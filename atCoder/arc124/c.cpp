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

#define MAXN 1500
#define MOD 1000000007
#define INF 2000000000000000100

set<pii> davez;

ll n;
ll a[MAXN], b[MAXN];

signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> a[i] >> b[i];
	davez.insert({a[0], b[0]});
	frr(i, n - 1){
		set<pii> nxt;
		for(auto p : davez){
			nxt.insert({__gcd(p.f, a[i]), __gcd(p.s, b[i])});
			nxt.insert({__gcd(p.f, b[i]), __gcd(p.s, a[i])});
		}
		davez = nxt;
	}

	ll ans = 0;
	for(auto p : davez) ans = max(ans, p.f * p.s / __gcd(p.f, p.s));
	cout << ans << endl;
}
