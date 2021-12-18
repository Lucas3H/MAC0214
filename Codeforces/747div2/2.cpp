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
#define INF 2000000000000000100

ll fastxp(ll n, ll e){
    ll ans = 1, pwr = n;
    while(e){
        if(e%2)  ans = ans * pwr % MOD;
        e /= 2;
        pwr = pwr * pwr % MOD;
    }
    return ans % MOD;
}

ll k, n;
vector<pii> nd;

ll msb(ll x){
	ll ind = 0;
	while(x){
		x /= 2;
		ind++;
	}
	return ind;
}

ll lca(ll a, ll b){
	ll ba = msb(a), bb = msb(b);
	fr(i, ba - bb) a /= 2;
	fr(i, bb - ba) b /= 2;

	while(a != b){
		a /= 2;
		b /= 2;
	}
	return a;
}

array<ll, 6> dp[MAXN];
map<ll, array<ll, 6>> m;
vector<ll> cur;
ll tot = 0;

void solve(){
	ll davez = 0, val = -1;
	fr(i, cur.size() - 1){
		if(lca(cur[i], cur[i + 1]) > val){
			val = lca(cur[davez], cur[davez + 1]);
			davez = i;
		}
	}

	ll a = cur[davez], b = cur[davez + 1];
	ll ha = msb(a), hb = msb(b), h = msb(val);
	dp[0] = m[a];
	fr(i, ha - h){
		fr(j, 6){
			for(ll k = (j + 2) % 6; k != j; k = (k + 1)%6) 
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][k]) % MOD;
		}
	}
	m[val] = dp[ha - h];
	dp[0] = m[b];
	fr(i, hb - h){
		fr(j, 6){
			for(ll k = j + 2; k != j; k = (k + 1)%6) 
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][k]) % MOD;
		}
	}
	fr(i, 6) m[val][i] = m[val][i] * dp[hb - h][i] % MOD;
	cur[davez] = val;
	cur.erase(cur.begin() + davez + 1, cur.begin() + davez + 2);
	tot += ha + hb - h - 1;
}

signed main(){
	fastio;

	cin >> k >> n;
	fr(i, n){
		ll v;
		string s;
		cin >> v >> s;
		if(s == "white") nd.pb({v, 0});
		else if(s == "yellow") nd.pb({v, 1});
		else if(s == "green") nd.pb({v, 2});
		else if(s == "blue") nd.pb({v, 3});
		else if(s == "red") nd.pb({v, 4});
		else nd.pb({v, 5});
	}


 	db;
/*	for(auto x : nd){
		m[x.f][x.s] = 1;
 		cur.pb(x.f);
 	}
 	sort(all(cur));

 	while(cur.size() >= 2) solve();

 	ll ans = 0;
 	for(auto x : m[cur[0]]) ans = (ans + x) % MOD;

 	ans = ans * fastxp(4, (1 << k) - tot) % MOD;

 	if(cur[0] != 1) ans = ans * 6 % MOD;
 	else ans = ans * 4 % MOD;

 	cout << ans << endl;
 	*/
}
