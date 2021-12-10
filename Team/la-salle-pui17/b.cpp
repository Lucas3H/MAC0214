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

#define MAXN 500010
#define MOD 1000000007
#define INF 2000000000000000100

int n;
vector<int> adj[MAXN];
int dist[MAXN];

void dfs(int v, int p){
	for(auto x: adj[v]){
		if(x!=p){
			dist[x] = dist[v] + 1;
			dfs(x, v);
		}
	}
}

signed main(){
	fastio;
	cin >> n;
	fr(i, n - 1){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	int v = 1;
	frr(i, n){
		if(dist[v] < dist[i]) v = i;
	}
	dist[v] = 0;
	dfs(v, 0);
	int ans = 0;
	frr(i, n) ans = max(ans, dist[i]);

	int tot = 0;
	while(ans > 1){
		tot++;
		ans = (ans + 1)/2;
	}
	cout << tot << endl;
}
