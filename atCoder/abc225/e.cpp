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

vector<pair<pii, pii>> v;
ll n;

bool comp1(const pair<pii, pii> a, const pair<pii, pii> b){
	if(a.f.f*b.f.s == a.f.s * b.f.f) return a.s.s * b.s.f < a.s.f * b.s.s;
	return a.f.s * b.f.f < a.f.f * b.f.s;
}
bool comp(const pii a, const pii b){
	return a.s*b.f <= a.f * b.s;
}

signed main(){
	fastio;
	cin >> n;
	fr(i, n){
		ll x, y;
		cin >> x >> y;
		v.pb({{x - 1, y}, {x, y - 1}});
	}
	sort(all(v), comp1);

	ll ans = 0;
	pii davez = {1, -1};
	fr(i, n){
		if(comp(davez, v[i].s)){
			davez = v[i].f;
			ans++;
		}
		//cout << v[i].f.f << "/" << v[i].f.s << " " << v[i].s.f << "/" << v[i].s.s << " " << endl;
	}
	cout << ans << endl;
}
