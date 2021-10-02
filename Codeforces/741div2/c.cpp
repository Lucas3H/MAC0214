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
		int n;
		string s;
		cin >> n >> s;
		vector<int> pos;
		fr(i, n) if(s[i] == '0') pos.pb(i);

		if(pos.size() && pos.back() >= (n + 1)/2){
			cout << 1 << " " << pos.back() + 1 << endl;
			cout << 1 << " " << pos.back() << endl;
			continue;
		}
		else if(pos.size() && pos[0] < n/2){
			cout << pos[0] + 1 << " " << n << endl;
			cout << pos[0] + 2 << " " << n << endl;
		}
		else if(pos.size() && pos[0] == n/2){
			cout << 1 << ' ' << n/2 + 1 << endl;
			cout << n/2 + 1 << ' ' << n << endl;
		}
		else{
			cout << 1 << " " << n/2 * 2 << endl;
			cout << 1 << ' ' << n/2 << endl;
		}
	}
}
