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

#define MAXN 5010
#define MOD 998244353
#define INF 1000000000000000100

ll fr[MAXN], a[MAXN], b[MAXN], acu[MAXN];

void update(ll x){
	frm(i, MAXN){
		if(i + x < MAXN) fr[i + x] = (fr[i] + fr[i + x]) % MOD;
	}
	acu[0] = fr[0];
	frr(i, MAXN-1){
		acu[i] = (acu[i-1] + fr[i]) % MOD;
	}
}

ll n, m;
signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> a[i];
	fr(i, n) cin >> b[i];
	vector<pii> v;
	fr(i, n) v.pb({a[i], b[i]});
	sort(all(v));
	fr[0] = acu[0] = 1;
	frr(i, MAXN - 1) acu[i] = 1; 
	ll ans = 0;
	fr(i, n){
		if(v[i].f >= v[i].s) {
			ans = (ans + acu[v[i].f - v[i].s]) % MOD;
		}
		update(v[i].s);
	}

	cout << ans << endl;	
}
