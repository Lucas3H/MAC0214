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

int n;
int sz[MAXN];
vector<int> centroid;	
vector<int> adj[MAXN];
void dfs(int u, int p, int tam){
	sz[u] = 1;
	int ok = 1;
	for(auto x: adj[u]){
		if(x != p){
			dfs(x, u, tam);
			if(sz[x] > tam/2) ok = 0;
			sz[u]+=sz[x];
		}
	}
	if(ok && tam - sz[u] <= tam/2)
		centroid.pb(u);
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		cin >> n;
		frr(i, n) adj[i].clear();
		fr(i, n-1){
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		centroid.clear();
		dfs(1, -1, n);
		if(centroid.size() == 1){
			cout << 1  << " " << adj[1][0] << endl;
			cout << 1  << " " << adj[1][0] << endl;
			continue;
		}
		int a = centroid[0], b = centroid[1], c;
		for(auto x: adj[a]){
			if(x != b) c = x;
		}

		cout << a << " " << c << endl << b << " " << c << endl;
	}
}
