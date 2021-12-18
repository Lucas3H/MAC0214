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

#define MAXN 110
#define MOD 1000000007
#define INF 2000000000000000100

char m[MAXN][MAXN];

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		int r, c;
		cin >> r >> c;
		fr(i, r) fr(j, c) m[i][j] = '0';
		for(int i = 0; i < c; i += 2) m[0][i] = '1';
		for(int i = 2; i < r; i += 2) m[i][c - 1] = '1';
		for(int i = c - 3; i >= 0; i -= 2) m[r - 1][i] = '1';
		for(int i = r - 3; i >= 2; i -= 2) m[i][0] = '1';
		fr(i, r){
			fr(j, c) cout << m[i][j];
			cout << endl;
		}
	}
}
