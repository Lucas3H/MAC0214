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

ll n, m;
pii p[MAXN];
ll a[MAXN], acu[MAXN];

ll bb(ll x){
	ll l = 0, r = m + 1, mid;
	while(l < r - 1){
		mid = (l + r)/2;
		if(a[mid] < x) l = mid;
		else r = mid;
	}
	return l;
}

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--){
		vector<pii> v;
		cin >> n >> m;
		frr(i, m){
			cin >> p[i].f >> p[i].s;
			a[i] = -p[i].f;
		}
		sort(a + 1, a + m + 1);
		frr(i, m) acu[i] = acu[i - 1] + a[i];

		ll ans = 0;
		frr(i, m){
			ll pos = bb(-p[i].s);
			if(p[i].f <= p[i].s){
				if(pos < n){
					ans = max(ans, -acu[pos] + p[i].f + p[i].s * (n - pos - 1));
				} 
			}
			else{
				if(pos <= n){
					ans = max(ans, -acu[pos] + p[i].s * (n - pos));
				} 
			}
		}
		if(n <= m) ans = max(ans, -acu[n]);

		cout << ans << endl;
 

	}
}
