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

#define MAXN 410
#define MOD 1000000007
#define INF 1000000000000000100

vector<array<ll, 3>> e;
ll dist[MAXN][2];
ll in[MAXN];
vector<pii> adj[MAXN];

ll n, m;
ll bfs(ll b){
	ll i = (b > -1);
	frr(j, n) dist[j][i] = -1;
	queue<ll> fila;
	fila.push(1);
	dist[1][i] = 0;
	while(fila.size()){
		ll davez = fila.front();
		fila.pop();
		for(pii p : adj[davez]){
			if(p.s == b) continue;
			if(dist[p.f][i] == -1){
				dist[p.f][i] = dist[davez][i] + 1;
				fila.push(p.f);
				if(i == 0){	
					in[p.f]++;
					e[p.s][2] = 1;
				}
			}
			else if(i == 0 && dist[p.f][i] == dist[davez][i] + 1)
				in[p.f]++;
		}	}
	return dist[n][i];
}

signed main(){
	fastio;
	cin >> n >> m;
	fr(i, m){
		ll a, b;
		cin >> a >> b;
		e.pb({a, b, 0});
		adj[a].pb({b, i});
	}
	bfs(-1);
	fr(i, m){
		if(e[i][2]) cout << bfs(i) << '\n';
		else cout << dist[n][0] << '\n';
	}
}
