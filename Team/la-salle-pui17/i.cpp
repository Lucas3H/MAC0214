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

ll h[MAXN];
ll n;
vector<pii> v;

signed main(){
	fastio;
	cin >> n;
	frr(i, n) cin >> h[i];
	frr(i, n - 1){	
		v.pb({(abs(h[i + 1] + h[i]) - abs(h[i + 1] - h[i])), i});
	}
	v.pb({0, n});
	sort(all(v));
	ll l = v[0].s, r = v[1].s;
	if(v[1].f <= 0){
		if(l > r) swap(l, r);
		for(ll i = l + 1; i <= r; i++) h[i] *= -1;
	}
	
	//frr(i, n) dbg(h[i]);
	ll ans = 0;
	frr(i, n - 1){
		ans += abs(h[i + 1] - h[i]);
	}
	cout << ans << endl;

}
