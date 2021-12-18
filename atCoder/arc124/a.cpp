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

ll n, k;
pii pos[MAXN];

signed main(){
	fastio;
	cin >> n >> k;
	frr(i, k){
		char c;
		ll x;
		cin >> c >> x;
		if(pos[x].s != 0){
			cout << 0 << endl;
			exit (0);
		}
		if(c == 'L') pos[x] = {i, 1};
		else pos[x] = {i, 2};
	}

	ll tot = 0;
	frr(i, n) if(pos[i].s == 2) tot++;

	ll ans = 1;
	frr(i, n){
		if(pos[i].s == 1) tot++;
		else if(pos[i].s == 2) tot--;
		if(pos[i].s != 0) continue;

		ans = ans * tot % MOD;
	}
	cout << ans << endl;
}
