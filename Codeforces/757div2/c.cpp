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

#define MAXN 200010
#define MOD 1000000007
#define INF 2000000000000000100

ll n, m;
ll p[MAXN];

signed main(){
	fastio;
	p[0] = 1;
	frr(i, MAXN - 1) p[i] = p[i - 1] * 2 % MOD;

	ll t;
	cin >> t;

	while(t--){
		cin >> n >> m;
		set<ll> bits;

		fr(i, m){
			ll l, r, x, j = 0;
			cin >> l >> r >> x;
			while(x){
				if(x%2) bits.insert(j);
				j++, x /= 2;
			}
		}
		ll sum = 0;
		for(auto x : bits) sum = (sum + p[x]) % MOD;
		cout << sum * p[n - 1] % MOD << endl;
	}
}
