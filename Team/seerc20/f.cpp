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

#define MAXN 3010
#define MOD 1000000007
#define INF 2000000000000000100

ll dp[MAXN][MAXN];
ll h[MAXN];
ll n;
ll l[MAXN], r[MAXN];

void build(){
	cin >> n;
	frr(i, n) cin >> h[i];
	frr(i, n){
		for(ll j = i - 1; j >= 1; j--) if(h[j] < h[i]) {
			l[i] = j;
			break;
		}
		for(ll j = i + 1; j <= n + 1; j++) if(h[j] < h[i]) {
			r[i] = j;
			break;
		}
	}
}

signed main(){
	fastio;
	build();
	dp[0][0] = 1;
	frr(i, n){
		ll sum = 0;
		fr(j, n + 1){
			sum = (sum + dp[i - 1][j]) % MOD;
			if(l[j] < i && i < r[j]) dp[i][j] = sum;
		}
	}
	ll ans = 0;
	fr(i, n + 1) ans = (ans + dp[n][i])%MOD;
	cout << ans << endl;
}
