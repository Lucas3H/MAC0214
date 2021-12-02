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

#define MAXN 400010
#define MOD 50331653
#define INF 2000000000000000100

ll fastxp(ll n, ll e){
    ll ans = 1, pwr = n;
    while(e){
        if(e%2)  ans = ans * pwr % MOD;
        e /= 2;
        pwr = pwr * pwr % MOD;
    }
    return ans % MOD;
}
v
ector<ll> Hash[MAXN];
ll p[MAXN], pi[MAXN];
string s[MAXN];
ll n, m;

ll h(ll ind, ll l, ll r){
	return (Hash[ind][r] - Hash[ind][l - 1] + MOD) * pi[l - 1] % MOD;
}

void build(ll ind){
	Hash[ind].resize(s[ind].size() + 1);

	Hash[ind][0] = 0;
	for(ll i = 1; i <= s[ind].size(); i++){
		Hash[ind][i] = (Hash[ind][i - 1] + (ll)(s[ind][i - 1] - 'a' + 1) * p[i - 1]) % MOD;
	}
}

void build_Hash(){
	pi[0] = p[0] = 1;
	p[1] = 31, pi[1] = fastxp(31, MOD - 2);
	for(ll i = 2; i < MAXN; i++){
		pi[i] = pi[i - 1] * pi[1] % MOD;
		p[i] = p[i - 1] * p[1] % MOD;
	}
	fr(i, m + 1) build(i);
}

void read(){
	cin >> n >> m;
	cin >> s[0];
	s[0] += s[0];
	frr(i, m) cin >> s[i];
	build_Hash();
}

set<ll> subs;

void coloca(ll ind, ll t){
	frr(i, (ll)s[ind].size() - t + 1) 
		subs.insert(h(ind, i, i + t - 1));
}

ll acu[MAXN];

bool test(ll t){
	subs.clear();
	frr(i, m) coloca(i, t);

	frr(i, 2*n) acu[i] = 0;
	frr(i, 2*n - t + 1){
		ll davez = h(0, i, i + t - 1);

		if(subs.find(davez) != subs.end()) acu[i] = 1;
	}
	frr(i, 2*n) acu[i] += acu[i-1];

	frr(i, n) 
		if(acu[i + n - t] == acu[i - 1]) return false;
	
	return true;
}

signed main(){
	fastio;

	read();
	ll l = 0, r = n + 1, m;	

	while(l < r - 1){
		m = (l + r)/2;
		if(!test(m)) r = m;
		else l = m;
	}
	cout << l << endl;
}
