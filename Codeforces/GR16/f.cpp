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

set<pii> segments;
set<pii> r;
set<ll> points;

ll n, m;

void tira(){
	set<pii> aux = segments;
	for(auto x: aux){
		auto it = points.lower_bound(x.f);
		if(it != points.end() && *it <= x.s) segments.erase(x);
		
		auto it1 = r.lower_bound(mp(x.s, (ll)-MOD));
		while(r.size() && it1 != r.end()){
			segments.erase({(*it1).s, (*it1).f});
			r.erase(it1);
			it1 = r.lower_bound(mp(x.s, (ll)-MOD));
		}
		r.insert({x.s, x.f});
	}
}

map<ll, ll> dp;
ll best_value;

void solve(ll a, vector<pii> s, ll b){
	if(s.size() == 0) {
		dp[b] = best_value;
		return;
	}
	dp[b] = INF;
	
	dp[b] = min(dp[b], best_value + 2*(b - s[0].s));
	fr(i, s.size()-1){
		dp[b] = min(dp[b], dp[a] + s[i].f - a + 2*(b - s[i+1].s));
		dp[b] = min(dp[b], best_value + 2*(s[i].f - a) + 2*(b - s[i+1].s));
	}
	dp[b] = min(dp[b], dp[a] + s.back().f - a);
	dp[b] = min(dp[b], best_value + 2*(s.back().f - a));

	ll old_best_value = best_value;
	best_value = INF;

	best_value = min(best_value, old_best_value + (b - s[0].s));
	fr(i, s.size()-1){
		best_value = min(best_value, dp[a] + s[i].f - a + (b - s[i+1].s));
		best_value = min(best_value, old_best_value + 2*(s[i].f - a) + (b - s[i+1].s));
	}

	best_value = min(best_value, dp[a] + s.back().f - a);	
	best_value = min(best_value, old_best_value + 2*(s.back().f - a));
}

ll t;
void build(){
	segments.clear(), r.clear(), points.clear();
	cin >> n >> m;
	fr(i, n){
		ll a;
		cin >> a;
		points.insert(a);
	}
	map<ll, ll> aux;
	set<ll> auxs;
	fr(i, m){
		ll a, b;
		cin >> a >> b;
		if(!auxs.count(a)) aux[a] = b;
		else aux[a] = min(aux[a], b);
		auxs.insert(a);
	}
	for(auto x: aux) segments.insert({x.f, x.s});


	tira();
	//for(auto x: segments) cout << x.f << " " << x.s << endl;
	best_value = 0;
	dp.clear();
	points.insert(-INF);
	points.insert(INF);
	//for(auto x: segments) cout << x.f << " | " << x.s << endl;
}

signed main(){
	fastio;
	cin >> t;

	while(t--){
		build();
		while(segments.size()){
			ll a = (*points.begin());
			points.erase(points.begin());
			ll b = (*points.begin());
			vector<pii> s;
			while(segments.size() && (*segments.begin()).s <= b){
				s.pb((*segments.begin()));
				segments.erase(segments.begin());
			}
			solve(a, s, b);
		}
		cout << best_value << endl;
	}
}
