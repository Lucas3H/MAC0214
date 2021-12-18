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

__int128 fastxp(__int128 n, __int128 e, __int128 mod){
    __int128 ans = 1, pwr = n;
    while(e){
        if(e%2)  ans = ans * pwr % mod;
        e /= 2;
        pwr = pwr * pwr % mod;
    }
    return ans % mod;
}

signed main(){
	fastio;
	ll n, m, k;
	cin >> n >> k >> m;

	if(m%998244353 == 0) cout << 0 << endl;
	else cout << (ll)fastxp(m, fastxp(k, n, 998244352), 998244353) << endl;
}
