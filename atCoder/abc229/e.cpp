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

vector<int> adj[MAXN];
int comp;
int sz[MAXN], pai[MAXN];
int ans[MAXN];
int find(int x){
	if(pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}

void join(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	comp--;
	if(sz[a] < sz[b]) swap(a, b);
	pai[b] = a;
	sz[a] += sz[b]; 
}

signed main(){
	fastio;
	int n, m;
	cin >> n >> m;
	frr(i, n) pai[i] = i, sz[i] = 1;
	fr(i, m){
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
	}

	for(int i = n; i >= 1; i--){
		ans[i] = comp;
		comp++;
		for(auto x: adj[i]) join(i, x);
		
	}
	frr(i, n) cout << ans[i] << endl;
}
