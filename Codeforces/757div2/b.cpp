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

#define MAXN 200010
#define MOD 1000000007
#define INF 2000000000000000100

ll n;
vector<pii> v;
ll ans[MAXN];

void solve(){
	v.clear();
	cin >> n;
	fr(i, n){
		ll x;
		cin >> x;
		v.pb({-x, i});
	}
	sort(all(v));
	ll sum = 0;
	for(ll i = 0; i < n; i+=2){
		ans[v[i].s] = i/2 + 1;
		sum += -v[i].f * (i/2 + 1);
		if(i < n - 1) 
			ans[v[i + 1].s] = -i/2 - 1, sum += -v[i + 1].f * (i/2 + 1);
	}
	cout << 2 * sum << endl;
	cout <<0 << " ";
	fr(i, n) cout << ans[i] << " ";
	cout << endl;
}

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--) solve();
}
