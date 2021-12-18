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

#define MAXN 101	
#define MOD 1000000007
#define INF 2000000000000000100

ll dp[MAXN][MAXN][MAXN];
ll bin[MAXN][MAXN], fat[MAXN];
ll p;
ll solve(ll n, ll k, ll m){
	ll & memo = dp[n][k][m];
	if(memo != -1) return memo;
	
	if(k > n - m + 1){
		if(k == 0) return memo = fat[n];
		else return memo = 0;
	}
	if(n < k) return memo = 0;
	if(n == 0) return memo = 1;
	if(m == 1){
		if(k > 1 || k == 0) return 0;
		else return fat[n];
	}
	memo = 0;

	frr(i, n){
		ll aux = 0;
		fr(j, k + 1) {
			aux = (aux + solve(i-1, j, m - 1) * solve(n - i, k - j, m - 1)) % p;

		}
		memo = (memo + aux * bin[n - 1][i - 1] % p) % p;
	//	dbg(memo);
	}
	//cout << n << " " << k << " " << m << " " << memo << endl;
	return memo;
}

signed main(){
	fastio;
	mem(dp, -1);
	ll n, m, k;
	cin >> n >> m >> k >> p;
	fat[0] = 1;
	frr(i, n) fat[i] = fat[i-1] * i % p;
	fr(i, n + 1){
		bin[i][0] = 1;
		frr(j, i){
			bin[i][j] = (bin[i - 1][j - 1] + bin[i - 1][j]) % p;
		}
	}
	cout << solve(n, k, m) << endl;

}
