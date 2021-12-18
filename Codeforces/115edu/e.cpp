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

#define MAXN 1010
#define MOD 1000000007
#define INF 2000000000000000100

/*
	0 começa pra direita e 1 começa pra baixo
*/
ll dp[2][MAXN][MAXN];
ll m[MAXN][MAXN];
ll R, C;
ll ans = 0;
bool inside(ll x, ll y){
	if(x >= 1 && x <= R && y >= 1 && y <= C) return true;
	else return false;
}

void update(ll r, ll c){
	while(r >= 1 || c >= 1){
		if(inside(r, c + 1)){
			ans -= dp[1][r][c + 1];
			if(m[r][c + 1]) dp[1][r][c + 1] = 0;
			else dp[1][r][c + 1] = dp[0][r + 1][c + 1] + 1;
			ans += dp[1][r][c + 1];
		}
		if(inside(r, c)){
			ans -= (dp[0][r][c] + dp[1][r][c]);
			if(m[r][c]) dp[0][r][c] = dp[1][r][c] = 0;
			else{
				dp[0][r][c] = dp[1][r][c + 1] + 1;
				dp[1][r][c] = dp[0][r + 1][c] + 1;
			}
			ans += dp[0][r][c] + dp[1][r][c];
		}
		if(inside(r, c - 1)) {
			ans -= dp[0][r][c - 1];
			if(m[r][c - 1]) dp[0][r][c - 1] = 0;
			else dp[0][r][c - 1] = dp[1][r][c] + 1;
			ans += dp[0][r][c - 1];
		}
		r--, c--;
	}

}

signed main(){
	fastio;
	ll q;
	cin >> R >> C >> q;
	frr(i, C) update(R, i);
	frr(i, R) update(i, C);
	ll tot = R * C;
	while(q--){
		ll x, y;
		cin >> x >> y;
		m[x][y] ^= 1;
		
		if(m[x][y]) tot--;
		else tot++;

		while(x < R && y < C){
			x++, y++;
		}
		update(x, y);
		// dbg(ans);
		// frr(i, R){
		// 	frr(j, C) cout << dp[0][i][j] << " ";
		// 	cout << endl;
		// }
		// frr(i, R){
		// 	frr(j, C) cout << dp[1][i][j] << " ";
		// 	cout << endl;
		// }
		cout << ans - tot << endl;
	}

}
