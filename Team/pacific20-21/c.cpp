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

#define MAXN 102
#define MOD 1000000007
#define INF 2000000000000000100


int dp[MAXN][MAXN][MAXN];
char cor[MAXN * MAXN];
int ok[MAXN * MAXN];
vector<pii> adj[MAXN];

void dfs(int r, int b, int y){
	if(dp[r][b][y]) return;
	dp[r][b][y] = 1;
	for(auto x: adj[r]){
		if(cor[x.s] == 'R' || cor[x.s] == 'X') {
			ok[x.s] = 1;
			dfs(x.f, b, y);
		}
	}
	for(auto x: adj[b]){
		if(cor[x.s] == 'B' || cor[x.s] == 'X') {
			ok[x.s] = 1;
			dfs(r, x.f, y);
		}
	}
	for(auto x: adj[y]){
		if(cor[x.s] == 'Y' || cor[x.s] == 'X') {
			ok[x.s] = 1;
			dfs(r, b, x.f);
		}
	}

	if(r == b){
		for(auto x: adj[r]){
			if(cor[x.s] == 'P') {
				ok[x.s] = 1;
				dfs(x.f, x.f, y);
			}
		}
	}
	if(r == y){
		for(auto x: adj[r]){
			if(cor[x.s] == 'O') {
				ok[x.s] = 1;
				dfs(x.f, b, x.f);
			}
		}
	}

	if(b == y){
		for(auto x: adj[b]){
			if(cor[x.s] == 'G') {
				ok[x.s] = 1;
				dfs(r, x.f, x.f);
			}
		}
	}
}

int n, m, R, B, Y;

signed main(){
	fastio;
	cin >> n >> m >> R >> B >> Y;

	frr(i, m){
		int u, v;
		cin >> u >> v >> cor[i];
		adj[u].pb({v, i});
		adj[v].pb({u, i});
		if(cor[i] == 'X') ok[i] = 1;
	}
	dfs(R, B, Y);
	frr(i, m){
		if(ok[i] == 0){
			cout << 0 << endl;
			return 0;
		}
	}
	cout << 1 << endl;
}
