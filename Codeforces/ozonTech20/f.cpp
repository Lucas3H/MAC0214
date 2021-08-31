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

#define mp make_pair
#define pq priority_queue

#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)
#define MAXN 200010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

ll a[MAXN];
ll n;
void decompose(ll x, vector<pii> & p){
	for(ll i = 2; i * i <= x; i++){
		if(x%i == 0){
			p.pb({i, 0});
			while(x%i == 0) x /= i;
		}
	}

	if(x > 1) p.pb({x, 0});
}

void update(ll x, pii & par){
	ll p = par.f;
	if(x < p) par.s += p - x;
	else par.s += min(x%p, p - x%p);
}

ll test(ll davez){
	vector<pii> p;
	decompose(a[davez]-1, p);
	decompose(a[davez], p);
	decompose(a[davez]+1, p);
	frr(i, n) fr(j, p.size()) update(a[i], p[j]);
	ll best = MOD;
	for(auto x: p) best = min(best, x.s);
	
	return best;
}

int main(){
	fastio;
	random;
	cin >> n;
	frr(i, n) cin >> a[i];
	ll ans = MOD;
	fr(it, 22) ans = min(ans, test(myrand(1, n)));
	cout << ans<< endl;
}
