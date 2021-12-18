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
#define INF 2000000000000000100

vector<double> flags;
int n, c;

void solve(){
	cin >> n >> c;
	flags.assign(n + 2, 0);
	frr(i, n) cin >> flags[i];
	flags[n + 1] = c;

	int l = 0, r = n + 1;
	double tl = 0, tr = 0;
	while(l < r - 1){
		if(tl + (flags[l + 1] - flags[l])/(l + 1) > tr + (flags[r] - flags[r - 1])/(n + 2 - r)){
			tr += (flags[r] - flags[r - 1])/(n + 2 - r);
			r--;
		}
		else{
			tl += (flags[l + 1] - flags[l])/(l + 1);
			l++;
		}
	}

	double d = (flags[l + 1] - flags[l]);
	if(tl < tr){
		d -= (l + 1) * (tr - tl); 	
		printf("%.8lf\n", tr + d / (n + 2));
	}
	else{
		d -= (n + 2 - r) * (tl - tr);
		printf("%.8lf\n", tl + d / (n + 2));
	}

}

signed main(){
	int t;
	cin >> t;

	while(t--){
		solve();
	}
}
