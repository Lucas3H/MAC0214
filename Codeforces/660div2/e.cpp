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

#define MAXN 2010
#define MOD 1000000007
#define INF 2000000000000000100

/*
	ia é sempre o mais baixo
	{ia, ib, tipo}
	tipo = 0, é o menor
*/
vector<array<ll, 3>> v;
set<pii> cur;
vector<ll> ord;
ll xl[MAXN], xr[MAXN], y[MAXN];
ll n;
set<pii> vira;

pii get(array<ll, 3> a){
	ll dx, dy = y[a[0]] - y[a[1]];
	if(a[2] == 1) dx = xr[a[0]] - xl[a[1]];
	else dx = xl[a[0]] - xr[a[1]];

	ll g = abs(__gcd(dx, dy));
	return {dx / g, dy / g};
}

bool comp(array<ll, 3> a, array<ll, 3> b){
	pii v1 = get(a), v2 = get(b);

	if(v1.f * v2.f > 0) return v1.s * v2.f < v2.s * v1.f;
	else if(v1.f < 0) return true;
	else return false;
}

double ans = INF;

void build_ans(pii v){
	double l = (double) xl[ord[0]] - (double) y[ord[0]] * v.f / v.s;
	double r = (double) xr[ord.back()] - (double) y[ord.back()] * v.f / v.s;
	ans = min(ans, r - l);
}

void fix_ord(){
	fr(i, n - 1){
		if(vira.count({min(ord[i], ord[i + 1]), max(ord[i], ord[i + 1])})){
			swap(ord[i], ord[i + 1]);
		}
	}
	frm(i, n - 1){
		if(vira.count({min(ord[i], ord[i + 1]), max(ord[i], ord[i + 1])})){
			swap(ord[i], ord[i + 1]);
		}
	}
	fr(i, n - 1){
		if(vira.count({min(ord[i], ord[i + 1]), max(ord[i], ord[i + 1])})){
			swap(ord[i], ord[i + 1]);
		}
	}
	frm(i, n - 1){
		if(vira.count({min(ord[i], ord[i + 1]), max(ord[i], ord[i + 1])})){
			swap(ord[i], ord[i + 1]);
		}
	}
}

void process(array<ll, 3> a){
	if(cur.size() == n * (n - 1) / 2) 
		build_ans(get(a));

	if(a[2] == 0) cur.erase({min(a[0], a[1]), max(a[0], a[1])});
	else {
		cur.insert({min(a[0], a[1]), max(a[0], a[1])});
		vira.insert({min(a[0], a[1]), max(a[0], a[1])});
		cout << min(a[0], a[1]) << " || " << max(a[0], a[1]) << endl;
		fix_ord();
	}
	if(cur.size() == n * (n - 1) / 2) 
		build_ans(get(a));

}

signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> xl[i] >> xr[i] >> y[i];
	fr(i, n) fr(j, i){
		if(y[i] > y[j]) fr(k, 2) v.pb({j, i, k});
		if(y[i] < y[j]) fr(k, 2) v.pb({i, j, k});
		cur.insert({j, i});
	}
	fr(i, n) ord.pb(i);

	sort(all(v), comp);
	// for(auto x: v) cout << x[0] << " " << x[1] << " " << x[2] << endl;

	sort(all(ord), [&](ll a, ll b){
		if(y[a] == y[b]) return xl[a] < xl[b];
		else return y[a] > y[b];
	});
	
	fr(i, n) cout << ord[i] << " ";
	cout << endl;

	for(auto x: v) {
		cout << x[0] << " " << x[1] << " " << x[2] << endl;
		process(x);
		fr(i, n) cout << ord[i] << " ";
		cout << endl;
	}
	printf("%.9lf\n", ans);
}

