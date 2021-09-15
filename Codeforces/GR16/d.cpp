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

#define MAXN 310
#define MOD 1000000007
#define INF 1000000000000000100

ll a[MAXN*MAXN];
ll n, m;
pii s[MAXN][MAXN];

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--){
		cin >> n >> m;
		fr(i, n*m) cin >> a[i];
		vector<pii> v;
		fr(i, n*m) v.pb({a[i], i});
		sort(all(v));
		fr(i, n) fr(j, m) s[i][j] = v[m*i + j];
		//for(auto x: v) cout << -x.s << endl;
		ll ans = 0;
		fr(i, n){
			fr(j, m) s[i][j].s = -s[i][j].s;
			sort(s[i], s[i] + m);
			fr(j, m) fr(k, j) if(-s[i][k].s < -s[i][j].s) ans++;
		}
		cout << ans << endl;
	}
}
