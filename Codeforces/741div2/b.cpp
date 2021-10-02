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

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		int k;
		cin >> k;
		vector<int> f[10];
		string s;
		cin >> s;
		fr(i, k) f[(int)(s[i] - '0')].pb(i);
		bool ok = 0;
		fr(i, 10){
			if(f[i].size() > 0 && i != 2 && i != 3 && i != 5 && i != 7){
				cout << 1 << endl;
				cout << i << endl;
				ok = 1;
				break;
			}
		}

		if(ok) continue;
		fr(i, 10){
			if(f[i].size() > 1){
				cout << 2 << endl;
				cout << i << i << endl;
				ok = 1;
				break;
			}	
		}

		if(ok) continue;

		if(f[2].size() && f[5].size() && f[2][0] < f[5][0]) {
			cout << 2 << endl;
			cout << 25 << endl;
		}
		else if(f[2].size() && f[7].size() &&  f[2][0] < f[7][0]) {
			cout << 2 << endl;
			cout << 27 << endl;
		}
		else if(f[3].size() && f[2].size() &&  f[3][0] < f[2][0]) {
			cout << 2 << endl;
			cout << 32 << endl;
		}
		else if(f[3].size() && f[5].size() &&  f[3][0] < f[5][0]) {
			cout << 2 << endl;
			cout << 35 << endl;
		}
		else if(f[5].size() && f[2].size() &&  f[5][0] < f[2][0]) {
			cout << 2 << endl;
			cout << 52 << endl;
		}
		else if(f[5].size() && f[7].size() &&  f[5][0] < f[7][0]) {
			cout << 2 << endl;
			cout << 57 << endl;
		}
		else if(f[7].size() && f[2].size() &&  f[7][0] < f[2][0]) {
			cout << 2 << endl;
			cout << 72 << endl;
		}
		else if(f[7].size() && f[5].size() &&  f[7][0] < f[5][0]) {
			cout << 2 << endl;
			cout << 75 << endl;
		}
		else assert(0);
	}
}
