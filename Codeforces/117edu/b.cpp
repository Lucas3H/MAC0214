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
		int n, a, b;
		cin >> n >> a >> b;
		if(a > n / 2 + 1 || b < n / 2) {
			cout << -1 << endl;
			continue;
		}
		if(a == n/2 + 1){
			if(b != n/2){
				cout << -1 << endl;
				continue;
			}

			frr(i, n / 2) cout << i + n/2 << ' ';
			frr(i, n / 2) cout << i << ' ';
			cout << endl;
			continue;
		}
		if(b == n/2){
			cout << -1 << endl;
			continue;
		}
		vector<int> left, right;
		for(int i = b + 1; i <= n; i++) left.pb(i);
		frr(i, a - 1) right.pb(i);
		left.pb(a), right.pb(b);
		int i = a + 1;
		while(left.size() < n / 2) left.pb(i++);
		while(right.size() < n / 2) right.pb(i++);
		for(auto x: left) cout << x << " ";
		for(auto x: right) cout << x << " ";		
		cout << endl;
	}
}
