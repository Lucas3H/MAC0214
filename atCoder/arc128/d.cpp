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
#define MOD 998244353
#define INF 2000000000000000100

vector<pii> v;
ll n;
ll dp[MAXN];

ll solve(vector<ll> a){
	if(a.size() == 2) return 1;
	if(a.size() > 6){
		ll ans = 1;
		fr(i, a.size() - 2) ans = ans * 2 % MOD;
		return ans;
	}
	for(auto x: a) dp[x] = 0;
	dp[a[0]] = 1;
	ll tot = 1;
	for(ll i = 1; i < (ll)a.size() - 1; i++){
		ll aux = dp[a[i]];
		if(i > 1 && a[i - 2] == a[i] && a[i - 1] == a[i + 1]){
			dp[a[i]] = tot;
			tot = (tot + tot - aux + MOD) % MOD;
		}
		else{
			dp[a[i]] = (tot + dp[a[i]]) % MOD;
			tot = tot * 2 % MOD;
		}
	}
	return tot;
}

ll a[MAXN];

signed main(){
	fastio;
	cin >> n;
	frr(i, n) cin >> a[i];
	a[0] = a[1], a[n + 1] = a[n];
	ll i = 0;
	while(i <= n + 1){
		ll ini = i;
		while(i <= n + 1 && a[ini] == a[i]) i++;
		v.pb({a[ini], i - ini});
	}

	i = 0;
	ll ans = 1;
	while(i < (int)v.size() - 1){
		ll l = i, r = i + 1;
		while(r < (int)v.size() && v[r].s == 1) r++;
		vector<ll> aux;
		for(ll i = l; i <= r; i++){
			aux.pb(v[i].f);
		}
		ans = ans * solve(aux) % MOD;
		i = r;
	}
	cout << ans << endl;
}
