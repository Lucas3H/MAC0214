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

#define MAXN 2010
#define MOD 1000000007
#define INF 2000000000000000100

ll dp[MAXN][MAXN][2];
vector<ll> out[MAXN];
ll ok[MAXN], sz[MAXN], p[MAXN], hp[MAXN];

ll n;

ll aux[MAXN][2];

void build(ll v){
	if(out[v].size() == 0){
		sz[v] = 1;
		dp[v][0][0] = hp[v];
		dp[v][1][1] = 0;
		return;
	}
	aux[0][0] = hp[v];
	aux[0][1] = 0;

	for(auto f : out[v]){
		fr(j, sz[v] + 1) fr(k, sz[f] + 1) dp[v][j + k][0] = dp[v][j + k][1] = INF;
		fr(j, sz[v] + 1) fr(k, sz[f] + 1){
			dp[v][j + k][0] = min(dp[v][j + k][0], aux[j][0] + dp[f][k][0] + hp[f]);
			dp[v][j + k][0] = min(dp[v][j + k][0], aux[j][0] + dp[f][k][1]);
			
			dp[v][j + k][1] = min(dp[v][j + k][1], aux[j][1] + dp[f][k][0]);
			dp[v][j + k][1] = min(dp[v][j + k][1], aux[j][1] + dp[f][k][1]);
			// cout << f << " " << j << " " << k << endl;
			// dbg(dp[f][k][1]);dbg(aux[j][1]);
			// dbg(dp[v][j + k][1]);
		}

		sz[v] += sz[f];
		fr(i, sz[v] + 1) fr(k, 2) aux[i][k] = dp[v][i][k];
	}

	//dbg(dp[v][0][0]);

	sz[v]++;
	for(ll i = sz[v]; i >= 1; i--) dp[v][i][1] = dp[v][i - 1][1];
	dp[v][0][1] = INF;
}

void solve(){
	cin >> n;
	frr(i, n) fr(j, n + 1) fr(k, 2) dp[i][j][k] = INF;
	frr(i, n) out[i].clear();
	frr(i, n) ok[i] = sz[i] = 0;
	frr(i, n - 1){
		cin >> p[i + 1];
		out[p[i + 1]].pb(i + 1);
		ok[p[i + 1]]++;
	}
	frr(i, n) cin >> hp[i];	

	fr(i, n + 1) fr(j, n + 1) fr(k, 2) dp[i][j][k] = INF; 

	queue<ll> fila;
	frr(i, n) if(ok[i] == 0) fila.push(i);

	while(fila.size()){
		ll davez = fila.front();
		fila.pop();
		build(davez);
		
		ok[p[davez]]--;
		if(ok[p[davez]] == 0) fila.push(p[davez]);
	}

	fr(i, n + 1) cout << min(dp[1][i][0], dp[1][i][1]) << ' ';
	// fr(i, n + 1) fr(j, n + 1) fr(k, 2){
	// 	cout << i << " " << j << " " << k << " -> " << dp[i][j][k] << endl;  
	// }
	cout << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--) solve();
}