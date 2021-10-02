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

vector<int> pos[2][30];
string a, b;

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		fr(i, 26) fr(j, 2) pos[j][i].clear();
		cin >> a >> b;
		reverse(all(a));
		reverse(all(b));
		fr(i, a.size()) pos[i%2][a[i] - 'a'].pb(i);

		int dp[2] = {MOD, -1};
		fr(i, b.size()){
			int aux[2];
			auto it = lower_bound(all(pos[0][b[i] - 'a']), dp[1]);
			if(it == pos[0][b[i] - 'a'].end()) aux[0] = MOD;
			else aux[0] = (*it) + 1;
			
			auto it1 = lower_bound(all(pos[1][b[i] - 'a']), dp[0]);
			if(it1 == pos[1][b[i] - 'a'].end()) aux[1] = MOD;
			else aux[1] = (*it1) + 1;

			dp[0] = aux[0], dp[1] = aux[1];
			//cout << dp[0] << " " << dp[1] << endl;
		}

		if(dp[0] < MOD || dp[1] < MOD) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
