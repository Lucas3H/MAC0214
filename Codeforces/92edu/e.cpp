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

ll t;
ll m, d, w;

signed main(){
	fastio;
	cin >> t;

	while(t--){
		cin >> m >> d >> w;
		if(d == 1){
			cout << 0 << endl;
			continue;
		}
		ll lim = min(m, d);
		w /= __gcd(d - 1, w);
		ll r = lim % w, q = lim / w;
		cout << r * (q + 1) * q / 2 + (w - r) * q * (q - 1) / 2 << endl;
	}
}
