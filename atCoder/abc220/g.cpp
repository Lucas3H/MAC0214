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

pii p[MAXN];
ll w[MAXN];
ll n;

pii mid(ll a, ll b){
	return {(p[a].f + p[b].f)/2, (p[a].s + p[b].s)/2};
}

ll val(ll a, ll b){
	return w[a] + w[b];
}

pii y(ll a, ll b, ll dx, ll dy){
	pii m = mid(a, b);
	if(dx == 0) return {0, m.s};
	ll num = m.s * dy + m.f * dx, den = dx;
	if(den < 0) num *= -1, den *= -1;
	ll g = __gcd(num, den);
	//cout << num << " " << den << " " << m.f << " " << m.s << " " << dx << " " << dy << endl;
	return {num/g, den/g};
}

/*
	{reta, {val, ponto médio}}
*/
map<pair<pii, pii>, vector<pair<pii, ll>>> m;
void build(){
	cin >> n;
	fr(i, n) cin >> p[i].f >> p[i].s >> w[i];
	fr(i, n) p[i].f *=2, p[i].s *= 2;
	fr(i, n) fr(j, i){
		ll dx = p[i].f - p[j].f, dy = p[i].s - p[j].s;
		if(dx <= 0) dx = -dx, dy = -dy;
		ll g = __gcd(dx, dy);
		dx /= g, dy /= g;
		pair<pii, pii> d;
		d.f = {dx, dy};
		d.s = y(i, j, dx, dy);
		if(dy == 0) d.s = {(p[i].f + p[j].f)/2, 0};

		//cout << i << " " << j << " -> ang: " << dx << "/" << dy << " | " << d.s.f << "|" << d.s.s << endl;
		m[d].pb({mid(i, j), val(i, j)});
	}
}

ll ans = -1;
void solve(vector<pair<pii, ll>> v){
	sort(all(v));
	ll best = -1;
	ll i = 0;
	while(i < v.size()){
		ll ini = i, davez = -1;
		while(i < v.size() && v[i].f == v[ini].f){
			davez = max(davez, v[i].s);
			i++;
		}
		if(best > -1) ans = max(ans, best + davez);
		best = max(best, davez);
	}
}


signed main(){
	fastio;
	build();
	for(auto x: m) {
		pair<pii, pii> y = x.f;
		solve(x.s);
		// cout << y.f.f << "/" << y.f.s << "   " << y.s.f << "/" << y.s.s << endl;
		// dbg(ans);
	}
	cout << ans<< endl;

}
