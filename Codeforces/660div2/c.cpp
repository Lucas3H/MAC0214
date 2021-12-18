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
int h[MAXN], p[MAXN], sz[MAXN];
int happy[MAXN], unhappy[MAXN];
vector<int> adj[MAXN];

bool ok = true;

void dfs(int v, int pai){	
	sz[v] = p[v];

	int sum_happy = 0;
	for(auto x: adj[v]){
		if(x != pai) {
			dfs(x, v);
			sz[v] += sz[x];
			sum_happy += happy[x];
		}
	}

	if((h[v] - sz[v])%2) ok = false;
	if(h[v] > sz[v] || h[v] < -sz[v]) ok = false;
	
	happy[v] = (h[v] + sz[v]) / 2, unhappy[v] = (h[v] - sz[v]) / 2;
	if(sum_happy > happy[v]) ok = false;
}

signed main(){
	fastio;
	int t;

	cin >> t;

	while(t--){
		cin >> n >> m;
		frr(i, n) adj[i].clear();
		frr(i, n) cin >> p[i];
		frr(i, n) cin >> h[i];
		fr(i, n - 1){
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		ok = true;
		dfs(1, 0);
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
