#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 3010
#define MOD 1000000007
#define INF 1000000000000000100

int dp[MAXN][MAXN];
vector<int> pos[MAXN];
int a[MAXN];
int n;

void solve(){
	cin >> n;
	fr(i, n) fr(j, n) dp[i][j] = 0;
	frr(i, n) pos[i].clear();
	fr(i, n) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}
	
	fr(r, n){
		frm(l, r){
			dp[l][r] = dp[l+1][r];
			fr(k, pos[a[l]].size()){
				int x = pos[a[l]][k];
				if(l < x && x <= r){
					// dbg(a[l]);
					// dbg(a[x]);
					// cout << l << " " << r << " || " << l + 1 << " | " << x - 1 << " | " << dp[l+1][x-1] << endl;
					dp[l][r] = max(dp[l][r], 1 + dp[l+1][x-1] + dp[x][r]);
				}
			}
		}
	}
	// fr(r, n) {
	// 	fr(l, r) cout << l << ' ' << r << " " << dp[l][r] << endl;
	// }
	cout << n - 1 - dp[0][n-1] << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--) solve();
}
