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
#define INF 2000000000000000000

set<ll> a, neg;
ll n, sum = 0;


ll solve(ll x, ll y){
	auto it = a.lower_bound(x);
	ll ans = INF;
	if(it != a.end()){
		ans = min(max((ll)0, y - sum + *it), ans);
	}
	it = neg.lower_bound(-x);
	if(it != neg.end()){
		ll aux = -(*it);
		ans = min(max(y - sum + aux, (ll)0) + max(x - aux, (ll)0), ans);
	}
	return ans;
}

signed main(){
	fastio;
	cin >> n;
	fr(i, n){
		ll x;
		cin>> x;
		a.insert(x);
		neg.insert(-x);
		sum += x;
	}

	ll x, y, m;
	cin >> m;
	fr(i, m){
		cin >> x>> y;
		cout << solve(x, y) << endl;
	}
}
