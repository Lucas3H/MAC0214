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
#define INF 2000000000000000100

int sz[MAXN], pai[MAXN], pr[MAXN];
vector<int> adj[MAXN];
int find(int x){
	if(pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}

void join(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	pai[b] = a;
}

bool ruim = 0;
void dfs(int v, int & a, int & b, int h){
	if(h%2) a+=sz[v];
	else b+=sz[v];
	pr[v] = h%2 + 1;

	for(auto x: adj[v]){
		if(!pr[x]) dfs(x, a, b, h + 1);
		else if(pr[x] == pr[v]) ruim = 1;
	}
}

int n, m;
void solve(){
	cin >> n >> m;
	frr(i, n) sz[i] = 1, pr[i] = 0, pai[i] = i, adj[i].clear();
	ruim = 0;

	vector<pii> e;
	fr(i, m){
		int a, b;
		string s;
		cin >> a >> b >> s;
		if(s == "crewmate") join(a, b);
		else e.pb({a, b});
	}

	for(auto p : e){
		adj[find(p.f)].pb(find(p.s));
		adj[find(p.s)].pb(find(p.f));
	}

	int ans = 0;
	frr(i, n){
		if(!pr[find(i)]){
			int a = 0, b = 0;
			dfs(find(i), a, b, 1);
			ans += max(a, b);
		}
	}
	if(ruim) cout << -1 << endl;
	else cout << ans << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--) solve();
}
