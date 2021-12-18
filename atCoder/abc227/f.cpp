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

#define MAX 63
#define MOD 1000000007
#define INF 2000000000000000100

ll dp[MAX][MAX][MAX];
ll h, w, k;
ll a[MAX][MAX];

ll solve(ll val){
	fr(r, h) fr(c, w) fr(n, k + 1) dp[r][c][n] = INF;

	if(a[0][0] >= val) dp[0][0][1] = a[0][0];
	if(a[0][0] <= val) dp[0][0][0] = 0;

	fr(i, k + 1) fr(r, h) fr(c, w) {
		if(a[r + 1][c] >= val)
			dp[r + 1][c][i + 1] = min(dp[r + 1][c][i + 1], dp[r][c][i] + a[r + 1][c]);
		if(a[r + 1][c] <= val)
			dp[r + 1][c][i] = min(dp[r + 1][c][i], dp[r][c][i]);
			
		if(a[r][c + 1] >= val)
			dp[r][c + 1][i + 1] = min(dp[r][c + 1][i + 1], dp[r][c][i] + a[r][c + 1]);	
		if(a[r][c + 1] <= val)
			dp[r][c + 1][i] = min(dp[r][c + 1][i], dp[r][c][i]);	
	}

	// dbg(val);
	// fr(r, h) fr(c, w) fr(i, k + 1){
	// 	cout << r << " " << c << " " << i << " " << dp[r][c][i] << endl;
	// }

	return dp[h - 1][w - 1][k];
}

signed main(){
	fastio;
	cin >> h >> w >> k;
	fr(r, h) fr(c, w) cin >> a[r][c];

	ll ans = INF;
	fr(r, h) fr(c, w) ans = min(ans, solve(a[r][c]));
	cout << ans << endl;
} 
