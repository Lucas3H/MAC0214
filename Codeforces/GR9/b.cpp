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

#define MAXN 100010
#define MOD 1000000007
#define INF 1000000000000000100

int m[301][301];
int r, c;

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		cin >> r >> c;
		fr(i, r) fr(j, c) cin >> m[i][j];
		if(m[0][0] > 2 || m[r-1][0] > 2 || m[0][c-1] > 2 || m[r-1][c-1] > 2){
			cout << "NO" << endl;
			continue;
		}

		int deu = 1;
		fr(i, r){
			if(m[i][0] > 3 || m[i][c-1] > 3) deu = 0;
			m[i][0] = m[i][c-1] = 3;
		}
		fr(i, c){
			if(m[0][i] > 3 || m[r-1][i] > 3) deu = 0;
			m[0][i] = m[r-1][i] = 3;
		}

		
		m[0][0] = m[r-1][0] = m[0][c-1] = m[r-1][c-1] = 2;

		frr(i, r-2) frr(j, c-2) {
			if(m[i][j] > 4) deu = 0;
			m[i][j] = 4;
		}


		if(!deu){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		fr(i, r) {
			fr(j, c) cout << m[i][j] << ' ';
			cout << endl;
		}

	}
}
