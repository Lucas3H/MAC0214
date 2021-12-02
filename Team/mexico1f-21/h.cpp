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
#define MOD 12582917
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

ll dp[MOD + 1];
ll h[MAXN];
ll p2[MAXN], p2i[MAXN];
ll n, b;
string s;

ll Hash(ll l, ll r){
	return (h[r] - h[l - 1] + MOD) * p2i[l - 1] % MOD;
}

ll guarda[MAXN], val[MAXN];
ll testa(ll tam){
	frr(i, n) guarda[i] = 0;
	ll ans = 0;	
	for(ll i = tam; i <= n; i++){
		val[i] = Hash(i - tam + 1, i);
		guarda[i] = dp[val[i]] + 1;
		dp[val[i - tam + 1]] = max(dp[val[i - tam + 1]], guarda[i - tam + 1]);
		ans = max(ans, guarda[i]);
	}
	frr(i, n) dp[val[i]] = 0;

	return n - ans * tam + ans;
}

void build(){
	p2[0] = p2i[0] = 1;
	p2[1] = 2;
	p2i[1] = fastxp(2, MOD - 2);
	for(ll i = 2; i < MAXN; i++){
		p2[i] = p2[i - 1] * 2 % MOD;
		p2i[i] = p2i[i - 1] * p2i[1] % MOD;
	}
	cin >> b;
	cin >> s;
	n = s.size();
	frr(i, n){
		h[i] = (h[i - 1] + (ll)(s[i - 1] - '0') * p2[i - 1]) % MOD;
	}
}

signed main(){
	fastio;
	build();
	ll ans = n;
	frr(i, b){
		//dbg(testa(i));
		ans = min(ans, testa(i));
	}
	cout << ans << endl;
}
