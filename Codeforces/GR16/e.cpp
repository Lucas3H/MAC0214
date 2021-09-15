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

#define MAXN 200010
#define MOD 1000000007
#define INF 1000000000000000100

vector<int> adj[MAXN];
int is_bud[MAXN];

void dfs(int v, int p){
	if(adj[v].size() == 1 && v != 1) 
		is_bud[v] = 0;

	for(int x: adj[v]){
		if(x == p) continue;
		dfs(x, v);
		if(!is_bud[x]) is_bud[v] = 1;
	}	
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		frr(i, n) adj[i].clear(), is_bud[i] = 0;
		is_bud[1] = 0;

		fr(i, n-1){
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		dfs(1, 0);
		is_bud[1] = 0;

		int leafs = -1, buds = 0, l_solta = 0;
		frr(i, n){
			if(is_bud[i]) buds++;
			else leafs++;
		}
		for(auto x: adj[1]) if(is_bud[x] == 0) l_solta=1;

		// dbg(l_solta);
		// dbg(buds);
		// dbg(leafs);

		cout << leafs - (buds - 1) - l_solta << endl;
	}
}