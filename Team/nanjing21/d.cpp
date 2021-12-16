#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = (int)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << '\n';
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100
vector<int> tree;
int dg[MAXN], fi[MAXN];
int root;

int pai[MAXN], sz[MAXN];
pii par(int a, int b){
	return {min(a, b), max(a, b)};
}


int find(int x){
	if(pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}


vector<pii> adj[MAXN];
bool join(int a, int b, int ind){
	int A = a, B = b;
	a = find(a), b = find(b);
	if(a == b) return false;
	if(dg[a] > dg[b]) swap(a, b);
	for(auto x : adj[b]) if(x.f == root) tree[x.s] = 0;
	dg[b]--, dg[root]--;
	pai[b] = a;
	sz[a] += sz[b];

	dg[A]++, dg[B]++;
	tree[ind] = 1;

	return true;
}

int n, m;
vector<pii> e;
int pr[MAXN];

void dfs(int v){
	pr[v] = 1;
	for(auto x : adj[v]){
		if(!pr[x.f]){
			tree[x.s] = 1;
			dg[x.f]++, dg[v]++;
			dfs(x.f);
		}
	}
}
void dfsTree(int v, int p, int filho){
	pai[v] = filho;
	sz[filho]++;
	//cout << v << " " << p << endl;
	for(auto x : adj[v]){
		if(x.f != p && tree[x.s]) {
			dfsTree(x.f, v, filho);
		}
	}
}

void solve(int ts){
	e.clear();
	cin >> n >> m;

	tree.assign(m, 0);
	frr(i, n){
		adj[i].clear();
		pai[i] = fi[i] = i;
		sz[i] = 1, dg[i] = pr[i] = 0;
	}
	fr(i, m){
		int a, b;
		cin >> a >> b;
		e.pb({a, b});
		adj[a].pb({b, i}), adj[b].pb({a, i});
	}


	root = -1;
	dfs(1);
	frr(i, n) if(dg[i] > n / 2) root = i;

	if(root == -1){
		cout << "Yes" << '\n';
		fr(i, m) if(tree[i]) cout << e[i].f << ' ' << e[i].s << '\n';
		return;
	} 

	for(auto x : adj[root]){
		if(tree[x.s]) dfsTree(x.f, root, x.f);
	}

	fr(i, m){
		pii x = e[i];
		if(x.f == root || x.s == root) continue;
		join(x.f, x.s, i);
		if(dg[root] <= n / 2) break;
	}
	int ok = 1;
	frr(i, n) if(dg[i] > n / 2) ok = 0;
	if(!ok) cout << "No" << '\n';
	else{
		cout << "Yes" << '\n';
		fr(i, m) if(tree[i]) cout << e[i].f << ' ' << e[i].s << '\n';
	}
}


signed main(){
	fastio;
	int t;
	cin >> t;

	frr(i, t) solve(i);
}
