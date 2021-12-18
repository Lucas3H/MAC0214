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

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100

int r, c;
char m[800][800];

signed main(){
	fastio;
	cin >> r >> c;
	frr(i, r) frr(j, c) cin >> m[i][j];
	frr(i, r) frr(j, c){
		if(m[i][j] != '.') continue;
		set<int> s;
		for(char k = '1'; k <= '5'; k++){
			if(m[i - 1][j] == k) s.insert(k - '0');
			if(m[i + 1][j] == k) s.insert(k - '0');
			if(m[i][j - 1] == k) s.insert(k - '0');
			if(m[i][j + 1] == k) s.insert(k - '0');
		}
		frr(k, 5) if(s.count(k) == 0) {
			m[i][j] = k + '0';
			break;
		}
	}
	frr(i, r) {
		frr(j, c) cout << m[i][j];
		cout << endl;
	}
}
