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

map<pii, ll> m;

void coloca(ll x, ll b){
	ll pref = 0;
	for(ll i = b; i >= 0; i--){
		if((x&(1 << i))) pref += (1 << i);
		m[{pref, i}] = 1;
	}
}

ll get_ans(ll x, ll b){
	ll ans = 0;
	ll pref = 0;
	for(ll i = b; i >= 0; i--){
		if((x&(1 << i))) {
			pref += (1 << i);
			if(!m[{pref, i}]){
				pref -= (1 << i);
				ans += (1 << i);
			}
		}
		else{
			if(!m[{pref, i}]){
				pref += (1 << i);
				ans += (1 << i);
			}
		}
	}
	return ans;
}

ll solve(vector<ll> & a, ll b){
	if(a.size() == 0) return 0;
	if(b == 0) return 0;

	vector<ll> u, z;
	for(auto x: a) {
		if((x&(1 << b))) u.pb((x^(1 << b)));
		else z.pb(x);
	}
	a.clear();
	if((u.size())%2 == 0){
		ll ans =  max(solve(u, b - 1), solve(z, b - 1));
		// db;
		// dbg(b);
		// for(auto x: a) cout << x << " ";
		// cout << endl;
		// dbg(ans);
		return ans;
	}

	m.clear();
	for(auto x: z) coloca(x, b);

	ll ans = INF;
	for(auto x: u) ans = min(ans, get_ans(x, b) + (1 << b));
	// dbg(get_ans(u[0], b));
	// dbg(b);
	// for(auto x: a) cout << x << " ";
	// cout << endl;
	// dbg(ans);
	return ans;
}

vector<ll> a;
ll n;
signed main(){
	fastio;
	cin >> n;
	a.resize(2*n);
	fr(i, 2*n) cin >> a[i];
	cout << solve(a, 29) << endl;
}
