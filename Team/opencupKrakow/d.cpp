#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_ll_distribution<ll>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 2010
#define MOD 1000000007
#define INF 2000000000000000100

vector <ll> g[MAXN], gr[MAXN];
ll n;

struct KOSARAJU{
    vector<bool> used;
    vector<int> order, comp, size;
    int tot = 0;

    void dfs1 (int v) {
        used[v] = true;
        for (size_t i=0; i<g[v].size(); ++i)
            if (!used[ g[v][i] ]) dfs1 (g[v][i]);
        order.push_back (v);
    }

    void dfs2 (int v, int c) {
        used[v] = true, comp[v] = c, size[c]++;
        for (size_t i=0; i<gr[v].size(); ++i)
            if (!used[ gr[v][i] ]) dfs2 (gr[v][i], c);
    }

    void build(){
        comp.assign(n, -1), size.assign(n, 0), order.clear(), used.assign(n, false);
        for (int i=0; i<n; ++i)
            if (!used[i]) dfs1 (i);

        used.assign (n, false), tot = 0;

        for (int i=0; i<n; ++i) {
            int v = order[n-1-i];
            if (!used[v]) dfs2 (v, tot++);
        }
    }
};

vector<pii> adj[MAXN];
ll a[MAXN][MAXN];
KOSARAJU k;
ll dist[MAXN], pai[MAXN];

pii dijkstra(ll ini){
	fr(i, n) dist[i] = -1;
	pq<array<ll, 3>> fila;
	fila.push({0, ini, -1});

	while(fila.size()){
		array<ll, 3> p = fila.top();
		fila.pop();
		if(dist[p[1]] != -1) continue;
		
		dist[p[1]] = -p[0];
		pai[p[1]] = p[2];
		for(auto x : adj[p[1]]) if(dist[x.f] == -1)
			fila.push({-dist[p[1]] - x.s, x.f, p[1]});
	}

	ll ans = 0, v = 0;
	fr(i, n) {
		if(ans < dist[i]){
			ans = dist[i];
			v = i;
		}
	}
	return {ans, v};
}

void solve(){
    cin >> n;
    fr(i, n) g[i].clear(), gr[i].clear(), adj[i].clear();

    fr(i, n) fr(j, n){
    	cin >> a[i][j];
    	if(a[i][j] != 0){
    		g[i].pb(j);
    		gr[j].pb(i);
    	}
    }

    if(n == 2){
    	cout<< "NO" << endl;
    	return;
    }

    k.build();
    fr(i, n) fr(j, n){
    	if(a[i][j] != 0){
    		if(k.comp[i] == k.comp[j]) {
    			adj[i].pb({j, 0});
    		}
    		else{
    			adj[i].pb({j, 0});
    			adj[j].pb({i, a[i][j]});
    		}
    	}
    } 

    set<ll> comps;
    fr(i, k.tot) comps.insert(i);
    fr(i, n) fr(j, n){
    	if(a[i][j] != 0){
    		if(k.comp[i] != k.comp[j]) {
    			comps.erase(k.comp[i]);
    		}
    	}
    } 

    ll fim, val, ini;
    fr(i, n){
    	if(k.comp[i] == *(comps.begin())){
    		pii d = dijkstra(i);
    		val = d.f, fim = d.s, ini = i;
    		break;
    	}
    }

    vector<pii> edges;
    while(fim != ini){
    	if(a[fim][pai[fim]] != 0 && k.comp[fim] != k.comp[pai[fim]]) 
    		edges.pb({fim, pai[fim]});
    	fim = pai[fim];
    }

    cout << "YES" << endl;
    cout << edges.size() << " " << val << endl;
    for(auto x: edges) cout << x.f + 1 << " " << x.s + 1 << endl;
}

signed main(){
	fastio;
	ll t;
	cin >> t;
	while(t--) solve();
}
