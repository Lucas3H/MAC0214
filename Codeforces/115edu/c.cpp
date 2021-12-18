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
ll a[MAXN];
map<ll, ll> f;

void solve(){
	f.clear();
	cin >> n;
	ll sum = 0;
	fr(i, n){
		cin >> a[i];
		sum += a[i];
	}

	ll g = __gcd(sum, n);
	sum /= g;
	if(n > 2 * g){
		cout << 0 << endl;
		return;
	}
	if(n == 2 * g){
		fr(i, n) {
			a[i] += a[i];
		}
	}
	fr(i, n) f[a[i]]++;

	ll ans = 0;
	fr(i, n){
		if(a[i] > sum){
			ans += f[sum - (a[i] - sum)];
		}
		if(a[i] < sum){
			ans += f[sum + (sum - a[i])];
		}
	}
	ans /= 2;
	ans += f[sum] * (f[sum] - 1) / 2;
	cout << ans << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		solve();
	}
}
