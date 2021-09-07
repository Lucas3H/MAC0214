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

ll n, k;

vector<ll> rep(ll x){
	vector<ll> ret;
	while(x){
		ret.pb(x%k);
		x /= k;
	}
	return ret;
}

ll rep(vector<ll> x){
	ll ans = 0;
	frm(i, x.size()){
		ans *= k;
		ans += x[i];
	}
	return ans;
}

ll inv(ll x){
	vector<ll> v = rep(x);
	fr(i, v.size()) v[i] = (k - v[i]) % k;
	return rep(v);
}

ll sum(ll a, ll b){
	vector<ll> v1 = rep(a), v2 = rep(b);
	while(v1.size() < v2.size()) v1.pb(0);
	while(v1.size() > v2.size()) v2.pb(0);
	fr(i, v1.size()) v1[i] = (v1[i] + v2[i]) % k;
	return rep(v1);
}


signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--){
		cin >> n >> k;
		ll r;
		for(ll i = n - 1 ; i >= 0; i--){
			if((n - i)%2 == 0) cout << sum(inv(i), (i+1)%n) << endl;
			else cout << sum(i, inv((i+1)%n)) << endl;
			cin >> r;
			if(r == 1) break;
		}
	}
}