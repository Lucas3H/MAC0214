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

	for(auto p: vis){
		ll tira = MOD;
		if(dx != 0) tira = p.f/dx;
		if(dy != 0) tira = min(tira, p.s/dy);

		m[{p.f - tira*dx, p.s - tira*dy}].pb(p.f);
	}
}

bool comp(ll a, ll b){
	if(dx == 0) {
		if(dy > 0) return a < b;
		else return a > b;
	}
	else if(dx > 0) return a < b;
	else return a > b;
}

ll ans = 0;
ll solve(vector<ll> v){
	sort(all(v), comp);
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

	//cout << dx << " " << dy << endl; 

	for(auto x : m) {
		// cout << x.f.f << " " << x.f.s << endl;
		// cout<< "vetor ";
		// for(auto y : x.s) cout << y << " " << y - x.f.f << " | ";

		ans += solve(x.s);
	//	cout << ans << endl;
	}
	cout<< ans << endl;
}
