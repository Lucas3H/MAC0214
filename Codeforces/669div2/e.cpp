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

#define MAXN 500010
#define MOD 1000000007
#define INF 2000000000000000100

int cor[MAXN], dist[MAXN];
set<int> aux[MAXN];
vector<int> rev[MAXN][2], adj[MAXN][2];
int n, m;

void dijkstra(){
	queue<int> fila;
	fila.push(n);

	dist[n] = 0;
	while(fila.size()){
		int v = fila.front();
		fila.pop();

		for(auto x: adj[v][0]){
			if(cor[x] == 0){
				aux[x].insert(1);
				if(aux[x].size() == 2){
					// dbg(x);
					// dbg(v);
					dist[x] = dist[v] + 1;
					fila.push(x);
					cor[x] = 1;
				}
			}
		}

		for(auto x: adj[v][1]){
			if(cor[x] == 0){
				aux[x].insert(2);
				if(aux[x].size() == 2){
					// dbg(x);
					// dbg(v);
					dist[x] = dist[v] + 1;
					fila.push(x);
					cor[x] = 2;
				}
			}
		}
	}
}

signed main(){
	fastio;
	mem(dist, -1);
	cin >> n >> m;

	fr(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		adj[b][c].pb(a);
	}

	dijkstra();
	frr(i, n) if(cor[i] == 0) {
		if(aux[i].size()) cor[i] = 3 - *(aux[i].begin());
		else cor[i] = 1;
	}
	
	cout << dist[1] << endl;
	frr(i, n) cout << cor[i] - 1;
	cout << endl;
}	
