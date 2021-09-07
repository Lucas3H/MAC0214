#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_ll_distribution<ll>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 40001
#define MOD 1000000007
#define INF 1000000000000000100

int dp[15][1 << 14];
int sz[MAXN], cost[MAXN], xor_all[MAXN], ans[MAXN], x[MAXN];

vector<int> adj[MAXN];

void dfs(int u){
	sz[u] = 1;
	for(int v : adj[u]) {
		xor_all[v] = xor_all[u]^x[v];
		dfs(v);
		sz[u] += sz[v];
	}
}

bool comp(int i, int j){
	return sz[i] < sz[j];
}	

int aux[1 << 14];

void solve(int v, int h, int heavy){
	if(heavy){
		fr(i, (1 << 14)) aux[i] = MOD;
		aux[0] = 0;
		
		fr(i, (1 << 14)){
			aux[i] = min(dp[h-1][(i ^ x[v])] + cost[v], aux[i]);
			aux[i] = min(aux[i], dp[h-1][i]);
		}

		h--;
		fr(i, (1 << 14)) dp[h][i] = aux[i];
	}
	else{
		fr(i, (1 << 14)) dp[h][i] = MOD;
		dp[h][0] = 0;
		
		fr(i, (1 << 14)){
			dp[h][i] = min(dp[h-1][(i ^ x[v])] + cost[v], dp[h][i]);
			dp[h][i] = min(dp[h][i], dp[h-1][i]);
		}
	}

	ans[v] = dp[h][xor_all[v]];

	fr(i, (int)adj[v].size()-1) solve(adj[v][i], h + 1, 0);
	//dbg(adj[v].size());
		
	if(adj[v].size() > 0){
	//	dbg(adj[v].size());
		solve(adj[v].back(), h + 1, 1);
	}
}

int n;
signed main(){
	fastio;
	fr(i, 15) fr(j, (1 << 14)) dp[i][j] = MOD;

	cin >> n;
	stack<int> pilha;
	pilha.push(0);
	frr(i, n){
		string s;
		cin >> s;
		if(s == "ADD"){
			cin >> x[i] >> cost[i];
			adj[pilha.top()].pb(i);	
			pilha.push(i);
		}
		else {
			pilha.pop();
			ans[i] = -pilha.top();
		}
	}

	dfs(0);
	fr(i, n + 1) sort(all(adj[i]), comp);
	solve(0, 1, 0);
	frr(i, n) {
		if(ans[i] < 0) cout << ans[-ans[i]] << endl;
		else cout << ans[i] << endl;
	}
}
