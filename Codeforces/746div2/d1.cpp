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
int n, ans;
vector<pii> tira;
int tam;
set<int> a, cur;
int pr[MAXN];

void dfs(int v, int p){
	if(a.size() > cur.size()/2) return;
	
	if(p != 0) tira.pb({v, p});
	pr[v] = 1;
	a.insert(v);
	for(auto x: adj[v]){
		if(x != p) dfs(x, v);
	}
}

int tot_ask = 0;
int ask(){
	tot_ask++;
	if(tot_ask > 12) assert(0);
	if(a.size() == 1) assert(0);

	cout << "? " << a.size() << " ";
	for(auto x: a) cout << x << " ";
	cout<< endl;
	int x;
	cin>> x;
	return x;
}

void solve(){
	cin >> n;
	frr(i, n) adj[i].clear();
	fr(i, n-1){
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	cout << "? " << n << ' ';
	frr(i, n) cout << i << ' ';
	cout << endl;
	cin >> ans;
	frr(i, n) cur.insert(i);

	while(cur.size() > 2){
		a.clear();
		tira.clear();
		frr(i, n) pr[i] = 0;
		for(auto x: cur) {
			if(!pr[x]) dfs(x, 0);
		}
		if(ask() == ans){
			cur = a;
			frr(i, n) adj[i].clear();
			for(auto x: tira){
				adj[x.f].insert(x.s);
				adj[x.s].insert(x.f);
			}
		}
		else{
			for(auto x: tira){
				adj[x.f].erase(x.s);
				adj[x.s].erase(x.f);
			}
			cur.clear();
			frr(i, n) if(adj[i].size()) cur.insert(i);
		}
	}

	cout << "! ";
	for(auto x: cur) cout << x << " ";
	cout << endl;
}

signed main(){
	fastio;
	solve();
}
