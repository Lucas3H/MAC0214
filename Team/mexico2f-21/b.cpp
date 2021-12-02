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
#define MOD 998244353
#define INF 2000000000000000100

ll fastxp(ll n, ll e){
    ll ans = 1, pwr = n;
    while(e){
        if(e%2)  ans = ans * pwr % MOD;
        e /= 2;
        pwr = pwr * pwr % MOD;
    }
    return ans % MOD;
}

ll fat[MAXN], acu[MAXN], p[MAXN];

void build(ll baldes, ll bolas){
	fat[0] = 1;
	frr(i, MAXN - 1) fat[i] = fat[i - 1] * i % MOD;
	ll den = 1;
	p[0] = 1;
	frr(i, bolas){
		den = den * baldes % MOD;
		p[i] = p[i - 1] * (baldes - 1) % MOD;
	}

	frr(i, bolas + 1){
		acu[i] = fat[bolas] * fastxp(fat[i - 1], MOD - 2) % MOD * fastxp(fat[bolas - i + 1], MOD - 2) % MOD;
		acu[i] = acu[i] * p[bolas - i + 1] % MOD * fastxp(den, MOD - 2) % MOD;
		acu[i] = (acu[i - 1] + acu[i]) % MOD;
	}
}

ll get_acu(ll l, ll r){
	return (acu[r + 1] - acu[l] + MOD) % MOD;
}

ll ans[10];

ll n, m;

void solve(ll x, ll d){
	ll lim = 1;
	while(d*lim - x <= m){
		ll l = max(d*lim - x, (ll)0), r = min((d + 1)*lim - 1 - x, m);
		if(0 <= l && l <= r){
			ans[d] = (ans[d] + get_acu(l, r)) % MOD;
		}
		lim *= 10;
	}
}

signed main(){
	fastio;
	cin >> n >> m;
	build(n, m);

	frr(i, n){
		ll a;
		cin >> a;
		frr(j, 9) solve(a, j);
	}
	frr(i, 9) cout << ans[i] << endl;
}
