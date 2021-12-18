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

#define MAXN 200010
#define MOD 1000000007
#define INF 2000000000000000100

ll p[MAXN];
ll ans = 0;

void solve(vector<ll> v){
	if(v.size() == 0) return;

	ll par[2] = {0};
	for(auto x : v) par[x%2]++;
	if(par[1] > 0) ans = (ans + (p[par[1] - 1] - 1 + MOD) * p[par[0]] % MOD)%MOD;
	
	vector<ll> aux;
	for(auto x : v) if(x%2 == 0) aux.pb(x / 2);
	solve(aux); 
}


signed main(){
	fastio;
	p[0] = 1;
	frr(i, MAXN - 1) p[i] = p[i - 1] * 2 % MOD;
	ll n;
	cin >> n;
	vector<ll> v(n);
	fr(i, n) cin >> v[i];

	ll par[2] = {0};
	fr(i, n) par[v[i]%2]++;
	ans = (ans + (p[par[1]] - 1 + MOD) * p[par[0]] % MOD)%MOD;

	vector<ll> aux;
	for(auto x : v) if(x%2 == 0) aux.pb(x / 2);
	solve(aux);  

	cout << ans << endl;
}
