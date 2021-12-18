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

int n, k;
int xr[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p){
	for(auto x: adj[v]){
		if(x != p){
			dfs(x, v);
			xr[v] ^= xr[x];
		}
	}
}

bool achou = 0;

bool check(int v, int p){
	int sum = 0;
	for(auto x: adj[v]){
		if(x != p){
			if(check(x, v)) sum++;
		}
	}
	if(sum && xr[v] == 0) achou = 1;
	if(sum >= 2) achou = 1;
	sum += (xr[v] == xr[1]);
	return sum > 0;
}

void solve(){
	cin >> n >> k;
	frr(i, n) adj[i].clear();
	frr(i, n) cin >> xr[i];
	fr(i, n-1){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	achou = 0;
	dfs(1, 0);
	if(xr[1] == 0) cout << "YES" << endl;
	else{
		if(k == 2) cout << "NO" << endl;
		else{
			bool ok = check(1, 0);
			if(achou) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}

signed main(){
	fastio;
	int t;
	cin >> t;
	while(t--) solve();

}
