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
#define MAXN 5010
#define MOD 1000000007
#define INF 2000000000000000100

ll n, k;

ll centroid;
ll sz[MAXN];
vector<ll> dp[MAXN];
vector<ll> adj[MAXN];

void cent(ll v, ll p){
	sz[v] = 1;
	ll ok = 1;
	for(auto x: adj[v]){
		if(x != p){
			cent(x, v);
			sz[v] += sz[x];
			if(sz[x] > n / 2) ok = 0;
		}
	}
	if(ok && n - sz[v] <= n / 2) centroid = v;
}

void merge(int v, int f){
	vector<ll> aux(dp[v].size() + dp[f].size() - 1);
	fr(i, dp[v].size()){
		fr(j, dp[f].size()){
			__int128 p = dp[v][i] * dp[f][j];
			p = min(p, (__int128)k);
			aux[i + j] = min(aux[i + j] + (ll)p, k);
		}
	}
	dp[v] = aux;
}

ll tot[MAXN];
void dfs(ll v, ll p){
	dp[v].resize(2);
	dp[v][1] = 1;
	for(auto x : adj[v]){
		if(x != p){
			dfs(x, v);
			merge(v, x);
		}
	}
	dp[v][0] = 1;
	// cout<< v << endl;
	// fr(i, dp[v].size()) cout << dp[v][i] << ' ';
	// cout << endl;
	fr(i, dp[v].size()) {
		tot[i] += dp[v][i];
		if(tot[i] >= k) tot[i] = k;
	}
}

signed main(){
	fastio;
	cin >> n >> k;
	fr(i, n - 1){
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cent(1, 0);
	dfs(centroid, 0);

	frr(i, n){
		//dbg(tot[i]);
		if(k <= tot[i]){
			cout << i << endl;
			return 0;
		}
		else k -= tot[i];
	}
	cout << -1 << endl;
}
