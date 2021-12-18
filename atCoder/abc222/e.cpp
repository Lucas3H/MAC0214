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

#define MAXN 100010
#define MOD 998244353
#define INF 2000000000000000100

map<pii, ll> fr;
vector<ll> adj[MAXN];
stack<ll> s;

void dfs(ll v, ll p, ll ini, ll fim){
	if(v == fim){
		ll davez = v;
		while(!s.empty()){
			pii p = {davez, s.top()};
			davez = s.top();
			if(p.f > p.s)swap(p.f, p.s);
			fr[p]++;
			s.pop();
		}
		return;
	}
	s.push(v);
	for(auto x: adj[v]){
		if(x != p) dfs(x, v, ini, fim);
	}
	if(s.size()) s.pop();
}

ll n, m, k;
ll a[MAXN];
vector<ll> v;
ll alvo = 0;


void build(){
	fr(i, m - 1) {
		dfs(a[i], -1, a[i], a[i + 1]);
		while(!s.empty()) s.pop();
		
	}
	ll sum = 0;
	for(auto x: fr){
		v.pb(x.s);
		sum += x.s;
	} 


	if((sum + k)%2 != 0 || (sum + k) < 0){
		cout << 0 << endl;
		exit (0);
	}

	alvo = (sum + k) / 2;
}

ll dp[MAXN];
void solve(){
	dp[0] = 1;
	for(auto x : v){
		frm(i, alvo + 1){
			if(i >= x)dp[i] = (dp[i] + dp[i - x]) % MOD;
		}
	}
	int tot = (int)v.size();
	fr(i, n - 1 - tot) dp[alvo] = dp[alvo] * 2 % MOD;
	cout << dp[alvo] << endl;
}

signed main(){
	fastio;
	cin >> n >> m >> k;
	fr(i, m) cin >> a[i];
	fr(i, n - 1){
		ll v, b;
		cin >> v >> b;
		adj[v].pb(b);
		adj[b].pb(v);
	}
	build();
	solve();
}
