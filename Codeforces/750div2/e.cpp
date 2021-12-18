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

ll n, ans, k;
ll a[MAXN];
ll acu[MAXN];
ll fac[2][MAXN];

void solve(ll tam){
	frr(i, n) fac[1][i] = 0;
	ll maior = 0;
	frr(i, n - tam + 1){
		if(maior > acu[i + tam - 1] - acu[i - 1]){
			fac[1][i + tam - 1] = 1;
			ans = tam;
		}
		if(fac[0][i]) maior = max(maior, acu[i] - acu[i - tam + 1]);
	}
	swap(fac[0], fac[1]);
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){		
		ans = 1;
		cin>> n;
		k = (ll)sqrt(2*(double)n + 0.1);
		frr(i, n) cin >> a[i];
		frr(i, n / 2) swap(a[i], a[n + 1 - i]);
		frr(i, n) acu[i] = a[i] + acu[i - 1];
		frr(i, n) fac[0][i] = 1;
		for(ll i = 2; i <= k; i++) solve(i);
		cout << ans << endl;
	}
}
