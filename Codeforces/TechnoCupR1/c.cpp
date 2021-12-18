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

#define MAXN 1000010
#define MOD 1000000007
#define INF 2000000000000000100

vector<string> v;
int n, m;
int ruim[MAXN];
int dp[MAXN];


signed main(){
	fastio;
	cin >> n >> m;
	fr(i, n){
		string s;
		cin >> s;
		v.pb(s);
	}
	fr(i, m - 1){
		fr(j, n - 1){
			if(v[j + 1][i] == 'X' && v[j][i + 1] == 'X') ruim[i] = 1;
		}
	}

	dp[0] = -1;
	frr(i, m - 1){
		if(ruim[i - 1]) dp[i] = i - 1;
		else dp[i] = dp[i - 1];
	}
	int q;
	cin >> q;

	while(q--){
		int l, r;
		cin >> l >> r;
		l--, r--;


		if(l <= dp[r]){
			cout << "NO" << '\n';
		}
		else cout << "YES" << '\n';
	}
}
