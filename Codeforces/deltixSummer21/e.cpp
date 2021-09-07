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

ll val[MAXN];
ll n, q;
	
struct SEG{
	ll nd[4*MAXN];
	ll t = 0;
	inline ll op(ll x, ll y) {return (t == 0) ? max(x, y) : min(x, y);}
	void build(ll i, ll l, ll r){
		if(l == r) nd[i] = val[l];
		else{
			ll m = (l + r)/2;
			build(2*i, l, m), build(2*i + 1, m + 1, r);
			nd[i] = op(nd[2*i], nd[2*i+1]);
		}
	}

	ll query(ll i, ll l, ll r, ll ql, ll qr){
		if(l > qr || ql > r) return (t == 0) ? -INF : INF;
		else if(ql <= l && r <= qr) return nd[i];
		else{
			ll m = (l + r)/2;
			return op(query(2*i, l, m, ql, qr), query(2*i + 1, m + 1, r, ql, qr));
		}
	}
};

ll a[MAXN], b[MAXN];
SEG minimo, maximo;

signed main(){
	fastio;
	cin >> n >> q;
	frr(i, n) cin >> a[i];
	frr(i, n) cin >> b[i], val[i] = b[i] - a[i];
	frr(i, n) {
		val[i] += val[i-1];
	}
	minimo.t = 1;
	minimo.build(1, 1, n), maximo.build(1, 1, n);

	while(q--){
		ll l, r;
		cin >> l >> r;

		// dbg(minimo.query(1, 1, n, l, r)); 
		// dbg(val);
		if(minimo.query(1, 1, n, l, r) < val[l-1] || val[l-1] != val[r]){
			cout << -1 << '\n';
			continue;
		}

		cout << maximo.query(1, 1, n, l, r) - val[l-1] << '\n';
	}
}
