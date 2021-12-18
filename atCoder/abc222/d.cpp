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

#define MAXN 3010
#define MOD 998244353
#define INF 2000000000000000100

ll dp[MAXN][MAXN];
ll n;
ll a[MAXN], b[MAXN];

signed main(){
	fastio;

	cin >> n;
	dp[0][0] = 1;
	frr(i, n) cin >> a[i];
	frr(i, n) cin >> b[i];
	frr(i, n){
		ll sum = 0;
		for(ll j = 0; j < a[i]; j++) sum = (sum + dp[i - 1][j]) % MOD;
		for(ll j = a[i]; j <= b[i]; j++) dp[i][j] = (dp[i - 1][j] + sum) % MOD, sum = (sum + dp[i - 1][j]) % MOD;
	}
	ll ans = 0;
	fr(i, 3001) ans = (ans + dp[n][i]) % MOD;
	cout << ans << endl;
}