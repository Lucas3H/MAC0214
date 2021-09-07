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
typedef deque<deque<ll>> matrix;

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
#define INF 1000000000000000100

namespace NTT {
    const long long mod = 998244353;
    const long long root = 15311432;
    const long long root_1 = 469870224;
    const long long root_pw = 1 << 23;

    ll fastxp(ll n, ll e){
	    ll ans = 1, pwr = n;
	    while(e){
	        if(e%2)  ans = ans * pwr % MOD;
	        e /= 2;
	        pwr = pwr * pwr % MOD;
	    }
	    return ans % MOD;
	}

    void fft(deque<long long> & a, bool invert) {
        long long n = a.size();

        for (long long i = 1, j = 0; i < n; i++) {
            long long bit = n >> 1;
            for (; j & bit; bit >>= 1)
                j ^= bit;
            j ^= bit;

            if (i < j)
                swap(a[i], a[j]);
        }

        for (long long len = 2; len <= n; len <<= 1) {
            long long wlen = invert ? root_1 : root;
            for (long long i = len; i < root_pw; i <<= 1)
                wlen = (long long)(1LL * wlen * wlen % mod);

            for (long long i = 0; i < n; i += len) {
                long long w = 1;
                for (long long j = 0; j < len / 2; j++) {
                    long long u = a[i+j], v = (long long)(1LL * a[i+j+len/2] * w % mod);
                    a[i+j] = u + v < mod ? u + v : u + v - mod;
                    a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                    w = (long long)(1LL * w * wlen % mod);
                }
            }
        }

        if (invert) {
            long long n_1 = fastxp(n, mod - 2);
            for (long long & x : a)
                x = (long long)(1LL * x * n_1 % mod);
        }
    }
 
    deque<long long> multiply(deque<long long> &a, deque<long long> &b) {
        long long sz = a.size() + b.size() - 1;
        long long logN = 0;
        while ((1 << logN) < sz) logN++;

        deque<long long> aa(1 << logN, 0), bb(1 << logN, 0);

        for (long long i = 0; i < a.size(); i++) aa[i] = a[i];
        for (long long i = 0; i < b.size(); i++) bb[i] = b[i];

        fft(aa, 0), fft(bb, 0);

        for (long long i = 0; i < aa.size(); i++) aa[i] = aa[i] * bb[i] % mod;

        fft(aa, 1);
        return aa;
    }
};

void solve(deque<ll> & v){
	if(v.size() == 1) {
		v.push_front((ll)1);
		return;
	}

	deque<ll> u;
	long long tamU = v.size()/2;
	long long tamV = v.size() - tamU;
	fr(i, tamU) u.pb(v.back()), v.pop_back();
	solve(u);
	solve(v);
	u.resize(tamU + 1);
	v.resize(tamV + 1);

	v = NTT::multiply(u, v);
	fr(i, v.size()) v[i] = v[i]%MOD;
}

ll fat[MAXN];
ll n;
ll a[MAXN];

deque<ll> v;

ll fastxp(ll n, ll e){
    ll ans = 1, pwr = n;
    while(e){
        if(e%2)  ans = ans * pwr % MOD;
        e /= 2;
        pwr = pwr * pwr % MOD;
    }
    return ans;
}


signed main(){
	fastio;
	long long t;
	cin >> t;

	fat[0] = 1;
	frr(i, MAXN - 1) fat[i] = fat[i-1] * i % MOD; 

	while(t--){	

		v.clear();
		cin >> n;
		frr(i, n) cin >> a[i], v.pb(a[i]);
		solve(v);

		ll num = 0;
		frr(i, n){
			ll part = (ll)v[i] * fat[i] % MOD;
			part = part * fat[n - i] % MOD;
			num = (num + part) % MOD;
		}

		cout << num * fastxp(fat[n], MOD - 2) % MOD << '\n';
	}
}