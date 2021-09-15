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

set<ll> v, h;

signed main(){
	fastio;
	ll t;
	cin >> t;
	while(t--){
		ll n, m, k;
		cin>> n >> m >> k;
		v.clear(), h.clear();
		fr(i, n){
			ll a;
			cin >> a;
			v.insert(a);
		}
		fr(i, m){
			ll a;
			cin >> a;
			h.insert(a);
		}
		map<pii, ll> th, tv;
		fr(i, k){
			ll x, y;
			cin >> x >> y;
			if(!v.count(x)){
				ll r = *(v.lower_bound(x));
				tv[{y, r}]++;
			}
			if(!h.count(y)){
				ll r = *(h.lower_bound(y));
				th[{x, r}]++;
			}
		}

		map<ll, ll> ansV, ansH;
		for(auto x: th) ansH[x.f.s] += x.s;
		for(auto & x: ansH) x.s = (x.s - 1) * x.s / 2;
		for(auto x: th) ansH[x.f.s] -= (x.s - 1) * x.s / 2;
		
		for(auto x: tv) ansV[x.f.s] += x.s;
		for(auto & x: ansV) x.s = (x.s - 1) * x.s / 2;
		for(auto x: tv) ansV[x.f.s] -= (x.s - 1) * x.s / 2;

		ll ans = 0;
		for(auto x: ansV) ans += x.s;
		for(auto x: ansH) ans += x.s;
		
		
		cout << ans << endl;
	}
}
