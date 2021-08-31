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

ll srange(ll l, ll r){
	return r*(r+1)/2 - l*(l-1)/2;
}

ll n, k;
pq<pii> fila;
signed main(){
	fastio;
	cin >> n >> k;
	map<ll, ll> m;
	fr(i, n){
		ll a;
		cin >> a;
		m[a]++;
	}

	for(auto x: m) fila.push({x.f, x.s});
	fila.push({0, 0});
	ll ans = 0;
	while(k && fila.size() > 1){
		pii a = fila.top();
		fila.pop();
		pii b = fila.top();
		fila.pop();
		if(a.s*(a.f - b.f) <= k){
			k-= a.s*(a.f - b.f);
			ans += a.s*srange(b.f + 1, a.f);
			fila.push({b.f, a.s + b.s});
		}
		else{
			ll tot = k/(a.s);
			ans += a.s*srange(a.f - tot + 1, a.f);
			ans += k%a.s * (a.f - tot); 
			k = 0;
		}
	}


	cout << ans << endl;
}
