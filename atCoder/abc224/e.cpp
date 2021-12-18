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

#define MAXN 400010
#define MOD 1000000007
#define INF 2000000000000000100

int ansh[MAXN], answ[MAXN], auxh[MAXN], auxw[MAXN];
int r, c, a, ans[MAXN];
int n, H, W;
map<int, vector<array<int, 3>>> val;

void solve(vector<array<int, 3>> & aux){
	for(auto x: aux) auxh[x[0]] = 0, auxw[x[1]] = 0;
	for(auto x: aux){
		auxh[x[0]] = max(ansh[x[0]] + 1, max(answ[x[1]] + 1, auxh[x[0]]));
		auxw[x[1]] = max(ansh[x[0]] + 1, max(answ[x[1]] + 1, auxw[x[1]]));
		ans[x[2]] = max(ansh[x[0]] + 1, answ[x[1]] + 1);
	}
	for(auto x: aux) ansh[x[0]] = auxh[x[0]], answ[x[1]] = auxw[x[1]];
}


signed main(){
	fastio;
	cin >> H >> W >> n;
	frr(i, n){
		cin >> r >> c >> a;
		val[-a].pb({r, c, i});
	}
	frr(i, H) ansh[i] = -1;
	frr(i, W) answ[i] = -1;
	for(auto x: val) {
		solve(x.s);
	}
	frr(i, n) cout << ans[i] << endl;
}
