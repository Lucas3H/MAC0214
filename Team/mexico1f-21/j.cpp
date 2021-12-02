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

vector<ll> adj[MAXN];
ll dist[MAXN];
ll n;

void dfs1(ll v){
	if(adj[v].size() == 0) {
		dist[v] = 1;
		return;
	}
	dist[v] = MOD;
	for(auto x: adj[v]){
		dfs1(x);
		dist[v] = min(dist[v], dist[x] + 1);
	}
}

void dfs2(ll v, ll d){
	dist[v] = min(dist[v], d);
	for(auto x: adj[v])
		dfs2(x, dist[v] + 1);
}

ll fastxp(ll n, ll e){
    ll ans = 1, pwr = n;
    while(e){
        if(e%2)  ans = ans * pwr % MOD;
        e /= 2;
        pwr = pwr * pwr % MOD;
    }
    return ans % MOD;
}

signed main(){
	fastio;
	cin >> n;
	frr(i, n - 1){
		ll a;
		cin >> a;
		adj[a].pb(i + 1);
	}
	dfs1(1);
	dfs2(1, MOD);

	ll sum = 0;
	frr(i, n){
		sum = (sum + dist[i]) % MOD;
	}
	cout << sum * fastxp(n, MOD - 2) % MOD << endl;
}
