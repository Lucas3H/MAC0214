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

int pref[210][(1 << 16)], suf[201][(1 << 16)];
int n, k;
int a[MAXN];

void build(){
	for(int i = n; i >= 1; i--){
		fr(j, (1 << k)) pref[i][j] = pref[i+1][j] + __builtin_popcount(j);
		fr(j, (1 << k)) {
			int davez = a[i];
			if(((1 << davez) & j) && pref[i+1][j^(1 << davez)] < MOD){
				int sum = 0;
				fr(l, davez) if((1 << l)&j) sum++;
				pref[i][j] = pref[i+1][j^(1 << davez)] + sum;
			}
		}
	}
}

void build_suf(){
	for(int i = 1; i <= n; i++){
		fr(j, (1 << k)) suf[i][j] = suf[i-1][j] + __builtin_popcount(j);
		fr(j, (1 << k)) {
			int davez = a[i];
			
			if(((1 << davez) & j) && suf[i-1][j^(1 << davez)] < MOD){
				int sum = 0;
				for(int l = k-1; l > davez; l--) if((1 << l)&j) sum++;
				suf[i][j] = suf[i-1][j^(1 << davez)] + sum;
			}
		}
	}
}

ll inv[(1 << 16)];

void build_inv(int m1){
	ll m2 = (1 << k) - 1 - m1;
	ll tot = __builtin_popcount(m1);
	fr(i, k){
		if((1 << i)&m2) inv[m1]+=tot;
		else tot--;
	}
}

signed main(){
	fastio;
	cin >> n >> k;
	fr(i, (1 << k)) build_inv(i);
	fr(i, n+2) fr(j, (1 << k)) pref[i][j] = suf[i][j] = MOD;
	pref[n+1][0] = 0;
	suf[0][0] = 0;

	frr(i, n) cin >> a[i], a[i]--;
	build();
	build_suf();

	// frr(i, n) fr(j, (1 << k)){
	// 	cout << i << " " << j << " " << suf[i][j] <<endl;
	// }

	ll ans = MOD;
	frr(i, n-1){
		fr(j, (1 << k)) {
			// if(ans > suf[i][j] + pref[i+1][(1 << k) - 1 - j] + inv[j]){
			// 	cout << i << " " << j << ' ' << suf[i][j] << " " << pref[i+1][(1 << k) - 1 - j] << " " << inv[j] << endl;
			// }
			ans = min(ans, suf[i][j] + pref[i+1][(1 << k) - 1 - j] + inv[j]);
		}
	}
	cout<< ans << endl;
}
