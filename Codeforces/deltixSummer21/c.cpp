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

ll n;
ll a[MAXN];

ll solve(ll ind){
	if(ind == n) return 0;
	stack<pii> vales;
	ll cur = 0;
	vales.push({0, 1});
	for(ll i = ind+1; i <= n; i+=2){
		cur -= a[i];
		if(vales.size() == 0) vales.push({cur, 1});
		else if(vales.top().f == cur) vales.top().s++;
		else if(vales.top().f > cur) vales.push({cur, 1});
		cur += a[i+1];
	}

	a[ind] = min(a[ind], -vales.top().f);

	ll ok = 0;
	while(vales.top().f + a[ind] < 0) {
		vales.pop();
		ok = 1;
	}

	ll ans = max((ll)vales.size() - 2 + ok, (ll)0);
	//dbg(ans);
	while(vales.size()){
		//dbg(vales.top().f);
		ans += a[ind] - vales.top().f;
		if(vales.top().f != 0) ans += vales.top().s;
		a[ind] = vales.top().f - 1;
		vales.pop();
	}
	//cout<< ind << " " << ans << endl;
	return ans;
}

signed main(){
	fastio;
	cin >> n;
	frr(i, n) cin >> a[i];
	ll ans = 0;
	for(ll i = 1; i <= n; i+= 2) ans += solve(i);
	cout << ans << endl;
}
