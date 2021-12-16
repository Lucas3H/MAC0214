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
#define INF 2000000000000000100

pii pt[MAXN];
// {x, y_cima, y_baixo}
vector<array<ll, 3>> esq, dir;

multiset<ll> f1; // 2 * y_cima + x
multiset<ll> f2; // y_cima + x
multiset<ll> f3; // 2*-y_baixo + x
multiset<ll> f4; // -y_baixo + 2 * x

ll n;
ll il = -1; // Último cara maior ou igual
ll ir = 0; // Primeiro cara menor
ll ans = INF;
ll pref[MAXN];

void build(){
	esq.clear(), dir.clear();
	il = -1, ir = 0;
	f1.clear(), f2.clear(), f3.clear(), f4.clear();

	vector<pii> v;
	fr(i, n) {
		if(pt[i].f < 0) v.pb({pt[i].f, pt[i].s});
	}

	sort(all(v));
	ll y_cima = 0, y_baixo = 0;
	for(auto x: v){
		esq.pb({x.f, y_cima, y_baixo});
		y_cima = max(y_cima, x.s);
		y_baixo = min(y_baixo, x.s);
	}

	esq.pb({0, y_cima, y_baixo});
	reverse(all(esq));

	v.clear();
	fr(i, n) {
		if(pt[i].f >= 0) v.pb({-pt[i].f, pt[i].s});
	}

	sort(all(v));
	y_cima = 0, y_baixo = 0;
	for(auto x: v){
		dir.pb({-x.f, y_cima, y_baixo});
		y_cima = max(y_cima, x.s);
		y_baixo = min(y_baixo, x.s);
	}

	dir.pb({0, y_cima, y_baixo});
	reverse(all(dir));

	ll val = INF;
	fr(i, (ll)dir.size()){
		val = min(val, dir[i][0] + dir[i][1] - dir[i][2] + min(dir[i][1], -dir[i][2]));
		pref[i] = val;
	}
}

void process(ll x, ll y_cima, ll y_baixo){
	while(ir < (int)dir.size() && (dir[ir][1] > y_cima || dir[ir][2] < y_baixo)){
		// Colocar as paradas no multiset
		f1.insert(2*dir[ir][1] + dir[ir][0]);
		f2.insert(dir[ir][1] + dir[ir][0]);
		f3.insert(-2*dir[ir][2] + dir[ir][0]);
		f4.insert(-dir[ir][2] + dir[ir][0]);
		ir++;
	}

	while(il + 1 < (int)dir.size() && dir[il + 1][1] >= y_cima && dir[il + 1][2] <= y_baixo){
		// Tirar as paradas do multiset
		il++;
		if(il < ir){
			f1.erase(f1.find(2*dir[il][1] + dir[il][0]));
			f2.erase(f2.find(dir[il][1] + dir[il][0]));
			f3.erase(f3.find(-2*dir[il][2] + dir[il][0]));
			f4.erase(f4.find(-dir[il][2] + dir[il][0]));
		}
	}
	while(ir < il) ir++;

	if(il >= 0){
		ans = min(ans, 2 * (-x) + pref[il]);
	}
	
	if(ir < dir.size())
		ans = min(ans, 2 * (-x) + dir[ir][0] + (y_cima + -y_baixo + min(-y_baixo, y_cima)));

	// dbg(x);
	// dbg(ans);
	// cout << il << " " << ir << " " << x << endl;
	if(il + 1 < ir){
		if(dir[il + 1][1] < y_cima){
			// y_cima prevalece
			// Pega de f3 e f4
			ans = min(ans, 2 * (-x) + *(f3.begin()) + y_cima);
			ans = min(ans, 2 * (-x) + *(f4.begin()) + 2 * y_cima);
		}
		else{
			// dbg(*(f1.begin()));
			// dbg(*(f2.begin()));
			// y_baixo prevalece
			// Pega de f1 e f2
			ans = min(ans, 2 * (-x) + *(f1.begin()) + -y_baixo);
			ans = min(ans, 2 * (-x) + *(f2.begin()) + 2 * -y_baixo);
		}
	}
	//dbg(ans);
}

void solve(){
	cin >> n;
	fr(i, n) cin >> pt[i].f >> pt[i].s;

	ans = INF;
	build();
	//fr(i, dir.size()) cout << dir[i][0] << " " << dir[i][1] << " " << dir[i][2] << endl; 

	for(auto x: esq) process(x[0], x[1], x[2]);
	fr(i, n) pt[i].f *= -1;
	build();
	for(auto x: esq) process(x[0], x[1], x[2]);

	cout << ans << endl;
}	

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--) solve();
}
