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

#define MAXN 2000010
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

ll pwr[MAXN];
ll n, d, inv2= fastxp(2, MOD - 2);

signed main(){
	fastio;
	cin >> n >> d;
	pwr[0] = 1;
	frr(i, MAXN - 1) pwr[i] = pwr[i-1] * 2 % MOD;

	ll ans = 0, baixo = 0;
	for(ll i = n-1; i > d; i--){
		baixo = (baixo + pwr[i]) % MOD;
	}
	for(ll i = 0; i <= d/2; i++){
		ll resto = d - i;
		if(resto >= n) continue;
		baixo = (baixo + pwr[resto]) % MOD;
		//dbg(baixo);
		if(i == resto) ans = (ans + baixo * pwr[i - 1]% MOD) % MOD;
		else if(i == 0) ans = (ans + 2 * baixo) % MOD;
		else ans = (ans + 2 * baixo % MOD * pwr[i - 1] % MOD) % MOD;
	}
	cout << ans << endl;
}
