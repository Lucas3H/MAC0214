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

ll fastxp(ll n, ll e){
    ll ans = 1, pwr = n;
    while(e){
        if(e%2)  ans = ans * pwr % MOD;
        e /= 2;
        pwr = pwr * pwr % MOD;
    }
    return ans;
}

ll n;
ll a[20], win[20][20], dp[1 << 14];

ll win_all(ll m1, ll m2){
	ll ret = 1;
	fr(i, n) if((1 << i) & m1) fr(j, n) if((1 << j) & m2){
		ret = ret * win[i][j] % MOD;
	}
	return ret;
}

signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >>a[i];
	
	fr(i, n) fr(j, n) 
		win[i][j] = a[i] * fastxp(a[i] + a[j], MOD - 2) % MOD;	

	ll ans = 0;
	fr(mask, (1 << n)) {
		dp[mask] = 1;
		for(ll i = mask&(mask-1); i > 0; i = (i-1) & mask){
			dp[mask] = (dp[mask] - win_all(i, mask ^i) * dp[i]) % MOD;
		}
		dp[mask] = (dp[mask] + MOD) % MOD;
		ans = (__builtin_popcount(mask) * dp[mask] % MOD * win_all(mask, ((1 << n) - 1)^mask) + ans) % MOD;
	}

	cout<< ans << endl;
}
