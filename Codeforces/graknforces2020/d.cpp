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

#define MAXN 1000010
#define MOD 1000000007
#define INF 2000000000000000100

int n, m;
vector<pii> rob, light;


/*
	{rob, light}
*/
vector<pii> minimo[MAXN];

multiset<int> minimos;

void build(){
	cin >> n >> m;
	rob.resize(n);
	fr(i, n) cin >> rob[i].f >> rob[i].s;
	light.resize(m);
	fr(i, m) cin >> light[i].f >> light[i].s;
	sort(all(light));
	vector<pii> aux;
	fr(i, m){
		while(aux.size() && aux.back().s <= light[i].s) aux.pop_back();
		aux.pb(light[i]);
	}
	light = aux;

	fr(i, n){
		fr(j, m){
			if(rob[i].f > light[j].f) continue;
			if(rob[i].s > light[j].s) break;
			minimo[light[j].f - rob[i].f].pb({i, j});
			//cout << light[j].f - rob[i].f << " " << i << ' ' << j << endl;
			minimos.insert(-(light[j].s - rob[i].s + 1));
			break;
		}
	}
}

int ans = 2*MOD;

void solve(int ind){
	if(minimos.size() == 0) ans = min(ans, ind);
	else ans = min(ans, ind - *(minimos.begin()));

	for(pii p: minimo[ind]){
		minimos.erase(minimos.find(-(light[p.s].s - rob[p.f].s + 1)));
		if(p.s == light.size() - 1 || light[p.s + 1].s < rob[p.f].s) continue;
		minimos.insert(-(light[p.s + 1].s - rob[p.f].s + 1));
		minimo[light[p.s + 1].f - rob[p.f].f].pb({p.f, p.s + 1});
	}
}

signed main(){
	fastio;

	build();
	fr(i, MAXN) solve(i);
	cout << ans << endl;
}
