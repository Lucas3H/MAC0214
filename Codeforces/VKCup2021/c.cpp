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

#define MAXN 400010
#define MOD 1000000007
#define INF 2000000000000000100

ll n;
ll a[MAXN], b[MAXN];
ll ac[MAXN], bc[MAXN];

signed main(){
	fastio;

	ll t;
	cin >> t;

	while(t--){
		cin >> n;
		frr(i, n) cin >> a[i];
		frr(i, n) cin >> b[i], b[i] = - b[i];

		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		frr(i, n) ac[i] = a[i] + ac[i - 1], bc[i] = b[i] + bc[i - 1];

		ll ans = n;
		while(true){
			ll tot = ans - ans/4;
			ll pa = ac[ans] - ac[ans - tot];
			ll pb = -bc[tot];

			if(pa >= pb) break;
			ans++;
			ac[ans] = ac[ans - 1] + 100;
			bc[ans] = bc[ans - 1];
		}

		cout << ans - n << endl;
	}
}
