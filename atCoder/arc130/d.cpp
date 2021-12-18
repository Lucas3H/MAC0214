#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = (ll)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_ll_distribution<ll>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 3010
#define MOD 998244353
#define INF 2000000000000000100

ll fastxp(ll n, ll e){
    ll ans = 1, pwr = n;
    while(e){
        if(e%2)  ans = ans * pwr % MOD;
        e /= 2;
        pwr = pwr * pwr % MOD;
    }
    return ans % MOD;
}

vector<ll> dp[MAXN];
vector<ll> adj[MAXN];
ll n;

ll fat[MAXN], inv_fat[MAXN];
ll sz[MAXN];

void dfs(ll v, ll p){
	sz[v] = 1;
	for(auto x : adj[v]) if(x != p) {
		dfs(x, v);
		sz[v] += sz[x];
	}

	vector<ll> aux;
	dp[v].resize(sz[v] + 1);
	aux.resize(sz[v] + 1);

	dp[v][0] = 1;
	ll tot = 1;
	for(auto x : adj[v]) if(x != p){
		ll sum = 0;
		fr(j, sz[x] + 1) {
			sum = (sum + dp[x][j]) % MOD;
			ll inverso = inv_fat[j] * inv_fat[sz[x] - j] % MOD;
			fr(i, tot) {
				aux[i + j] = (aux[i + j] + dp[v][i] * sum % MOD * inverso) % MOD;
			}
		}
		dp[v] = aux;
		tot += sz[x];
		fr(i, tot) aux[i] = 0;
	}

	for(int i = sz[v]; i >= 1; i--){
		dp[v][i] = dp[v][i - 1] * fat[i - 1] % MOD * fat[sz[v] - i] % MOD;
	}
	dp[v][0] = 0;

	//frr(i, sz[v]) cout << v << " " << i << " : " << dp[v][i] << endl;

	frr(i, sz[v] / 2) swap(dp[v][i], dp[v][sz[v] - i + 1]);
}

signed main(){
	fastio;
	fat[0] = 1, inv_fat[0] = 1;
	frr(i, MAXN - 1){
		fat[i] = fat[i - 1] * i % MOD;
		inv_fat[i] = fastxp(fat[i], MOD - 2);
	}

	cin >> n;
	fr(i, n - 1){
		ll a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(1, -1);
	ll ans = 0;
	frr(i, n) {
		//cout << dp[1][i] << endl;
		ans = (ans + 2 * dp[1][i]) % MOD;
	}
	cout << ans << endl;
}
