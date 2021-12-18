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

ll x[MAXN], y[MAXN];

ll func(ll a, ll b, ll c){
	ll val = x[a] * y[b] + x[c] * y[a] + x[b] * y[c];
	val -= x[a] * y[c] + x[c] * y[b] + x[b] * y[a];
	if(val == 0) return 1;
	else return 0;
} 

signed main(){
	fastio;
	ll n;
	cin >> n;
	fr(i, n){
		cin >> x[i] >> y[i];
	}
	ll ans = n * (n - 1) * (n - 2) / 6;
	fr(i, n) fr(j, i) fr(k, j) if(func(i, j, k)) ans--;
	cout << ans << endl;
}
