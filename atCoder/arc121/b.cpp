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
#define MOD 1000000007
#define INF 2000000000000000100

vector<pii> d[3];
ll n;
ll nearest(ll a, ll b){
	ll ret = INF;
	vector<array<ll, 3>> v;
	for(auto x: d[a]) v.pb({x.f, x.s, 0});
	for(auto x: d[b]) v.pb({x.f, x.s, 1});
	sort(all(v));

	fr(i, (ll)v.size() - 1){
		if(v[i][2] != v[i + 1][2]){
			ret = min(ret, v[i + 1][0] - v[i][0]);
		}
	}

	return ret;
}



signed main(){
	fastio;
	cin >> n;
	frr(i, 2*n) {
		ll a;
		char c;
		cin >> a >> c;
		if(c == 'R') d[0].pb({a, i});
		else if(c == 'B') d[1].pb({a, i});
		else d[2].pb({a, i});
	}
	sort(all(d[0])), sort(all(d[1])), sort(all(d[2]));

	if(d[0].size()%2 == 0 && d[1].size()%2 == 0 && d[2].size()%2 == 0){
		cout << 0 << endl;
		return 0;
	}
	else if(d[1].size()%2 == 0) swap(d[0], d[1]);
	else if(d[2].size()%2 == 0) swap(d[0], d[2]);

	ll ans = INF;
	ans = min(ans, nearest(1, 2));
	ans = min(ans, nearest(0, 2) + nearest(0, 1));

 	cout<< ans << endl;
}
