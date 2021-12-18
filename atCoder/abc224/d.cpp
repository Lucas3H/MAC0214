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

int m;
vector<int> adj[10];
int p[10];
map<int, vector<int>> a;

int get(vector<int> & v){
	int sum = 0;
	fr(i,v.size()){
		sum = 10 * sum + v[i];
	}
	return sum;
}
void build(vector<int> v){
	int nove = 0;
	fr(i, v.size()) if(v[i] == 9) nove = i;
	int davez = get(v);
	for(auto x: adj[nove]){
		swap(v[x], v[nove]);
		a[davez].pb(get(v));
		swap(v[x], v[nove]);
	}
}

map<int, int> dist, vis;
void bfs(int ini){
	queue<int> fila;
	fila.push(ini);
	vis[ini] = 1;
		
	while(fila.size()){
		int davez = fila.front();
		fila.pop();
		for(auto x: a[davez]){
			if(!vis[x]){
				vis[x] = 1;
				dist[x] = dist[davez] + 1;
				fila.push(x);
			}
		}
	}

}

signed main(){
	fastio;
	cin >> m;
	fr(i, m){
		int u, v;
		cin >> u >> v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}
	vector<int> v(9, 0), aux(9);
	frr(i, 8){
		cin >> p[i];
		v[p[i] - 1] = i;
	}
	fr(i, 9) if(v[i] == 0) v[i] = 9;
	aux = v;
	//for(auto x: a[get(v)]) cout << x << endl;
	// build(v);
	// swap(v[0], v[8]);
	// build(v);
	// swap(v[1], v[8]);
	// build(v);
	// swap(v[0], v[1]);
	// build(v);
	// swap(v[0], v[2]);
	// build(v);
	// swap(v[2], v[8]);
	// build(v);
	
	sort(all(v));
	do{
		build(v);
	}while ( next_permutation(v.begin(), v.end()) );

	bfs(get(aux));
	if(vis[123456789]) cout << dist[123456789] << endl;
	else cout << -1 << endl;
}
