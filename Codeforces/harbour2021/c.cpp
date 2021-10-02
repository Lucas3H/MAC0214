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

int solve(int mask){
	int p[2] = {0, 0}, r[2] = {5, 5};
	frr(i, 10){
		p[i%2] += mask%2;
		r[i%2]--;

		if(p[1] + r[1] < p[0] || p[0] + r[0] < p[1]) return i;
		mask /= 2;
	}
	return 10;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		string m;
		cin >> m;
		int mask1 = 0, mask2 = 0;
		frm(i, 10){
			mask1 *= 2;
			mask2 *= 2;
			if(m[i] == '1') mask1++, mask2++;
			if(m[i] == '?') mask2++;
		}
		// dbg(mask1);
		// dbg(mask2);

		int ans = 10;
		fr(i, (1 << 10)){
			if((mask1 & i) == mask1 && (mask2 & i) == i){
				ans = min(ans, solve(i));
			}
		}
		cout << ans << endl;
	}
}
