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

#define MAXN 100010
#define MOD 1000000007
#define INF 1000000000000000100

vector<pii> adj[MAXN];
ll sz[MAXN], pai[MAXN];
ll n;
ll find(ll x){
	if(x == pai[x]) return x;
	else return pai[x] = find(pai[x]);
}

ll join(ll a, ll b){
	a = find(a), b = find(b);
	if(a == b) return false;
	if(sz[a] > sz[b]) swap(a, b);
	pai[a] = b;
	sz[b] += sz[a];
	return true;
}

map<ll, vector<ll>> x, y;

pii p[MAXN];
bool test(ll t){
	frr(i, n) sz[i] = 1, pai[i] = i;

	ll tot = 0;
	frr(i, n){
		for(auto x: adj[i]) {
			if(x.s <= t) tot += join(i, x.f);
		}
	}

	dbg(tot);
	if(tot == n-1) return true;
	else if(tot < n-4) return false;
	else if(tot == n-2){
		ll minimo = 2*MOD;
		frr(i, n){
			frr(j, i-1){
				if(find(i) != find(j)){
					if(p[i].f == p[j].f) minimo = min(minimo, (abs(p[i].s - p[j].s) + 1)/2);
					else if(p[i].s == p[j].s) minimo = min(minimo, (abs(p[i].f - p[j].f) + 1)/2);
					else minimo = min(minimo, max(abs(p[i].s - p[j].s), abs(p[i].f - p[j].f)));
				} 
			}
		}
		if(minimo <= t) return true;
		else return false;
	}
	else if(tot == n-3){
		ll minimo = 2*MOD;
		frr(i, n){
			for(auto & q : x){
				ll it = lower_bound(all(q.s), p[i].s) - q.s.begin();
				if(it == q.s.size()){
					minimo = min(minimo, max(p[i].s - q.s.back(), abs(q.f - p[i].f)));
				}
				else if(it == 0){
					minimo = min(minimo, max(q.s[0] - p[i].s, abs(q.f - p[i].f)));
				}
				else{
					ll aux = max(p[i].s - q.s[it-1], abs(q.f - p[i].f));
					aux = max(aux, q.s[it-1]-p[i].s);
					minimo = min(minimo, aux);
				}
			}
		}

		frr(i, n){
			for(auto & q : y){
				ll it = lower_bound(all(q.s), p[i].f) - q.s.begin();
				if(it == q.s.size()){
					minimo = min(minimo, max(p[i].f - q.s.back(), abs(q.f - p[i].s)));
				}
				else if(it == 0){
					minimo = min(minimo, max(q.s[0] - p[i].f, abs(q.f - p[i].s)));
				}
				else{
					ll aux = max(p[i].f - q.s[it-1], abs(q.f - p[i].s));
					aux = max(aux, q.s[it-1]-p[i].f);
					minimo = min(minimo, aux);
				}
			}
		}
		if(minimo <= t) return true;
		else return false;
	}
	else{
		ll minimo = 2*MOD;
		frr(i, n){
			for(auto & q : x){
				ll it = lower_bound(all(q.s), p[i].s) - q.s.begin();
				ll aux;
				if(it == q.s.size())
					aux = p[i].s - q.s.back();
				else if(it == 0)
					aux = max(aux, q.s[it] - p[i].s);
				else
					aux = max(p[i].s - q.s[it-1], q.s[it-1]-p[i].s);

				vector<ll> v = y[p[i].s];

				it = lower_bound(all(v), q.f) - v.begin();
				if(it == v.size())

					aux = max(aux, q.f - v.back());
				else if(it == 0)

					aux = max(aux, v[it] - q.f);
				else

					aux = max(q.f - v[it-1], max(v[it-1]-q.f, aux));
				minimo = min(minimo, aux);
			}
		}

		if(minimo <= t) return true;
		else return false;
	}
}

void build(){
	cin >> n;
	frr(i, n) cin >> p[i].f >> p[i].s;
	frr(i, n){
		frr(j, i-1){
			if(p[i].f == p[j].f){
				adj[i].pb({j, abs(p[i].s - p[j].s)});
				adj[j].pb({i, abs(p[i].s - p[j].s)});
			}
			else if(p[i].s == p[j].s){
				adj[i].pb({j, abs(p[i].f - p[j].f)});
				adj[j].pb({i, abs(p[i].f - p[j].f)});
			}
		}

		x[p[i].f].pb(p[i].s);
		y[p[i].s].pb(p[i].f);
	}

	for(auto & q : x) sort(all(q.s));
	for(auto & q : y) sort(all(q.s));
}

signed main(){
	fastio;
	build();
	ll l = 0, r = 2*MOD, m;
	while(l < r - 1){
		m = (l + r)/2;
		if(test(m)) r = m;
		else l = m;
	}
	if(r == 2*MOD) cout << -1 << endl;
	else cout << r << endl;
}
