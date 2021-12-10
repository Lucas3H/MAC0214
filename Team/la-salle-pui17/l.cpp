#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

#define MAXN 100010
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

ll n, m;


signed main(){
	fastio;
	cin >> n >> m;
	if(n + m >= MOD){
		cout << 0 << endl;
		return 0;
	}

	ll cima = n + m;
	ll num = 1, den = 1;

	for(int i = 1; i < m; i++){
		num = cima * num % MOD;
		cima--;
		den = den * i % MOD;
	}

	ll ans1 = num * fastxp(den, MOD - 2) % MOD;
	num = cima * num % MOD;
	den = den * m % MOD;
	ll ans2 = num * fastxp(den, MOD - 2) % MOD;
	cout << (ans2 - ans1 + MOD) % MOD;
}
