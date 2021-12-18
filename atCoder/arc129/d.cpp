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

ll a[MAXN];
ll n;

ll d[MAXN];

signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> a[i];

	d[0] = 0;
	ll sum = 0;
	frr(i, n - 1){
		d[i] = d[i - 1] + a[i];
		sum += d[i];
	}

	if(sum%n != 0){
		cout << -1 << endl;
		return 0;
	}

	ll val = (-sum) / n;
	fr(i, n) a[i] = val + d[i];

	sum = 0;
	ll minimo = 0;
	frr(i, n - 1){
		d[i] = d[i - 1] + a[i];
		sum += d[i];
		minimo = min(minimo, d[i]);
	}
	cout << -n * minimo + sum << endl;
}
