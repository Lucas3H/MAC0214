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

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		int a, b;
		cin >> a >> b;
		vector<int> ans;
		for(int i = 0; i <= a + b; i++){
			if((a + b)%2 == 0){
				int x0 = ((a - b)/2 + i) / 2, y0 = (i - (a - b)/2) / 2;
				int b0 = (a + b) / 2 - x0, a0 = (a + b) / 2 - y0;
				if(x0 >= 0 && y0 >= 0 && a0 >= 0 && b0 >= 0 && a0 + x0 == a && b0 + y0 == b && x0 + y0 == i)
					ans.pb(i);
			}
			else{
				int x0 = ((a - b + 1)/2 + i) / 2, y0 = (i - (a - b + 1)/2) / 2;
				int b0 = (a + b + 1) / 2 - x0, a0 = (a + b - 1) / 2 - y0;
				if(x0 >= 0 && y0 >= 0 && a0 >= 0 && b0 >= 0 && a0 + x0 == a && b0 + y0 == b && x0 + y0 == i){
					ans.pb(i);
					continue;
				}
				x0 = ((a - b - 1)/2 + i) / 2, y0 = (i - (a - b - 1)/2) / 2;
				b0 = (a + b - 1) / 2 - x0, a0 = (a + b + 1) / 2 - y0;
				if(x0 >= 0 && y0 >= 0 && a0 >= 0 && b0 >= 0 && a0 + x0 == a && b0 + y0 == b && x0 + y0 == i)
					ans.pb(i);
			}
		}
		cout << ans.size() << endl;
		for(auto x : ans) cout<< x<< " ";
		cout << endl;
	}
}
