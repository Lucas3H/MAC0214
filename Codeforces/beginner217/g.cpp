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

#define MAXN 5010
#define MOD 998244353
#define INF 1000000000000000100

ll fastxp(ll n, ll e){
    ll ans = 1, pwr = n;
    while(e){
        if(e%2)  ans = ans * pwr % MOD;
        e /= 2;
        pwr = pwr * pwr % MOD;
    }
    return ans;
}

ll fat[MAXN], fat_inv[MAXN];
ll n, m;
ll num[MAXN], ans[MAXN];
ll bin[MAXN][MAXN];

signed main(){
	fastio;

	bin[0][0] = 1;
	frr(i, MAXN - 1){
		bin[i][0] = 1;
		frr(j, i){
			bin[i][j] = (bin[i-1][j] + bin[i-1][j-1]) % MOD;
		}
	}

	cin >> n >> m;
	frr(i, n) num[i%m]++;

	ll k = (n - 1)/m;
	frr(i, k) ans[i] = 0;
	
	k++;
	ll ini = k;

	fat[0] = 1;
	fat_inv[0] = 1;
	frr(i, MAXN - 1) {
		fat[i] = fat[i-1] * i % MOD;
		fat_inv[i] = fastxp(fat[i], MOD - 2) % MOD;
	}

	while(k <= n){
		ans[k] = 1;
		fr(i, m){
			ans[k] = (ans[k] * fat[k]) % MOD;
			ans[k] = (ans[k] * fat_inv[k - num[i]]) % MOD;
		}
		
  		for(ll i = ini; i < k; i++){
  			ans[k] = (ans[k] - bin[k][i] * ans[i] % MOD + MOD) % MOD;
  		}
		
		k++;
	}
	frr(i, n) {
		//cout << ans[i] << endl;
		ans[i] = (ans[i] * fat_inv[i]) % MOD;
		cout << ans[i] << '\n';
	}
}
