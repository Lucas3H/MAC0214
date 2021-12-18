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

#define MAXN 1000010
#define MOD 1000000007
#define INF 2000000000000000100

int n, m;
vector<vector<char>> a;

bool valid(int m1, int m2){
	int m[2][3];
	fr(i, 2) fr(j, 3) m[i][j] = 0;
	fr(j, 3) {
		m[0][j] = m1%2;
		m1 /= 2;
	}
	fr(j, 3) {
		m[1][j] = m2%2;
		m2 /= 2;
	}

	if((m[0][0] + m[0][1] + m[1][0] + m[1][1])%2 == 0) return false;
	if((m[0][2] + m[0][1] + m[1][2] + m[1][1])%2 == 0) return false;
	return true;
}

int dist(int m1, int m2){
	int m[2][3];
	int ret =0 ;
	fr(j, 3) {
		if((m1 - m2)%2) ret++;
		m1 /= 2, m2 /= 2;
	}
	return ret;
}

int v[2][2];
int dp[MAXN][10];

int get(int x, int y, int z){
	return x + 2 * y + 4 * z;
}

signed main(){
	fastio;
	cin >> n >> m;
	a.resize(n);
	fr(i, n){
		a[i].resize(m);
		fr(j, m) cin >> a[i][j];
	}

	if(n >= 4){
		cout << -1 << endl;
		return 0;
	}
	if(n == 1) {
		cout << 0 << endl;
		return 0;
	}
	if(n == 2){
		fr(i, m){
			int sum = 0;
			fr(j, n) sum += a[j][i];
			v[i%2][sum%2]++;
		}

		cout << min(v[0][0] + v[1][1], v[0][1] + v[1][0]) << endl;
		return 0;
	}
	fr(i, 8) 
		dp[0][i] = dist(i, get(a[0][0] - '0', a[1][0] - '0', a[2][0] - '0'));

	frr(i, m - 1){
		int cur = get(a[0][i] - '0', a[1][i] - '0', a[2][i] - '0');
		fr(j, 8){
			dp[i][j] = MOD;
			fr(k, 8) if(valid(j, k)) {
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + dist(j, cur));
			}
		}
		// dbg(cur);
		// fr(j, 8) cout << dp[i][j] << " ";
		// cout << endl;
	}

	int ans = MOD;
	fr(i, 8) ans = min(ans, dp[m - 1][i]);
	cout << ans << endl;
} 
