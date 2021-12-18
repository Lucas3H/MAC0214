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

struct LCA{
    int n, maxl, tempo;
    vector<int> tin, tout, h, parent;
    vector<vector<int>> adj, anc;

    void dfs(int v, int pai){
        parent[v] = pai;
        h[v] = h[pai] + 1, anc[v][0] = pai;
        for(int i = 1; i <= maxl; i++) anc[v][i] = anc[anc[v][i-1]][i-1];
        
        tin[v] = tempo++;
        for(int u: adj[v]) if(u != pai) dfs(u, v);
        tout[v] = tempo++;
    }

    bool is_ancestor(int v, int u){
        return (tin[v] <= tin[u] && tout[v] >= tout[u]);
    }

    int lca(int a, int b){
        if(is_ancestor(a, b)) return a;
        if(is_ancestor(b, a)) return b;

        for (int i = maxl; i >= 0; --i) 
            if (!is_ancestor(anc[a][i], b))
                a = anc[a][i];

        return anc[a][0];
    }

    int dist(int a, int b){
        int l = lca(a, b);
        return h[a] + h[b] - 2*h[l];
    }

    /*Retorna o k-ésimo elemento no caminho de v até a raiz*/
    int kth(int v, int k){
        k--;
        for(int i = maxl; i >= 0; i--)
            if((1 << i) <= k)
                k -= (1 << i), v = anc[v][i];

        return v;
    }

    LCA() {};
    LCA(int vtx, vector<int> a[]){
        n = vtx, maxl = ceil(log2(n)), tempo = 0;
        tin.resize(n+1, 0), tout.resize(n+1, 0), h.resize(n+1, 0);
        adj.resize(n+1), anc.resize(n+1), parent.resize(n + 1);

        for(int i = 1; i <= n; i++) 
            adj[i] = a[i], anc[i].resize(maxl + 1);

        dfs(1, 1);
    }

    deque<int> get_path(int a, int b){
        deque<int> ret1, ret2;
        int l = lca(a, b);

        ret2.push_front(b);
        while(b != l){
            b = parent[b];
            ret2.push_front(b);
        }

        while(a != l){
            ret1.pb(a);
            a = parent[a];
        }
        for(auto x: ret2) ret1.pb(x);
        return ret1;
    }
};

vector<int> adj[MAXN], aux[MAXN];
int pr[MAXN];
void dfs(int v){
    pr[v] = 1;
    for(auto x: aux[v]){
        if(!pr[x]){
            adj[v].pb(x);
            adj[x].pb(v);
            dfs(x);
        }
    }
}

int n, m, q;
LCA l;
int deg[MAXN];
signed main(){
	fastio;
    cin >> n >> m;
    fr(i, m){
        int a, b;
        cin >> a >> b;
        aux[a].pb(b);
        aux[b].pb(a);
    }
    dfs(1);

    l = LCA(n, adj);

    cin >> q;
    vector<pii> path;
    path.resize(q);

    fr(i, q){
        cin >> path[i].f >> path[i].s;
        deg[path[i].f]++, deg[path[i].s]++;
    }

    int odd = 0;
    frr(i, n){
        if(deg[i]%2) odd++;
    }
    if(odd > 0){
        cout << "NO" << endl;
        cout << (odd - 1)/2 + 1 << endl;
        return 0;
    }

    cout << "YES" << endl;
    for(auto x: path){
        deque<int> p = l.get_path(x.f, x.s);
        cout << p.size() << endl;
        for(auto x: p) cout << x << " ";
        cout << endl;
    }
}
