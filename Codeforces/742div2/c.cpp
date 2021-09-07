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
#define INF 1000000000000000100

ll solve(ll n, ll carry){
	if(n == 0 && carry > 0) return 0;
	if(n == 0) return 1;


	ll d = n%10;
	ll ans = 0;

	if(carry%2){
		ans += solve(n/10, carry/2 + 2) * (10 - d);
		ans += solve(n/10, carry/2) * d;
	}
	else{
		ans += solve(n/10, carry/2 + 2) * (9 - d);
		ans += solve(n/10, carry/2) * (d + 1);
	}

	//cout << n << ' ' << carry << " " << ans << endl;
	return ans;
}

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--){
		ll n;
		cin >> n;
		cout << solve(n, 0) - 2 << '\n';
	}
}
