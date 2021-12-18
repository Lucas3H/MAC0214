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
ll a[MAXN], b[MAXN], c[MAXN];
ll ans = 0;

signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> a[i];
	if(a[0] < 0) b[0] = a[0], c[0] = 0;
	else b[0] = 0, c[0] = a[0];
	ans = abs(a[0]);
	//cout << b[0] << " " << c[0] << endl;
	frr(i, n - 1){
		b[i] = b[i - 1], c[i] = a[i] - b[i];
		if(c[i] > c[i - 1]){
			c[i] = c[i - 1], b[i] = a[i] - c[i];
		}

		ans += abs(b[i]) + abs(c[i]);
		//cout << b[i] << ' ' << c[i] << endl;
	}
	cout << ans << endl;
}
