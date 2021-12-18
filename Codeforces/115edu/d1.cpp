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
#define MOD 1000000007
#define INF 2000000000000000100

ll n;
vector<ll> topic[MAXN];
ll dif[MAXN];

ll solve(ll ind){
	ll sum = 0, ans = 0, t = 0;
	for(auto x: topic[ind]){
		ans += sum;
		ans += t * (dif[x] - 1);
		sum += dif[x] - 1;
		t++;
	}
	return ans;
}

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--){
		cin >> n;
		frr(i, n) topic[i].clear(), dif[i] = 0;
		
		frr(i, n){
			ll x, y;
			cin >> x >> y;
			topic[x].pb(y);
			dif[y]++;
		}
		ll ans = 0;
		frr(i, n) ans += solve(i);
		cout << n * (n - 1) * (n - 2) / 6 - ans << endl;
	}
}
