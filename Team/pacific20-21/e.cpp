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

#define MAXN 300010
#define MOD 1000000007
#define INF 2000000000000000100

ll nd[4*MAXN];

void update(ll i, ll l, ll r, ll p, ll v){
	if(l == r) nd[i] += v;
	else{
		ll m = (l + r)/2;
		if(m >= p) update(2*i, l, m, p, v);
		else update(2*i + 1, m + 1, r, p, v);
		nd[i] = nd[2*i] + nd[2*i + 1];
	}
}

void build(ll i, ll l, ll r){
	nd[i] = r - l + 1;
	if(l == r) return;
	int m = (l + r)/2;
	build(2*i, l, m);
	build(2*i + 1, m + 1, r);
}

ll query(ll i, ll l, ll r, ll ql, ll qr){
	if(ql <= l && r <= qr)return nd[i];
	else if(ql > r || l > qr) return 0;
	else{
		ll m = (l + r)/2;
		return query(2*i, l, m, ql, qr) + query(2*i + 1, m + 1, r, ql, qr);
	}
}

ll n;
ll c[MAXN];

signed main(){
	fastio;
	cin>> n;
	frr(i, n) cin >> c[i];
	build(1, 1, n);
	vector<pii> v;
	frr(i, n) v.pb({c[i], i});
	sort(all(v));

	ll maior = v[0].s;

	ll ans = 0;
	for(auto p : v){
		ll i = p.s;
		update(1, 1, n, i, -1);
	
		ans += min(query(1, 1, n, 1, i), query(1, 1, n, i, n));
	}
	cout << ans << endl;
}
