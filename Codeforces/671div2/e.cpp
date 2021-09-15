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
#define INF 1000000000000000100

ll n;
bool nprime[MAXN];

void sieve(){
	for(ll i = 2; i < MAXN; i++){
		if(nprime[i] == 0){
			for(ll j = 2 * i; j < MAXN; j += i) nprime[j] = 1;
		}
	}
}

vector<ll> decompose(ll x){
	vector<ll> p;
	for(ll i = 2; i* i <= x; i++){
		if(x % i == 0){
			p.pb(i);
			while(x%i == 0) x/=i;
		}
	}
	if(x > 1) p.pb(x);
	return p;
}

set<ll> d, aux;
void solve(){
	cin >> n;
	d.clear();
	vector<ll> p = decompose(n);

	for(ll i = 2; i* i <= n; i++){
		if(n % i == 0){
			d.insert(i);
			if(i*i == n) continue;
			d.insert(n/i);
		}
	}

	for(auto x: p) d.erase(x);

	if(p.size() == 2 && d.size() == 0) {
		cout <<p[0] << ' ' << p[1] << " " << n << endl << 1 << endl;
		return;
	}
	vector<ll> ans;

	fr(i, p.size() - 1) d.erase(p[i] * p[i + 1]);

	fr(i, p.size()){
		aux.clear();
		ans.pb(p[i]);
		for(auto x: d) {
			if(x%p[i]) aux.insert(x);
			else ans.pb(x);
		}
		if(i < p.size() - 1) ans.pb(p[i] * p[i+1]);
		d = aux;
	}
	ans.pb(n);
	for(auto x: ans) cout << x <<' ';
	cout << endl;
	cout << 0 << endl;
}


signed main(){
	fastio;
	sieve();
	ll t;
	cin >> t;
	while(t--) solve();
}
