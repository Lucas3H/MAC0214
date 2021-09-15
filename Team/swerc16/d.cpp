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
#define INF 1000000000000000100

ll binomial[60][60];
ll n, d, c;

ll bin(ll x, ll y){
	if(x < y || x < 0 || y < 0) return 0;
	return binomial[x][y];
}

long double p(ll x, ll o1, ll y, ll both, ll z, ll o2){
	ll ret = bin(o1, x) * bin(both, y) * bin(o2, z) * bin(n - o1 - both - o2, d - x - y - z);
	return (long double) ret / bin(n, d);
}

long double dp[11][11][11];

long double solve(ll o1, ll both, ll o2){
	long double & memo = dp[o1][both][o2];
	if(memo > -1) return memo;
	if(both == 0 && o1 == 0) return 0;
	else if(both == 0 && o2 == 0) return 0;

	memo = p(0, o1, 0, both, 0, o2);
	fr(i, o1 + 1){
		if(i > d) break;
		fr(j, both + 1){
			if(i + j > d) break;
			fr(k, o2 + 1){
				if(i == 0 & j == 0 && k == 0) continue;
				if(i + j + k > d) break;
				memo += (solve(o1 - i, both - j, o2 - k) + 1.0) * p(i, o1, j, both, k, o2);
			}
		}
	}

	memo /= (1.0 - p(0, o1, 0, both, 0, o2));
	return memo;
}

signed main(){
	binomial[0][0] = 1;
	frr(i, 51){
		fr(j, i+1){
			if(j == 0) binomial[i][j] = 1;
			else binomial[i][j] = binomial[i-1][j] + binomial[i-1][j-1];
		}
	}
	fr(i, 11) fr(j, 11) fr(k, 11) dp[i][j][k] = -2.0;
	cin >> n >> d >> c;

	set<int> p1;
	int both = 0;
	fr(i, c){
		int x;
		cin >> x;
		p1.insert(x);
	}
	fr(i, c){
		int x;
		cin >> x;
		if(p1.count(x)) both++;
	}

	printf("%.8Lf\n", solve(c - both, both, c - both));
}
