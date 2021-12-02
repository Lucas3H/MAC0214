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

ll dp[2*MAXN];
vector<pii> start[MAXN];
ll a, t;

signed main(){
	fastio;
	cin >> a >> t;
	fr(i, a){
		ll h, d, n;
		cin >> h >> d >> n;
		fr(j, n){
			ll tempo;
			cin >> tempo;
			start[tempo].pb({h, d});
		}
	}

	ll ans = 0;
	for(ll i = 0; i <= t; i++){
		ans = max(ans, dp[i]);
		for(auto x: start[i]){
			dp[i + x.s] = max(dp[i + x.s], ans + x.f);
		}
	}
	for(ll i = t + 1; i <= 2*t; i++) ans = max(ans, dp[i]);
	cout << ans << endl; 
}
