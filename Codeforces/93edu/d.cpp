#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 201
#define MOD 1000000007
#define INF 1000000000000000100

int dp[MAXN][MAXN][MAXN];
int a[MAXN], b[MAXN], c[MAXN];

int solve(int ia, int ib, int ic){
	int & memo = dp[ia][ib][ic];
	if(memo > -1) return memo;
	if(ia + ib + ic <= 1) return 0;
	memo = 0;
	if(ia && ib){
		memo = max(memo, a[ia]*b[ib] + solve(ia-1, ib-1, ic));
	}
	if(ic && ib){
		memo = max(memo, c[ic]*b[ib] + solve(ia, ib-1, ic-1));
	}
	if(ia && ic){
		memo = max(memo, a[ia]*c[ic] + solve(ia-1, ib, ic-1));
	}
	return memo;


}

signed main(){
	fastio;
	mem(dp, -1);
	int ta, tb, tc;
	cin >> ta >> tb >> tc;

	frr(i, ta) cin >> a[i];
	frr(i, tb) cin >> b[i];
	frr(i, tc) cin >> c[i];
	sort(a + 1, a + ta  + 1);
	sort(b + 1, b + tb  + 1);
	sort(c + 1, c + tc  + 1);

	cout << solve(ta, tb, tc) << endl;
}
