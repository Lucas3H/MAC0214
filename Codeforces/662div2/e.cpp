#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = (ll)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;

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

const long long mod1 = 1000015553;
const long long mod2 = 1000028537;

mt19937 rng((ll) chrono::steady_clock::now().time_since_epoch().count()); // Random number generator
static long long base = 27;	// In case TL, use const

struct str_hash{
	string s; 
	long long n;
	vector<long long> hsh1, pwr1, hsh2, pwr2;

	str_hash() : n(0) {}
	str_hash(string _s) : n(_s.size()), s(_s), hsh1(n), pwr1(n + 1), hsh2(n), pwr2(n + 1){	
		pwr1[0] = pwr2[0] = 1;
		for (ll i = 1; i <= n; i++){
			pwr1[i] = (base * pwr1[i - 1]) % mod1;
			pwr2[i] = (base * pwr2[i - 1]) % mod2;
		}
		hsh1[0] = hsh2[0] = s[0] - 'a' + 1;
		for (ll i = 1; i < n; i++){
			hsh1[i] = (hsh1[i - 1] * base + (long long)(s[i] - 'a' + 1))%mod1;
			hsh2[i] = (hsh2[i - 1] * base + (long long)(s[i] - 'a' + 1))%mod2;
		}
	}
	array<long long, 2> hash(ll i, ll j){ // hash no llervalo [i, j]
		if(i > j) return {0, 0};
		if (i == 0) return {hsh1[j], hsh2[j]};
		long long ret1 = ((hsh1[j] - (hsh1[i - 1] * pwr1[j - i + 1])) % mod1 + mod1) % mod1;
		long long ret2 = ((hsh2[j] - (hsh2[i - 1] * pwr2[j - i + 1])) % mod2 + mod2) % mod2;
		return {ret1, ret2};
	}

	array<long long, 2> hash(ll i, ll j, ll ignore){ // hash no llervalo [i, j]
		if(ignore > j || ignore < i) return hash(i, j);
		
		array<long long, 2> l = hash(i, ignore - 1), r = hash(ignore + 1, min(j + 1, n - 1));
		
		long long ret1 = (l[0] * pwr1[j - ignore + 1] + r[0]) % mod1;
		long long ret2 = (l[1] * pwr2[j - ignore + 1] + r[1]) % mod2;

		return {ret1, ret2};
	}
};

str_hash h[MAXN];
string s[MAXN];
vector<ll> dp[MAXN];
ll n;

bool comp(const pii a, const pii b){
	ll ia = a.f, ib = b.f, ignore_a = a.s, ignore_b = b.s;
	ll l = -1, r = min(h[ia].s.size(), h[ib].s.size()), m;
	while(l < r - 1){
		m = (l + r)/2;

		if(h[ia].hash(0, m, ignore_a) == h[ib].hash(0, m, ignore_b)) l = m;
		else r = m;
	}
	
	ll xa = r, xb = r;
	if(a.s <= r) xa++;
	if(b.s <= r) xb++;

	if(xa >= h[ia].s.size() && xb >= h[ib].s.size()) return ia < ib;
	else if(xa >= h[ia].s.size()) return true;
	else if(xb >= h[ib].s.size()) return false;
	else return h[ia].s[xa] < h[ib].s[xb];
}



signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> s[i];
	
	fr(i, n) {
		h[i] = str_hash(s[i]);
 	}

	dp[0].resize(s[0].size() + 1);
	for(auto & x: dp[0]) x = 1;

	frr(i, n - 1){
		dp[i].resize(s[i].size() + 1, 0);
		
		vector<pii> v;
		fr(j, s[i - 1].size() + 1) v.pb({i - 1, j});
		fr(j, s[i].size() + 1) v.pb({i, j});
		sort(all(v), comp);
		// for(auto x: v) {
		// 	//cout << x.f << " " << x.s << endl;
		// 	fr(j, s[x.f].size()) if(x.s != j) cout << s[x.f][j];
		// 	cout << endl;
		// }
		ll sum = 0;
		for(auto x: v){
			if(x.f == i - 1) sum = (sum + dp[i - 1][x.s]) % MOD;
			else dp[i][x.s] = sum;
		}
	}

	ll ans = 0;
	for(auto x : dp[n - 1]) ans = (ans + x) % MOD;
	cout << ans << endl;
}
