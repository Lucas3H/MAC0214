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

#define MAXN 1000010
#define MOD 1000000007
#define INF 2000000000000000100

ll ans[MAXN];
ll p[MAXN];

void solve(ll pos){
	ll val = (p[pos] - ans[pos] + MOD) % MOD;
	if(pos == 1) val = 2;

	for(ll i = 2 * pos; i < MAXN; i += pos){
		ans[i] = (ans[i] + val) % MOD;
	}
}

signed main(){
	fastio;
	p[0] = 1;
	frr(i, MAXN - 1) p[i] = p[i - 1] * 2 %MOD;
	ans[1] = 2;
	frr(i, MAXN - 1) solve(i);

	ll t;
	cin >> t;

	while(t--){
		ll n;
		cin >> n;
		if(n == 1) cout << 0 << endl;
		else cout<< ans[n] << endl;
	}

}
