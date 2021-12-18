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

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--){
		ll k, x;
		cin >> k >> x;

		ll l = 0, r = k + 1, m;
		while(l < r - 1){
			m = (l + r)/2;

			if(m * (m + 1) / 2 < x) l = m;
			else r = m;
		}
		if(r < k + 1) {
			cout << r << endl;
			continue;
		}

		x -= k * (k + 1)/2;
		l = k, r = 2*k - 1, m;

		while(l < r - 1){
			m = (l + r)/2;
			ll d = 2 * k - m;
			if(k * (k - 1) / 2 - d * (d - 1) / 2 < x) l = m;
			else r = m;
		}

		cout << r << endl;
	}
}
