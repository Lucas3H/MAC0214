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
#define INF 2000000000000000100

ll mmc[MAXN];
ll t, n;
ll a[MAXN];

signed main(){
	fastio;
	mmc[1] = 1;
	for(ll i = 2; i < MAXN; i++){
		mmc[i] = mmc[i - 1] * i / __gcd(mmc[i - 1], i);
		if(mmc[i] > MOD) mmc[i] = MOD;
	}

	cin >> t;

	while(t--){
		cin >> n;
		frr(i, n) cin >> a[i];

		ll ok = 1;
		frr(i, n){
			if(a[i] % mmc[i + 1] == 0){
				ok = 0;
				break;
			}
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
