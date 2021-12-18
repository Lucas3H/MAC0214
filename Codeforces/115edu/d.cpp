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
#define INF 2000000000000000100

ll n;
vector<ll> topic[MAXN];
ll dif[MAXN];
ll tot = 0;
ll ans = 0;


void remove(ll ind, ll t){
	ans -= (tot - dif[ind] - topic[t].size() + 1);
	tot--, dif[ind]--;
}
ll query(ll ind, ll t){
	return ans - (tot - dif[ind]) * dif[ind];
}
void build(){
	frr(i, n) for(auto x : topic[i]){
		dif[x]++;
		tot++;
	}

	frr(i, n){
		for(auto x : topic[i]){
			ans += (tot - topic[i].size() - dif[x] + 1);
		}
	}
	ans /= 2;
}

ll a1[MAXN], b1[MAXN];

ll get_all_triples(ll v[]){
	ll ans = n * n * n;
	frr(i, n) ans -= v[i] * v[i] * v[i];
	frr(i, n){
		ans -= 3 * v[i] * v[i] * (n - v[i]);
	}
	return ans;
}

void solve(){
	cin >> n;
	frr(i, n){
		topic[i].clear();
		dif[i] = 0;
	}
	tot = ans = 0;

	fr(i, n){
		ll a, b;
		cin >> a >> b;
		topic[a].pb(b);
		a1[a]++, b1[b]++;
	}
	build();

	ll resp = 0;
	frr(i, n){
		for(auto x : topic[i]) remove(x);
		for(auto x : topic[i]) resp += query(x);
		dbg(resp);
		dbg(ans);
	}
	cout << ans << endl;
}


signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--) solve();
}
