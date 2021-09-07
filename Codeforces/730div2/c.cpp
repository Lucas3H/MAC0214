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

#define MAXN 100010
#define MOD 1000000007
#define INF 1000000000000000100
#define eps 0.00000000001

double c, m, p, v;

double solve(double x, double y, ll depth){
	if(abs(x) < eps && abs(y) < eps) return depth;
	double ans = depth * (1 - x - y);
	if(abs(y) < eps){
		if(v > x) ans += x*solve(0, 0, depth + 1);
		else ans += x*solve(x - v, 0, depth + 1);
	}
	else if(abs(x) < eps){
		if(v > y) ans += y*solve(0, 0, depth + 1);
		else ans += y*solve(0, y - v, depth + 1);
	}
	else{
		if(v > x) ans += x*solve(0, y + x/2, depth + 1);
		else ans += x*solve(x - v, y + v/2, depth + 1);
		if(v > y) ans += y*solve(x + y/2, 0, depth + 1);
		else ans += y*solve(x + v/2, y - v, depth + 1);
	}
	return ans;
}	

signed main(){
	int t;
	cin >>t;
	while(t--){
		cin >> c >>m >> p >> v;
		printf("%.10lf\n", solve(c, m, 1));
	}
}
