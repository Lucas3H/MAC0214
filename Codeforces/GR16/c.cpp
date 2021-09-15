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

string s[2];
int a[MAXN];
int n;

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		cin >> n >> s[0] >> s[1];
		fr(i, n){
			if(s[0][i] == '0' && s[1][i] == '0') a[i] = 0;
			if(s[0][i] == '0' && s[1][i] == '1') a[i] = 1;
			if(s[0][i] == '1' && s[1][i] == '0') a[i] = 1;
			if(s[0][i] == '1' && s[1][i] == '1') a[i] = 2;
		}
		int last = -1, ans = 0;
		fr(i, n){
			if(a[i] == 1){
				if(last == 0) 
					ans += 3;
				else ans += 2;
				last = -1;
			}
			else if(a[i] == 2){
				if(last == 0) {
					ans += 2;
					last = -1;
				}
				else last = 2;
			}
			else{
				if(last == 2) {
					ans += 2;
					last = -1;
				}
				else if(last == 0) {
					ans++;
					last = 0;
				}
				else last = 0;
			}
		}

		if(last == 0) ans++;
		cout<< ans << endl;	
	}
}