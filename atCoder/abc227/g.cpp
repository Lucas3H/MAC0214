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

#define MAXN 1000010
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

ll np[MAXN];
vector<ll> p;

void sieve(){
	for(ll i = 2; i < MAXN; i++){
		if(!np[i]){
			p.pb(i);
			for(ll j = 2 * i; j < MAXN; j += i) np[j] = 1;
		}
	}
}

ll np_interval[MAXN];
vector<ll> sieve_interval(ll a, ll b){
	vector<ll> v;
	for(ll i = a; i <= b; i++) v.pb(i);
	vector<ll> ret;
	for(auto x: p){
		ret.pb(0);
		ll ini = (x - a%x) % x;
		while(ini < v.size()){
			while(v[ini]%x == 0) {
				ret.back()++;
				v[ini] /= x;
			}
			ini += x;
		}
	}
	ret.pb(0);
	for(auto x : v) if(x > 1) ret.back()++; 
	return ret;
}

ll solve(ll k, ll n){
	vector<ll> num = sieve_interval(n - k + 1, n);
	ll tot_primes = num.back();
	num.pop_back();
	vector<ll> den = sieve_interval(1, k);
	den.pop_back();
	fr(i, num.size()) {
		// if(num[i] < den[i]) {
		// 	dbg(p[i]);
		// 	dbg(den[i]);
		// 	dbg(num[i]);
		// }
		num[i] -= den[i];
	}
	ll ans = fastxp(2, tot_primes);
	fr(i, num.size()) {
		ans = ans * (num[i] + 1) % MOD; 
	}
	return ans;
}

signed main(){
	fastio;
	sieve();
	ll n, k;
	cin >> n >> k;
	if(k > n - k) k = n - k;
	if(k == 0) cout << 1 << endl;
	else cout << solve(k, n) << endl;
}
