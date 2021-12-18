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

ll nd[4*MAXN], lz[4*MAXN];
ll v[MAXN];

void build(ll i, ll l, ll r){
	if(l == r) nd[i] = v[l];
	else{
		ll m = (l + r)/2;
		build(2*i, l, m);
		build(2*i + 1, m + 1, r);
		nd[i] = nd[2*i] + nd[2*i + 1];
	}
}

void push(ll i, ll l, ll r){
	if(lz[i] != 0){
		nd[i] += lz[i] *(r - l + 1);
		if(l < r) lz[2*i] += lz[i], lz[2*i + 1] += lz[i];
		lz[i] = 0;
	}
}

void update(ll i, ll l, ll r, ll ql, ll qr, ll val){
	push(i, l, r);
	if(ql <= l && r <= qr){
		lz[i] += val;
		push(i, l, r);
	}
	else if(ql > r || l > qr) return;
	else{
		ll m = (l + r)/2;
		update(2*i, l, m, ql, qr, val);
		update(2*i + 1, m + 1, r, ql, qr, val);
		nd[i] = nd[2*i] + nd[2*i + 1];
	}
}

ll query(ll i, ll l, ll r, ll ql, ll qr){
	push(i, l, r);
	if(ql <= l && r <= qr) return nd[i];
	else if(ql > r || l > qr) return 0;
	else{
		ll m = (l + r)/2;
		return query(2*i, l, m, ql, qr) + query(2*i + 1, m + 1, r, ql, qr);
	}
}

ll n;
ll s_cai = 0, s_sobe = 0;

void process(ll l, ll r, ll val){
	if(l > 1){
		ll a = query(1, 1, n, l - 1, l - 1), b = query(1, 1, n, l, l);
		if(a < b) s_sobe -= b - a;
		else s_cai -= a - b;
	}
	if(r < n){
		ll a = query(1, 1, n, r, r), b = query(1, 1, n, r + 1, r + 1);
		if(a < b) s_sobe -= b - a;
		else s_cai -= a - b;
	}

	update(1, 1, n, l, r, val);

	if(l > 1){
		ll a = query(1, 1, n, l - 1, l - 1), b = query(1, 1, n, l, l);
		if(a < b) s_sobe += b - a;
		else s_cai += a - b;
	}
	if(r < n){
		ll a = query(1, 1, n, r, r), b = query(1, 1, n, r + 1, r + 1);
		if(a < b) s_sobe += b - a;
		else s_cai += a - b;
	}
}

ll get(ll x){
	if(x < 0) return x/2;
	else return (x + 1)/2;
}

signed main(){
	fastio;
	cin >> n;
	frr(i, n) cin >> v[i];
	build(1, 1, n);
	frr(i, n - 1){
		if(v[i] < v[i + 1]) s_sobe += v[i + 1] - v[i];
		else s_cai += v[i] - v[i + 1];
	}

	cout << max(get(query(1, 1, n, 1, 1) + s_sobe), get(query(1, 1, n, n, n) + s_cai)) << endl;

	ll q;
	cin >> q;
	while(q--){
		ll l, r, val;
		cin >> l >> r >> val;
		process(l, r, val);
		//dbg(query(1, 1, n, 1, 1));

		cout << max(get(query(1, 1, n, 1, 1) + s_sobe), get(query(1, 1, n, n, n) + s_cai)) << endl;
	}
}
