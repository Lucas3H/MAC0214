#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = (int)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 2010
#define MOD 1000000007
#define INF 2000000000000000100

int n, m;

int vert[2][MAXN][MAXN], hori[2][MAXN][MAXN];
char a[MAXN][MAXN];

void build(){
	frr(i, n) frr(j, m){
		if(a[i][j] == a[i - 1][j]) vert[0][i][j] = vert[0][i - 1][j] + 1;
		else vert[0][i][j] = 1;
	}
	for(int i = n; i >= 1; i--) frr(j, m){
		if(a[i][j] == a[i + 1][j]) vert[1][i][j] = vert[1][i + 1][j] + 1;
		else vert[1][i][j] = 1;

		vert[0][i][j] = min(vert[1][i][j], vert[0][i][j]);
	}
}

void solve(int row){
	for(int i = 1; i <= m; i++){
		if(a[row][i] != a[row][i - 1]) hori[0][row][i] = 1;
		else hori[0][row][i] = min(vert[0][row][i], hori[0][row][i - 1] + 1);
	} 
	for(int i = m; i >= 1; i--){
		if(a[row][i] != a[row][i + 1]) hori[1][row][i] = 1;
		else hori[1][row][i] = min(vert[0][row][i], hori[1][row][i + 1] + 1);

		hori[0][row][i] = min(hori[1][row][i], hori[0][row][i]);
	} 
}

signed main(){
	fastio;
	cin >> n >> m;
	frr(i, n) frr(j, m) cin >> a[i][j];
	build();
	frr(i, n) solve(i);

	ll ans = 0;
	frr(i, n) frr(j, m){
		ans += min(vert[0][i][j], hori[0][i][j]);
	}
	cout << ans << endl;
}
