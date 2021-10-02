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

#define MAXN 200010
#define MOD 1000000007
#define INF 1000000000000000100

/*
	{diferença, resto%dx} -> inicios;
*/
ll dx, dy, k;
map<pii, vector<ll>> m;

void build(string s){
	ll x = 0, y = 0;
	vector<pii> vis;
	vis.pb({0, 0});
	for(auto a: s){
		if(a == 'U') y++;
		else if(a == 'D') y--;
		else if(a == 'R') x++;
		else x--;
		vis.pb({x, y});
	}

	dx = x, dy = y;
	if(dx == 0 && dy == 0){
		set<pii> s;
		for(auto a : vis) s.insert(a);
		cout << s.size() << endl;
		exit (0);
	}
	if(dx < 0) for(auto & p : vis) p.f *= -1;
	if(dy < 0) for(auto & p : vis) p.s *= -1;
	dx = abs(dx), dy = abs(dy);

	if(dx == 0) {
		for(auto & p : vis) swap(p.f, p.s);
		swap(dx, dy);
	}

	for(auto p: vis){
		ll ini = p.f;
		if(p.f < 0){
			ll tot = abs(p.f)/dx;
			p.f += tot * dx;
			p.s += tot*dy;
			while(p.f < 0){
				p.f += dx;
				p.s += dy;
			}
		}	
		else{
			ll tot = p.f/dx;
			p.f -= tot * dx;
			p.s -= tot * dy;
			while(p.f - dx >= 0){
				p.f -= dx;
				p.s -= dy;
			}
		}
		//cout << p.f << " " << p.s << endl;

		m[{p.f, p.s}].pb(ini);
	}
}

ll ans = 0;
ll solve(vector<ll> v){
	sort(all(v));
	ll ret = 0, tam = (ll)v.size() - 1;
	fr(i, tam){
		if((v[i+1] - v[i])/dx <= k) ret += (v[i+1] - v[i])/dx;
		else ret += k;
	}

	ret += k;
	return ret;
}

signed main(){
	fastio;
	string s;
	cin >> s >> k;
	build(s);

	for(auto x : m) {
			// cout << x.f.f << " " << x.f.s << endl;
			// cout<< "vetor ";
			// for(auto y : x.s) cout << y << " | ";

		ans += solve(x.s);
		//cout << ans << endl;
	}
	cout<< ans << endl;
}
