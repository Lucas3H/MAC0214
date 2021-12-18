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
#define INF 1000000000000000100

ll sz[MAXN], pai[MAXN];
ll find(ll x){
	if(x == pai[x]) return x;
	else return pai[x] = find(pai[x]);
}

ll join(ll a, ll b){
	a = find(a), b = find(b);
	if(a == b) return false;
	if(sz[a] > sz[b]) swap(a, b);
	pai[a] = b;
	sz[b] += sz[a];
	return true;
}

vector<array<ll, 3>> e;
ll n, m;

signed main(){
	fastio;
	cin >> n >> m;
	ll ans = 0;
	fr(i, m){
		ll a, b, c;
		cin >> a >> b >> c;
		e.pb({c, a, b});
		if(c > 0) ans += c;
	}
	sort(all(e));
	frr(i, n) sz[i] = 1, pai[i] = i;
	fr(i, m){
		ll val = e[i][0];
		if(join(e[i][1], e[i][2])){
			if(val > 0) ans -= val;
		}
	}
	cout << ans << endl;
}
