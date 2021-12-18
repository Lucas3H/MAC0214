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

#define MAXN 4000010
#define MOD 1000000007
#define INF 2000000000000000100

ll dp[MAXN];
ll sum = 0;
ll n, m;

signed main(){
	fastio;
	cin >> n >> m;

	dp[1] = 1;
	dp[2] = 2;
	for(ll i = 2; i <= n; i++){
		if(i > 2) dp[i] = (2 * dp[i - 1] + 1 + dp[i]) % m;
		for(ll j = 2 * i; j <= n; j += i){
			dp[j] = (dp[j] - dp[i - 1] + dp[i] + m) % m;
		}
	}
	cout << dp[n] << endl;
}
