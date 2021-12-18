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
#define MOD 998244353
#define INF 2000000000000000100

string s;
ll s1 = 0, sdp = 0, ans = 0, pwr2 = 1;

signed main(){
	fastio;
	cin >> s;
	s1 = sdp = ans = s[0] - '0';
	pwr2 = 2;

	frr(i, s.size() - 1){
		ll d = s[i] - '0';
		s1 = (10 * s1 + pwr2 * d) % MOD;
		ans = (sdp + s1) % MOD;
		sdp = (sdp + sdp + s1) % MOD;
		pwr2 = pwr2 * 2 % MOD;
		// dbg(ans);
		// dbg(s1);
	}
	cout << ans << endl;

}
