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

#define MAXN 1001
#define MOD 1000000007
#define INF 2000000000000000100

int dp[MAXN][MAXN];
int m[MAXN][MAXN];
vector<pii> pos[30];
int r, c;

int mx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int my[8] = {-1, 0, 1, 1, -1, -1, 0, 1};

bool inside(int x, int y){
	if(x >= 1 && x <= r && y >= 1 && y <= c) return true;
	else return false;
}

int ans = 1;
void update(int x, int y, int val){
	fr(i, 8){
		if(inside(x + mx[i], y + my[i]) && m[x + mx[i]][y + my[i]] == val + 1){
			dp[x + mx[i]][y + my[i]] = max(dp[x + mx[i]][y + my[i]], dp[x][y] + 1);
		}
	}
	ans = max(ans, dp[x][y] + 1);
}

signed main(){
	fastio;
	cin >> r >> c;
	frr(i, r){
		frr(j, c){
			char v;
			cin >> v;
			pos[v - 'A'].pb({i, j});
			m[i][j] = v - 'A';
		}
	}
	fr(i, 26) for(auto x: pos[i]) update(x.f, x.s, i);
	cout << ans << endl;

}
