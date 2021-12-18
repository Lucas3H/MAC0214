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
#define INF 2000000000000000100

int m[MAXN][5];
int n;

bool solve(int a, int b){
	int na = 0, nb = 0;
	fr(i, n){
		if(m[i][a]) na++;
		if(m[i][b]) nb++;
		if(m[i][a] == 0 && m[i][b] == 0) return false;	
	}
	if(na >= n/2 && nb >= n/2) return true;
	else return false;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		cin >> n;
		fr(i, n) fr(j, 5) cin >> m[i][j];
		int ok = 0;
		fr(i, 5){
			fr(j, i){
				if(solve(i, j)) ok = 1;
			}
		}
		cout <<(ok ? "YES" : "NO") << endl;
	}
}
