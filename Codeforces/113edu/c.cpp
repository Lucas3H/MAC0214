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

#define MAXN 200010
#define MOD 998244353	
#define INF 1000000000000000100

ll n;
map<ll, ll> m;

ll fat[MAXN];

ll fastxp(ll n, ll e){
    ll ans = 1, pwr = n;
    while(e){
        if(e%2)  ans = ans * pwr % MOD;
        e /= 2;
        pwr = pwr * pwr % MOD;
    }
    return ans % MOD;
}

signed main(){
	fastio;
	fat[0] = 1;
	frr(i, MAXN - 1) fat[i] = fat[i-1] * i % MOD;
	ll t;
	cin >> t;
	while(t--){
		m.clear();
		cin >> n;
		ll maior = 0;
		fr(i, n){
			ll x;
			cin >> x;
			m[x]++;
			maior = max(maior, x);
		}

		if(m[maior] > 1) cout << fat[n] << endl;
		else if(m[maior - 1] == 0) cout << 0 << endl;
		else{
			cout << fat[n] * fastxp(m[maior-1] + 1, MOD - 2) % MOD * m[maior-1] % MOD << endl;
		}
	}
}
