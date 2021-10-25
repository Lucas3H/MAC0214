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

int n, m;
int p[11][1001];
int used[1001];
int ans[1001];

void backtracking(int mask){
	if(mask == 0) return;
	fr(i, m){
		if((1 << i) & mask){
			int j = 0;
			while(used[p[i][j]] == 1) j++;
			used[p[i][j]] = 1;
			ans[p[i][j]] = 1;
			backtracking(mask ^ (1 << i));
			used[p[i][j]] = 0;
		}
	}
}


signed main(){
	fastio;
	cin >> n >> m;
	fr(i, m) fr(j, n) cin >> p[i][j];
	backtracking((1 << m) - 1);
	vector<int> ok;
	fr(i, 1001) if(ans[i]) ok.pb(i);
	cout << ok.size() << endl;
	for(auto x: ok) cout << x << " ";
	cout << endl; 
}
