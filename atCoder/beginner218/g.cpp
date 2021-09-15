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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 

ordered_set leaf;
int ans[MAXN], a[MAXN];
vector<int> adj[MAXN];
int n;
int median(){
	int tam = (int)(leaf.size());
	if(tam % 2 == 0){
		return ( (*(leaf.find_by_order(tam/2 - 1))).f + (*(leaf.find_by_order(tam/2))).f )/2;
	}
	else{
		return (*(leaf.find_by_order((tam + 1)/2 - 1))).f;  
	}
}

int dfs(int v, int pai, int h){
	if(v != 1 && adj[v].size() == 1){
		leaf.insert({a[v], v});
		ans[v] = median();
		// cout << v << endl;
		// for(auto x: leaf) cout << x.f << ' ';
		// cout << endl;
		leaf.erase({a[v], v});
		return ans[v];
	}

	leaf.insert({a[v], v});

	int best_median = - 1;
	if(h%2 == 0) best_median = MOD;
	for(int x : adj[v]){
		if(x != pai) {
			if(h%2 == 0) best_median = min(best_median, dfs(x, v, h + 1));
			else best_median = max(best_median, dfs(x, v, h + 1));
		}
	}

	leaf.erase(leaf.find({a[v], v}));
	return best_median;
}



signed main(){
	fastio;
	cin >> n;
	frr(i, n )cin >> a[i];
	fr(i, n-1){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cout << dfs(1, 0, 1) << endl;
}
