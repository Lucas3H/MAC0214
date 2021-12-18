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

vector<int> val[MAXN];
ll n;
ll a[MAXN];

void build(int ind){
	int i;
	for(i = 1; i * i <= ind; i++){
		val[ind].pb(i);
	}

	for(; i>=1; i--){
		if(val[ind].back() < (ind - 1) / i + 1)
			val[ind].pb((ind - 1) / i + 1);
	}
}

ll ans;
vector<pii> dp;

void solve(ll x, ll ind){
	vector<pii> aux;
	ll itDP = (ll)dp.size() - 1;

	for(ll itVal = (ll)val[x].size() - 1; itVal >= 0; itVal--){
		ll sum = 0;
		while(itDP >= 0 && dp[itDP].f >= val[x][itVal]){
			sum += dp[itDP].s;
			itDP--;
		}
		ans = (ans + sum * ((x - 1)/val[x][itVal]) % MOD * ind) % MOD;
		if(x%val[x][itVal] == 0) aux.pb({val[x][itVal], sum});
		else aux.pb({val[x][itVal] - 1, sum});
	}

	reverse(all(aux));
	if(aux.back().f == x) aux.back().s++;
	else aux.pb({x, 1});

	dp = aux;
}

signed main(){
	fastio;
	frr(i, MAXN - 1) build(i);
	ll t;
	cin >> t;

	while(t--){
		cin >> n;
		frr(i, n) cin >> a[i];
		dp.clear();
		ans = 0;
		dp.pb({a[n], 1});
		for(ll i = n - 1; i >= 1; i--){
		//	dbg(ans);
			solve(a[i], i);
		}

		cout << ans %MOD<< endl;
	}
}
