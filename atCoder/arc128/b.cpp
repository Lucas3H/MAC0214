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
#define MOD 1000000007
#define INF 2000000000000000100

ll solve(ll a, ll b, ll c){
	if((a - b)%3 != 0) return INF;
	if(a > b) swap(a, b);
	ll tot = 0;
	while(true){
		b -= a;
		c += 2*a;
		tot += a;
		a = 0;

		if(b == 0) break;
		ll part = min(c, b / 3);
		c -= part;
		b -= part;
		a += 2*part;
		tot+=part; 
	}

	return tot;
}

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--){
		ll a, b, c;
		cin >> a >> b >> c;
		ll ans = INF;
		ans = min(ans, solve(a, b, c));
		ans = min(ans, solve(a, c, b));
		ans = min(ans, solve(c, b, a));
		if(ans == INF) cout << -1 << endl;
		else cout << ans << endl;
	}
}
