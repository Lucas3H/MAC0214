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

#define MAXN 300010
#define MOD 1000000007
#define INF 1000000000000000100

ll fr[MAXN];
ll acu[MAXN], acu_f[MAXN];
ll n, k;

ll solve_small(ll x){
	ll sum = 0, tot = n;
	frr(i, MAXN - 1){
		if(i%x == 0) tot-=fr[i];
		sum += i%x * fr[i];
	}
	return x*tot - sum;
}

ll solve_large(ll x){
	ll sum = acu[x-1], tot = acu_f[x-1];


	ll it = 1;
	while(it*x < MAXN){
		ll nxt = min((it + 1)*x, (ll)MAXN);

		sum += acu[nxt - 1] - acu[it*x] - (acu_f[nxt - 1] - acu_f[it*x])*it*x;
		tot += acu_f[nxt - 1] - acu_f[it*x];

		it++;
	}
	// 	dbg(sum);
	// dbg(tot);
	return x*tot - sum;
}


signed main(){
	fastio;
	cin >> n >> k;
	fr(i, n){
		ll a;
		cin >> a;
		fr[a]++;
	}
	frr(i, MAXN - 1) {
		acu[i] = acu[i-1] + fr[i]*i;
		acu_f[i] = acu_f[i-1] + fr[i];
	}

	//dbg(solve_large(30178));
	
	ll it = 2;
	ll ans = 1;
	while(it * it < MAXN){
		if(solve_small(it) <= k) ans = it;
		it++;
	}

	while(it < MAXN){
		if(solve_large(it) <= k) ans = it;
		it++;
	}

	if(k + acu[MAXN-1] >= n*(MAXN - 1)){
		ans = (k + acu[MAXN-1])/n;
	}
	cout << ans << endl;
}
