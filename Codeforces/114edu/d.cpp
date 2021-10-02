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

ll n, m;
vector<ll> items[MAXN];
map<vector<ll>, ll> banned;
map<vector<ll>, ll> pr;

void dijkstra(){
	vector<ll> ini;
	ll val = 0;
	fr(i, n) ini.pb((ll)items[i].size() - 1), val += items[i].back();
	pq<pair<ll, vector<ll>>> fila;
	fila.push({val, ini});
	pr[ini] = 1;

	while(fila.size()){
		vector<ll> davez;
		ll dist = -1;
		pair<ll, vector<ll>> p = fila.top();
		fila.pop();
		if(!banned[p.s]){
			for(auto x: p.s) cout << x + 1<< " ";
			cout << endl;
			exit (0);
		}

		davez = p.s;
		dist = p.f;

		// for(auto x: p.s) cout << x + 1<< " ";
		// cout << endl;

		fr(i, n){
			if(davez[i]){
				dist -= items[i][davez[i]];
				davez[i]--;
				dist += items[i][davez[i]];

				if(!pr[davez]){
					fila.push({dist, davez});
					pr[davez] = 1;
				}

				dist -= items[i][davez[i]];
				davez[i]++;
				dist += items[i][davez[i]];
			}
		}

	}
}

signed main(){
	fastio;
	cin >> n;
	fr(i, n){
		ll c;
		cin >> c;
		items[i].resize(c);
		fr(j, c) cin >> items[i][j];
	}
	cin >> m;
	fr(i, m){
		vector<ll> b;
		b.resize(n);
		fr(j, n) cin >> b[j], b[j]--;
		banned[b] = 1;
	}
	dijkstra();
}
