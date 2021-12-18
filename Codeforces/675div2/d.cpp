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
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

vector<pii> adj[MAXN];
ll n, m;
ll xi, yi, xf, yf;
pair<pii, ll> p[MAXN];

bool comp(pair<pii, ll> a, pair<pii, ll> b){
	return a.f.s < b.f.s;
}

ll dist[MAXN];

void dijkstra(ll v){
	fr(i, m + 2) dist[i] = INF;

	pq<pii, vector<pii>, greater<pii>> fila;
	fila.push(mp(0, v));

	/*
	fr(i, m+2) cout << dist[i] << ' ';
	cout << endl;
	*/
	while(true){
		ll davez = -1;

		while(!fila.empty()){
			pii p = fila.top();
			fila.pop();


			if(dist[p.s] > p.f){
				dist[p.s] = p.f;
				davez = p.s;

				break;
			}
		}
		if(davez == -1) break;

		for(pii e: adj[davez]){
			if(dist[e.f] > dist[davez] + e.s){
				fila.push(mp(dist[davez] + e.s, e.f));
			}
		}
	}

	/*
	fr(i, m+2) cout << dist[i] << ' ';
	cout << endl;
	*/
}

void read(){
	cin >> n >> m >> xi >> yi >> xf >> yf;

	frr(i, m){
		cin >> p[i].f.f >> p[i].f.s;
		p[i].s = i;
	}

	sort(p + 1, p + m + 1);
	frr(i, m-1){
		adj[p[i].s].pb({p[i + 1].s, p[i + 1].f.f - p[i].f.f});
		adj[p[i + 1].s].pb({p[i].s, p[i + 1].f.f - p[i].f.f});
	}

	sort(p + 1, p + m + 1, comp);
	frr(i, m-1){
		adj[p[i].s].pb({p[i + 1].s, p[i + 1].f.s - p[i].f.s});
		adj[p[i + 1].s].pb({p[i].s, p[i + 1].f.s - p[i].f.s});
	}

	frr(i, m){
		adj[0].pb({p[i].s, min(abs(p[i].f.f - xi), abs(p[i].f.s - yi))});
		adj[p[i].s].pb({0, min(abs(p[i].f.f - xi), abs(p[i].f.s - yi))});

		adj[p[i].s].pb({m + 1, abs(p[i].f.f - xf) + abs(p[i].f.s - yf)});
	}

	adj[0].pb({m + 1, abs(xi - xf) + abs(yi - yf)});
	adj[m+1].pb({0, abs(xi - xf) + abs(yi - yf)});
}

int main(){
	ios::sync_with_stdio(false);
	read();
	dijkstra(0);

	cout << dist[m + 1] << endl;
}
