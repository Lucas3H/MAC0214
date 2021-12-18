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

#define MAXN 400010
#define MOD 1000000007
#define INF 2000000000000000100

ll pai[MAXN], sz[MAXN];

ll find(ll x){
	if(pai[x] == x)return x;
	else return pai[x] = find(pai[x]);
} 

ll join(ll a, ll b, ll w){
	a = find(a), b = find(b);
	if(a == b) return 0;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	pai[b] = a;
	return w;
}

ll mst(vector<array<ll, 3>> e){
	sort(all(e));
	for(auto x: e){
		pai[x[2]] = x[2], sz[x[2]] = 1;
		pai[x[1]] = x[1], sz[x[1]] = 1;
	}
	
	ll ans = 0;
	frm(i, e.size()){
		array<ll, 3> x = e[i];
		ans += join(x[1], x[2], x[0]);
	}

	return ans;
}

ll pr[MAXN];
vector<ll> vtx;
vector<pii> adj[MAXN];

void dfs(ll v){
	vtx.pb(v);
	pr[v] = 1;
	for(auto x: adj[v]){
		if(!pr[x.f]) dfs(x.f);
	}
}

vector<array<ll, 3>> get_edges(ll v){
	vtx.clear();
	dfs(v);
	vector<array<ll, 3>> e;
	for(auto x: vtx){
		for(auto p : adj[x]){
			if(p.f < x) e.pb({p.s, p.f, x});
		}
	}
	// for(auto x: vtx) cout << x << " ";
	// cout << endl;
	// for(auto x: e) cout << x[1] << "|" << x[2] << "|" <<x[0] << " ";
	// cout << endl;
	
	return e;
}



ll n, m;
ll a[MAXN], b[MAXN];
ll ans = 0;
void solve(){
	frr(i, n + m){
		if(!pr[i]){
			ans -= mst(get_edges(i));
		}
	}
	cout << ans << endl;
}

void build(){
	cin >> m >> n;
	frr(i, m) cin >> a[i];
	frr(i, n) cin >> b[i];

	frr(i, m){
		ll s;
		cin >> s;
		frr(j, s){
			ll v;
			cin >> v;
			adj[v + m].pb({i, a[i] + b[v]});
			adj[i].pb({v + m, a[i] + b[v]});
			ans += a[i] + b[v];
		}
	}
}

signed main(){
	fastio;
	build();
	solve();
}
