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

int t[MAXN], a[MAXN], b[MAXN];
bool dp[MAXN];
int n, c;

int vivea[200100];

void calca(){
	vivea[n - 1] = n;
	int l = n - 2, r = n;

	while (l >= 0){
		if (t[l] + a[l] <= t[l + 1])
			vivea[l] = r;
		else{
			vivea[l] = l;
			r = l - 1;
		}

		l--;
	}
}


void solve(){
	int i = 0;
	while(i < n){
		if(t[i] + b[i] < t[i + 1]){
			dp[i + 1] = true;
			i++;
			continue;
		}
		if(!dp[i]) break;
		i++;
		int ini = i;	
		while(i < n && i < vivea[ini]){
			dp[i + 1] = true;
			i++;
		}
	}
}

signed main(){
	fastio;
	cin >> n >> c;
	fr(i, n) cin >> t[i];
	fr(i, n) cin >> a[i];
	fr(i, n) cin >> b[i];

	calca();
	solve();
	int ans = 2*MOD;
	if(t[vivea[0]] >= c){
		ans = min(ans, c);
	}
	fr(i, n){
		dbg(vivea[i]);
		if(dp[i] && t[vivea[i + 1]] >= b[i] + t[i] + c){
			ans = min(ans, b[i] + t[i] + c);
		}
	}
	if(ans == 2 * MOD) cout << "Dire victory" << endl;
	else{
		cout << "Radiant victory" << endl;
		cout << ans << endl;
	}

}
