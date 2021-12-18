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

vector<pii> adj[MAXN];
ll dp[MAXN];
ll d[MAXN];
ll n;

void dfs1(ll v, ll p){
	for(auto x: adj[v]){
		if(x.f != p){
			dfs1(x.f, v);
			dp[v] = max(dp[v], dp[x.f] + x.s);
			dp[v] = max(dp[v], d[x.f] + x.s);
		}
	}
}

void dfs2(ll v, ll p, ll val_pai){
	dp[v] = max(dp[v], val_pai);
	vector<pii> davez;
	for(auto x: adj[v]){
		if(x.f != p){
			ll aux = d[x.f] + x.s;
			aux = max(aux, dp[x.f] + x.s);
			davez.pb({aux, x.f});
		}
	}

	val_pai = max(val_pai, d[v]);
	davez.pb({val_pai, v});
	sort(all(davez));

	ll a1 = davez.back().f, a2 = -INF;
	ll v1 = davez.back().s, v2 = -1;
	if(davez.size() >= 2) a2 = davez[(ll)davez.size() - 2].f, v2 = davez[(ll)davez.size() - 2].s;
	davez.clear();

	for(auto x: adj[v]){
		if(x.f != p){
			ll aux;
			if(x.f == v1) aux = a2;
			else aux = a1;

			dfs2(x.f, v, aux + x.s);
		}
	}
}

signed main(){
	fastio;
	cin >> n;
	fr(i, n - 1){
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	frr(i, n) cin >> d[i];

	dfs1(1, -1);
	dfs2(1, -1, -INF);
	frr(i, n) cout << dp[i] << endl;
}
