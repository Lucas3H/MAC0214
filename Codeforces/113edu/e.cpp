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
#define MOD 998244353
#define INF 1000000000000000100

ll pwrA[50];
ll k, a, h;

ll get_hash(ll mask, vector<ll> p, ll exp){
	if(p.size() == 1){
		if(mask) return p[0]*pwrA[1] % MOD;
		else return p[0] * pwrA[2] % MOD;
	}
	vector<ll> w;
	ll ans = 0;
	for(ll i = 0; i < p.size(); i+=2){
		if(mask%2) {
			ans = (ans + p[i]*pwrA[exp]) % MOD;
			w.pb(p[i+1]);
		}
		else {
			ans = (ans + p[i + 1]*pwrA[exp]) % MOD;	
			w.pb(p[i]);
		}
		mask /= 2;
	}
	ans = (ans + get_hash(mask, w, exp/2 + 1)) % MOD;
	return ans;
}

map<pii, pii> m;
ll resp[50];

void prll(ll mask, vector<ll> p, ll exp){
	if(p.size() == 1){
		if(mask) resp[p[0]] = 1;
		else resp[p[0]] = 2;
		return;
	}
	vector<ll> w;
	for(ll i = 0; i < p.size(); i+=2){
		if(mask%2) {
			resp[p[i]] = exp;
			w.pb(p[i+1]);
		}
		else {
			resp[p[i+1]] = exp;	
			w.pb(p[i]);
		}
		mask /= 2;
	}
	prll(mask, w, exp/2 + 1);
}

signed main(){
	fastio;
	cin >> k >> a >> h;
	pwrA[0] = 1;
	frr(i, 49) pwrA[i] = a * pwrA[i-1] % MOD;

	vector<ll> pos;
	ll tot = (1 << (k-1));
	
	fr(i, tot) pos.pb(i + tot + 1);
	fr(i, (1 << tot)) {
		ll w = ((i & (1 << (tot-1))) != 0);
		m[{get_hash(i, pos, tot + 1), w}] = {i, 1};
	}
	
	pos.clear();
	fr(i, tot) pos.pb(i + 1);

	fr(i, (1 << tot)){
		ll w = ((i & (1 << (tot-1))) != 0);

		pii p = m[{(h - get_hash(i, pos, tot + 1) + MOD)%MOD, 1 - w}];
		if(p.s != 0){
			prll(i, pos, tot + 1);

			pos.clear();
			fr(i, tot) pos.pb(i + 1 + tot);

			prll(p.f, pos, tot + 1);

			frr(i, (1 << k)) cout << resp[i] << " ";
			cout << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}
