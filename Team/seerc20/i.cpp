#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = (ll)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_ll_distribution<ll>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 10000010
#define MOD 1000000007
#define INF 2000000000000000100

ll dp1[MAXN], dp2[MAXN];
ll n;

signed main(){
	fastio;
	cin >> n;
	if(n == 1  || n == 2){
		cout << n << endl;
		return 0;
	}

	dp1[2] = 1;

	for(ll i = 2; i <= n; i++){
		for(ll j = 2 * (i - 1); j <= n; j += (i - 1)){
			dp1[j] = (dp1[j] + dp1[i]) % MOD;
			dp1[j + 1] = (dp1[j + 1] + dp1[i]) % MOD;
			dp1[j + 2] = (dp1[j + 2] + dp1[i]) % MOD;
		}
		dp2[i + 1] = (dp1[i] + dp2[i]) % MOD;
		cout << dp1[i] << " " << dp2[i] << endl;
	}
	//	cout << dp1[n] << " " << dp2[n] << endl;

	cout << n * (dp1[n] + dp2[n]) % MOD%MOD << endl;
}
