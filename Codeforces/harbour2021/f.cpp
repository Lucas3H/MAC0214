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
#define RAIZ 2001
#define MOD 1000000007
#define INF 2000000000000000100

struct seg{
	ll n = MAXN;  // array size
	ll nd[2 * MAXN];

	void build() {  // build the tree
	    for (ll i = 2*MAXN-1; i >= 0; i--) nd[i] = 0;
	}

	void modify(ll p, ll val) {  // set val at position p
	    for (nd[p += n] += val; p > 1; p >>= 1) 
	        nd[p>>1] = nd[p] + nd[p^1];
	}

	ll query(ll l, ll r) {  // sum on llerval [l, r]
	    ll res = 0;
	    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
	        if (l&1) res += nd[l++];
	        if (r&1) res += nd[--r];
	    }
	    return res;
	}
};

seg tira, sum, fre;

ll n;
ll v[MAXN];

ll solve(ll x, ll ind){
	ll p = 0, i = 0;
	ll ret = (ind - 1) * x - tira.query(1, x);
	while(p < MAXN){
		ret += sum.query(p, min(p + x, (ll)MAXN) - 1) - i * x * fre.query(p, min(p + x, (ll)MAXN) - 1);
		tira.modify(p, i * x);
		tira.modify(min(p + x, (ll)MAXN - 1), -i * x);
		p+=x, i++;
	}
	sum.modify(x, x);
	fre.modify(x, 1);
	return ret;
}

signed main(){
	fastio;
	cin >> n;
	frr(i, n) cin >> v[i];
	sum.build(), tira.build(), fre.build();

	ll s = 0;
	frr(i, n){
		s += solve(v[i], i);
		cout << s << " ";
	}
	cout << endl;
}
