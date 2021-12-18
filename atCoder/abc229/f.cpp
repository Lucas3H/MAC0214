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

#define MAXN 200010
#define MOD 1000000007
#define INF 2000000000000000100

ll dp[MAXN][2][2]; // {vtx, cor_1, cor_i} , cor_0 = 0
ll a[MAXN], b[MAXN];
ll n;

signed main(){
	fastio;
	ll s = 0;
	cin >> n;
	frr(i, n) cin >> a[i], s += a[i];
	frr(i, n) cin >> b[i], s += b[i];

	dp[1][1][1] = a[1];
	dp[1][0][0] = 0;
	dp[1][0][1] = dp[1][1][0] = -INF;

	for(int i = 2; i <= n; i++){
		fr(j, 2) {
			dp[i][j][1] = max(dp[i - 1][j][0] + b[i - 1] + a[i], dp[i - 1][j][1] + a[i]);
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + b[i - 1]);
		}
	}
	dp[n][0][1] += b[n];
	dp[n][1][0] += b[n];
	ll ans = 0;
	fr(i, 2) fr(j, 2) ans = max(ans, dp[n][i][j]);
	cout << s - ans << endl;
}
