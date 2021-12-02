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

vector<ll> adj[20];
ll n, m;

bool is_connected[(1 << 15)];
ll num_edges[(1 << 15)];

ll pr[20];
ll num = 0;
void dfs(ll v, ll mask){
	num++;
	pr[v] = 1;
	for(auto x: adj[v]){
		if(((1 << x)&mask) == 0) continue;
		if(!pr[x])
			dfs(x, mask);
	}
}

void build(ll mask){
	fr(i, n) pr[i] = 0;
	num = 0;
	vector<ll> v;
	ll aux = mask, ind = 0;
	while(aux){
		if(aux%2) v.pb(ind);
		aux/=2;
		ind++;
	}

	dfs(v[0], mask);
	if(num == v.size()) is_connected[mask] = 1;
	ll t = 0;
	fr(i, v.size()){
		for(auto x: adj[v[i]]){
			if(((1 << x)&mask) != 0) t++;
		}
	}
	t /= 2;
	num_edges[mask] = 1;
	fr(i, t) num_edges[mask] = 2 * num_edges[mask] % MOD;
}

void build(){
	cin >> n >> m;
	fr(i, m){
		ll u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	num_edges[0] = 1;
	frr(i, (1 << n) - 1) build(i);
}

ll dp[(1 << 15)][20];
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
	build();

	dp[0][0] = 1;
	frr(m, (1 << n) - 1){
		for (ll s=m; s; s=(s-1)&m){
			if(!is_connected[s]) continue;
			//cout << m << " " << (m^s) << " " << val[s] << endl;
		
			for(int comp = 2 ; comp <= n; comp++) {
				dp[m][comp] = (dp[m][comp] + dp[m^s][comp - 1] * dp[s][1])%MOD;
			}
		}
		dp[m][1] = num_edges[m];
		for(int comp = 2 ; comp <= n; comp++){
			//cout << dp[m][comp] << " " << m << " " << comp << endl;
			
			dp[m][comp] = dp[m][comp] * fastxp(comp, MOD - 2) % MOD;
			//cout << dp[m][comp] << " " << m << " " << comp << endl;
			
			dp[m][1] = (dp[m][1] - dp[m][comp] + MOD) % MOD; 
		}
		//cout << dp[m][1] << " " << m << endl;
	}
	frr(i, n) cout << dp[(1 << n) - 1][i] << endl;
}
