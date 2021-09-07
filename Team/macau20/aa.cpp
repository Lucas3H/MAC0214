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
#define MOD 998244353
#define INF 1000000000000000100

signed main(){
	fastio;

	ll t;
	cin >> t;

	while(t--){
		ll n;
		ll v[5];
		cin >> n;
		fr(i, n) cin >> v[i];
		ll sum = 0;
		fr(i, n) sum = (sum + v[i]) % MOD;
		cout<< sum << endl;
		sum = 0;
		fr(i, n) fr(j, i) sum = (sum + v[i] * v[j] % MOD) % MOD;
		cout<< sum << endl;
		sum = 0;
		fr(i, n) fr(j, i) fr(k, j) sum = (sum + v[i] * v[j] % MOD * v[k] % MOD) % MOD;
		cout<< sum << endl;
		sum = 0;
		fr(i, n) fr(j, i) fr(k, j) fr(a, k) sum = (sum + v[i] * v[j] % MOD * v[k] % MOD * v[a] % MOD) % MOD;
		cout<< sum << endl;
		sum = 0;
		fr(i, n) fr(j, i) fr(k, j) fr(a, k) fr(b, a) sum = (sum + v[i] * v[j] % MOD * v[k] % MOD * v[a] % MOD * v[b] % MOD) % MOD;
		cout<< sum << endl;
	}
}