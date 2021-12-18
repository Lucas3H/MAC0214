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

#define MAXN 300010
#define MOD 1000000007
#define INF 2000000000000000100

int dir[MAXN];
array<int, 3> e[MAXN];
int n, m;


int deg[MAXN], pr[MAXN];
vector<pii> adj[MAXN];
int cur_dir = 0;
int cur_sum[MAXN], sum[MAXN];
int cur[MAXN]

void dfs(int v){
	pr[v] = 1;
	for(auto x: adj[v]){
		if(!pr[x.f]){
			if(cur_dir){
				cur[x.f] -= e[x.s][2];
				cur[v] += e[x.s][2];
				dfs(x.f);
				cur[v] -= e[x.s][2];
			} 
			else{
				cur[x.f] += e[x.s][2];
				cur[v] -= e[x.s][2];
				dfs(x.f);
				cur[v] += e[x.s][2];
			}

			if(cur_dir == 0){
				if(e[x.s][0] == v) ans[x.s] = 0;
				else ans[x.f] = 1;
				
				sum[v] += e[x.s][2];
			}
			else{
				if(e[x.s][0] == v) ans[x.s] = 1;
				else ans[x.f] = 0;
				sum[v] -= e[x.s][2];		
			}

		}
		else{
			int cur_sum = sum[x.f];
			if(cur_dir) cur_sum += cur[x.f];
			else cur_sum -= cur[x.f];

			if(cur_sum > 0){
				if(cur_dir == 0){
					
				}
			}
		}
	}
}


signed main(){
	fastio;
	cin >> n >> m;
	fr(i, m){
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].pb({b, i});
		adj[b].pb({a, i});
		e[i] = {a, b, w};
		deg[b] += w, deg[a] += w;
	}
	
	// Somente considero os caras de grau impar
	frr(i, n){
		vector<int> aux;
		if(deg[i]%2 == 0) continue;
		for(auto x: adj[i]) if(deg[x.f]%2) aux.pb(x);
		adj[i] = aux;		
	}


}
