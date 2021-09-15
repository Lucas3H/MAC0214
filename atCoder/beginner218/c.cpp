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

#define MAXN 410
#define MOD 1000000007
#define INF 1000000000000000100

char s[MAXN][MAXN], t[MAXN][MAXN];
int n;

void translate(char m[][MAXN]){
	int row = n, col = n;
	fr(i, n){
		fr(j, n){
			if(m[i][j] == '#') 
				row = min(row, i), col = min(col, j);
		}
	}
	fr(i, n){
		fr(j, n){
			m[i][j] = m[i + row][j + col];
		}
	}
}


char aux[MAXN][MAXN];
void rotate(char m[][MAXN]){
	fr(i, n) fr(j, n) aux[j][n - 1 - i] = m[i][j];
	fr(i, n) fr(j, n) m[i][j] = aux[i][j];
}

bool match(){
	fr(i,n) fr(j, n) 
		if(s[i][j] == '#' && t[i][j] == '.' || t[i][j] == '#' && s[i][j] == '.')
			return false;
	return true;
}

signed main(){
	fastio;
	cin >> n;
	fr(i, MAXN) fr(j, MAXN) s[i][j] = t[i][j] = '.';
	fr(i, n) fr(j, n) cin >> s[i][j];
	fr(i, n) fr(j, n) cin >> t[i][j];
	translate(s);
	translate(t);
	fr(i, 5){
		// fr(i, n){
		// 	fr(j, n) cout << s[i][j];
		// 	cout << endl;
		// }
		// fr(i, n){
		// 	fr(j, n) cout << t[i][j];
		// 	cout << endl;
		// }
		if(match()){
			cout << "Yes" << endl;
			return 0;
		}

		rotate(t);
		translate(t);
	}
	cout << "No" << endl	;
}
