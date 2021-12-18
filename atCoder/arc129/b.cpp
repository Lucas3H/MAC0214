#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

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
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 200010
#define MOD 1000000007
#define INF 2000000000000000100

pii p[MAXN];
ll n;
ll l, r;
ll ans[MAXN];

signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> p[i].f >> p[i].s;
	ans[0] = 0;
	l = p[0].s, r = p[0].f;

	frr(i, n - 1){
		l = min(p[i].s, l);
		r = max(p[i].f, r);
		if(r <= l) ans[i] = 0;
		else{
			ans[i] = (r - l + 1)/2;
		}
	}
	fr(i, n) cout << ans[i] << endl;

}
