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

set<int> adj[MAXN];

int n;
int sz[MAXN];
vector<int> centroid;	
	
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

int get_tam(int v, int p){
	int s = 1;
	for(auto x: adj[v]){
		if(x != p) s += get_tam(x, v);
	}
	return s;
}






vector<int> davez;
void build_davez(int v, int p){
	davez.pb(v);
	for(auto x: adj[v]){
		if(x != p) build_davez(x, v);
	}
}

int tot_ask = 0;
int ask(){
	if(davez.size() == 1) {
		return -1;
	}
	tot_ask++;
	if(tot_ask > 12) assert (0);
	cout<< "? " << davez.size() << ' ';
	for(auto x: davez) cout << x << " ";
	cout << endl;
	int x;
	cin >> x;
	return x;
}

int ans;
void decompose(int root){
	centroid.clear();
	int tam = get_tam(root, -1);
	dfs(root, -1, tam);
		
	int c = centroid[0];
	if(adj[c].size() == 1){
		cout << "! " << c << " " << *(adj[c].begin()) << endl;
		exit (0);
	}
	int nxt = -1, sz = 1;
	deque<pii> viz;
	for(auto x: adj[c]){
		int aux = get_tam(x, c);
		viz.pb({aux, x});
	}

	sort(all(viz));
	int ind = 0;
	while(sz < (tam + 1)/2){
		sz += viz[ind].f;
		ind++;
	}
	if(ind == viz.size()){
		pii aux = viz.back();
		viz.pop_back();
		viz.push_front(aux);
		ind = 1;
	}

	for(int i = ind; i < viz.size(); i++){
		adj[c].erase(viz[i].s);
		adj[viz[i].s].erase(c);
	}
	davez.clear();
	build_davez(c, -1);
	int x = ask();

	if(x == ans){
		decompose(c);
	}
	else {
		adj[c].clear();
		for(int i = ind; i < viz.size(); i++){
			adj[c].insert(viz[i].s);
			adj[viz[i].s].insert(c);
		}
		decompose(c);
	}
}


signed main(){
    cin>> n;
    fr(i, n-1){
    	int u, v;
    	cin >> u >> v;
    	adj[u].insert(v);
    	adj[v].insert(u);
    }
    build_davez(1, -1);
    ans = ask();
    decompose(1);
}
