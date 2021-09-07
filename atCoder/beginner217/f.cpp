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

#define MAXN 410
#define MOD 998244353
#define INF 1000000000000000100

ll dp[MAXN][MAXN], bin[MAXN][MAXN];
vector<ll> adj[MAXN];
ll n, m;

ll solve(ll l, ll r){
	ll & memo = dp[l][r];
	if(memo > -1) return memo;
	if(l >= r || (r - l) % 2 == 0) return memo = 0;
	if(l == r - 1){
		for(auto x: adj[r]){
			if(x == l) return memo = 1;
		}
		return memo = 0;
	}

	ll pares = (r - l + 1)/2;

	memo = 0;
	for(auto x: adj[r]){
		if(x == r - 1) memo = (memo + solve(l, x - 1) * bin[pares][1]) % MOD;
		else if(x == l) memo = (memo + solve(l + 1, r - 1)) % MOD;
		else if(x > l && (x - l)%2 == 0) {
			ll part = solve(x + 1, r - 1) * solve(l, x - 1) % MOD;
			part = part * bin[pares][(x - l)/2] % MOD;
			memo = (memo + part) % MOD;
		}
	}
	return memo;
}

signed main(){
	fastio;

	bin[0][0] = 1;
	frr(i, MAXN - 1){
		bin[i][0] = 1;
		frr(j, i){
			bin[i][j] = (bin[i-1][j] + bin[i-1][j-1]) % MOD;
		}
	}

	mem(dp, -1);
	cin >> n >> m;
	fr(i, m){
		ll u, v;
		cin >> u >> v;
		if(u > v) adj[u].pb(v);
		else adj[v].pb(u);
	}

	cout << solve(1, 2*n) << endl;
}
