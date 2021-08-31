#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 200010
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


ll fat[MAXN];

ll bin(ll a, ll b){
	if(b > a) return 0;
	ll ret = fat[a] * fastxp(fat[b], MOD - 2) % MOD;
	return ret * fastxp(fat[a - b], MOD - 2) % MOD;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	fat[0] = 1;
	frr(i, MAXN - 1) fat[i] = fat[i-1] * i % MOD;

	while(t--){
		ll n, k;
		cin >> n >> k;
		ll empate = 0;
		for(int i = 0; i < n; i += 2) empate = (empate + bin(n, i)) % MOD;
		if(n%2 == 1) {
			empate++;
			cout << fastxp(empate, k) << endl;
			continue;
		}

		ll ans = 0, part = 1;
		fr(i, k){
			ans += part * fastxp(2, (k - 1 - i) * n);
			ans = ans % MOD;
			part = part * empate % MOD;
		}

		cout<< (ans + part) %MOD << endl;
	}
}
