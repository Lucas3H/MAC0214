#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = (int)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;

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

string s;

int solve(char a, char b){
	int ans = 0;
	int cur = 0;
	fr(i, s.size()){
		if(s[i] == a && cur == 0){
			cur = 1;
		}
		else if(s[i] == b && cur == 1){
			cur = 0;
		}
		else ans++;
	}
	if(cur == 1 && a != b) ans++;
	return ans;
}

void solve(){
	cin >> s;
	int ans = (int)s.size() - 2;	
	for(char c = '0'; c <= '9'; c++){
		for(char b = '0'; b <= '9'; b++){
			ans = min(ans, solve(c, b));
		}
	}
	cout << ans << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--) solve();
}
