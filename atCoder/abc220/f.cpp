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
#define MOD 1000000007
#define INF 2000000000000000100

ll dp[MAXN], sz[MAXN];
vector<ll> adj[MAXN];
ll n;

void dfs1(ll v, ll p){
	sz[v] = 1;
	for(auto x: adj[v]){
		if(x != p){
			dfs1(x, v);
			sz[v] += sz[x];
			dp[v] += dp[x] + sz[x];
		}
	}
}

void dfs2(ll v, ll p){
	for(auto x: adj[v]){
		if(x != p){
			dp[x] += (dp[v] - dp[x] - sz[x] + n - sz[x]);
			dfs2(x, v);
		}
	}
}

signed main(){
	fastio;
	cin >> n;
	fr(i, n-1){
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(1, 1);
	dfs2(1, 1);
	frr(i, n) cout<< dp[i] << endl;
}
