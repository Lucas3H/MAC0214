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
#define MOD 1000000007
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

ll put[2 * MAXN], rem[2 * MAXN];
ll m, maximo = 0, qtd = 1;

ll inv2 = 1;

ll fat[MAXN];

ll interval(ll l, ll r){
	if(l > r) return 0;
	r = r % MOD, l = l % MOD;
	ll ret = r * (r + 1) % MOD * inv2 % MOD;
	ll ret2 = l * (l - 1) % MOD * inv2 % MOD;
	return (ret - ret2 + MOD) % MOD;
}

signed main(){
	fastio;
	fat[0] = 1;
	frr(i, MAXN - 1) fat[i] = fat[i - 1] * i % MOD;
	inv2 = fastxp(2, MOD - 2);

	cin >> m;
	ll sum = 0;
	frr(i, m){
		ll x;
		cin >> x;
		sum += x;
		put[x - 1 + MAXN]++;
		rem[-x + 1 + MAXN]++;
	}

	ll v[2] = {0, 0};
	for(ll i = 2 * MAXN - 1; i >= 0; i--){
		ll cur = i%2;
		v[cur] += put[i];
		qtd = qtd * fat[v[cur]] % MOD;
		maximo = (maximo + (i - MAXN) * interval(sum - v[cur] + 1, sum) % MOD + MOD) % MOD;
		//dbg(v[cur]);
		sum -= v[cur];

		v[cur] -= rem[i];
	}

	cout << maximo << " " << qtd << endl;
}
