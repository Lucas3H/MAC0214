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

string s;
int n;
char ans[51][51];

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		cin >> n >> s;
		vector<int> v;
		fr(i, n) if(s[i] == '2') v.pb(i);
		if(v.size() > 0 && v.size() < 3){	
			cout << "NO" << endl;
			continue;
		} 

		fr(i, n) fr(j, n) ans[i][j] = '=';
		fr(i, n) ans[i][i] = 'X';

		int o = v.size();
		fr(i, o){
			ans[v[i]][v[(i+1)%o]] = '+';
			ans[v[(i+1)%o]][v[i]] = '-';
		}
		cout << "YES" << endl;
		fr(i, n) {
			fr(j, n) cout << ans[i][j];
			cout << endl;
		}

	}
}
