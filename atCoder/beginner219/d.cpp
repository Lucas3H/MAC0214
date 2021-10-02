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

#define MAXN 610
#define MOD 1000000007
#define INF 1000000000000000100

int dp[MAXN][MAXN];

void update(int a, int b){
	frm(i, MAXN) frm(j, MAXN){
		if(i - a >= 0 && j - b >= 0){
			dp[i][j] = min(dp[i-a][j-b] + 1, dp[i][j]);
		}
	}
	frm(i, MAXN-1) frm(j, MAXN-1){
		dp[i][j] = min(dp[i][j], dp[i+1][j]);
		dp[i][j] = min(dp[i][j], dp[i][j+1]);
	}
}

signed main(){
	fastio;
	fr(i, MAXN) fr(j, MAXN) dp[i][j] = MOD;
	dp[0][0] = 0;
	int n, x, y;
	cin >> n >> x >> y;
	fr(i, n){
		int a, b;
		cin >> a >> b;
		update(a, b);
	}
	if(dp[x][y] > 300) cout << -1  << endl;
	else cout << dp[x][y] << endl;
}
