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

#define MAXN 800010
#define MOD 1000000007
#define INF 2000000000000000100
#define B 400000

int tot[30];
int dp[(1 << 20)];
int sum[(1 << 20)];
int n;
int maximo[30], minimo[30], val[30];
int fr[20][MAXN];

void build(string s, int ind){
	int sum = 0;
	int mmax = 0, mmin = 0, num = 0;
	for(auto x: s){
		if(x == '(') sum++;
		else sum--;
		if(mmin == sum) {
			num++;	
			fr[ind][sum + B]++;
		}
		else if(mmin > sum){
			num = 1;
			mmin = sum;
			
			fr[ind][sum + B]++;
		}
	}
	maximo[ind] = mmax, minimo[ind] = mmin;
	tot[ind] = sum;
	val[ind] = num;
}

int ans = 0;
	
void solve(int mask){
	dp[mask] = -MOD;
	fr(i, n){
		if((1 << i) & mask){
			if(sum[mask] = sum[((1 << i) ^ mask)] + tot[i]);
			int s = sum[((1 << i) ^ mask)];
			if(s + minimo[i] == 0){
				dp[mask] = max(dp[((1 << i) ^ mask)] + val[i], dp[mask]);
			}
			else if(s + minimo[i] > 0){
				dp[mask] = max(dp[((1 << i) ^ mask)], dp[mask]);
			}
			else{
				ans = max(ans, dp[((1 << i) ^ mask)] + fr[i][B - s]);
				
			}
		}
	}
	ans = max(ans, dp[mask]);
}

signed main(){
	fastio;
	cin >> n;
	fr(i, n){
		string s;
		cin >> s;
		build(s, i);
	}
	dp[0] = 0;
	frr(i, (1 << n) - 1) solve(i);
	cout << ans << endl;
}
