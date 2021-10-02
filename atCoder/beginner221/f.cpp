#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_ll_distribution<ll>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 200010
#define MOD 998244353
#define INF 2000000000000000100

vector<ll> adj[MAXN];
ll n;
vector<ll> bfs(ll ini){
	vector<ll> d(n);
	fr(i, n) d[i] = -1;

	queue<ll> fila;
	fila.push(ini);
	d[ini] = 0;
	while(fila.size()){
		ll davez = fila.front();
		fila.pop();
		for(auto x: adj[davez]) if(d[x] == -1){
			d[x] = d[davez] + 1;
			fila.push(x);
		}
	}
	return d;
}

pii dfs(ll v, ll p){
	ll maximo = 0, num = 1;
	for(auto x: adj[v]){
		if(x != p) {
			pii p = dfs(x, v);
			if(maximo < p.f + 1) {
				maximo = p.f + 1;
				num = p.s;
			} 
			else if(maximo == p.f + 1){
				num += p.s;
			}
		}
	}
	return {maximo, num};
}

ll l = 0, r = 0, m = -1;
ll sl = 0, sr = 0;

signed main(){
	fastio;
	cin >> n;
	fr(i, n-1){
		ll u, v;
		cin >> u >> v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}

	vector<ll> dl = bfs(0);
	fr(i, n) if(dl[i] > dl[l]) l = i;
	dl = bfs(l);
	fr(i, n) if(dl[i] > dl[r]) r = i;
	vector<ll> dr = bfs(r);
	fr(i, n) if(dl[i] == dr[i] && dl[i] + dr[i] == dl[r]) m = i;
	
	fr(i, n) if(dr[i] == dr[l]) sl++;
	fr(i, n) if(dl[i] == dl[r]) sr++;

	// dbg(sl);
	// dbg(sr);
	// dbg(m);

	ll ans = 0;
	if(m != -1){
		dl = bfs(m);
		ll part = 1;
		for(auto x : adj[m]){
			pii p = dfs(x, m);
			if(p.f + 1 == dl[l]) {
				part = part * (p.s + 1) % MOD;
				ans = (ans - p.s + MOD) % MOD;		
			}
		}
		ans = (ans - 1 + MOD) % MOD;
		ans = (ans + part) % MOD;
	}
	else ans = sl * sr % MOD;
	cout<< ans << endl;
}
