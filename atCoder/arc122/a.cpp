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
#define MOD 1000000007
#define INF 2000000000000000100

ll a[MAXN];
ll dp[MAXN][2];
ll n;

signed main(){
	fastio;
	cin >> n;
	frr(i, n) cin >> a[i];
	if(n == 1){
		cout << a[1] << endl;
		return 0;
	}

	dp[0][0] = dp[0][1] = 1;
	dp[1][0] = dp[1][1] = 1;
	for(ll i = 2; i <= n; i++){
		dp[i][0] = (dp[i-1][0] + dp[i - 1][1]) % MOD;
		dp[i][1] = dp[i-1][0] % MOD;
	}
	//cout << dp[n - 1][0] + dp[n - 1][1] << endl;

	ll ans = a[1] * (dp[n - 1][0] + dp[n - 1][1]) % MOD;
	for(ll i = 2; i <= n; i++){
		ll tira = dp[i - 2][0] * dp[n - i][0] % MOD;
		//dbg(dp[n - 1][0] + dp[n - 1][1] - 2 * tira);	
		ans = (ans + (dp[n - 1][0] + dp[n - 1][1] - 2 * tira + 2 * MOD) * a[i]) % MOD;
	}
	cout << ans << endl;
}
