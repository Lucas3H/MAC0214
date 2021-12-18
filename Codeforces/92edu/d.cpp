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

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100

ll n, k;
pii a, b;

ll solve(ll cost){
	if(cost <= min(a.s, b.s) - max(a.f, b.f)) return 0;
	if(cost > (max(a.s, b.s) - min(a.f, b.f))){
		ll ans = abs(a.f - b.f) + abs(a.s - b.s);
		cost -= (max(a.s, b.s) - min(a.f, b.f));
		return ans + 2 * cost;
	}
	else return max(a.f, b.f) - min(a.s, b.s)  + cost;
}

void solve(){
	cin >> n >> k;
	cin >> a.f >> a.s >> b.f >> b.s;
	ll ans = INF;
	for(ll i = 1; i <= n; i++){
		ans = min(ans, k%i * solve(k / i + 1) + (i - k % i) * solve(k / i));
	}
	cout << ans << endl;
}

signed main(){
	fastio;

	ll t;
	cin >> t;
	while(t--) solve();
}
