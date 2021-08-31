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

#define mp make_pair
#define pq priority_queue

#define MAXN 200010
#define MOD 998244353
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

ll dp[MAXN], acu[MAXN], antes[MAXN], antes_edge[MAXN], finishes[MAXN];
ll x[MAXN], y[MAXN], s[MAXN];
vector<pii> v;
ll n;

ll get_antes(ll a){
	auto it = lower_bound(all(v), mp(y[a], -1ll));
	return (*it).s;
}

int main(){
	fastio;
	cin >> n;
	frr(i, n){
		cin >> x[i] >> y[i] >> s[i];
		v.pb({x[i], i});
	}

	sort(all(v));
	dp[1] = x[1] - y[1];
	acu[1] = dp[1];
	antes[1] = 0;
	antes_edge[1] = 0;
	finishes[1] = 1;

	for(ll i = 2; i <= n; i++){
		ll prv = get_antes(i);
		if(prv == i) finishes[i] = i;
		else finishes[i] = finishes[prv];
		
		antes_edge[i] = (antes_edge[prv] + x[prv] - y[i] + MOD) % MOD;
		dp[i] = acu[i-1] - acu[finishes[i]-1] - antes[prv] + antes_edge[i] + x[i] - x[finishes[i]];
		dp[i] = (dp[i]%MOD + MOD) % MOD;
		antes[i] = (antes[prv] + dp[i])%MOD;
		acu[i] = (dp[i] + acu[i-1]) % MOD;
		//cout << dp[i] << " " << prv << " " << acu[i-1] - acu[finishes[i]-1] << " " << antes[prv] << " " << antes_edge[i] << " " << x[i] - x[finishes[i]] << endl;
	}
	ll ans = 0;
	frr(i, n){
		if(s[i]) ans = (ans + dp[i]) % MOD;
	}
	cout << (ans + x[n] + 1) % MOD << endl;
}
