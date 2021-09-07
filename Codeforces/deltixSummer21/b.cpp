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
#define MOD 1
#define INF 1000000000000000100

ll a[MAXN];
ll n;

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--){
		cin >> n;
		vector<ll> v;
		ll par = 0, impar = 0;
		fr(i, n){
			cin >> a[i];
			if(a[i]%2 == 0) v.pb(i);
			if(a[i]%2 == 0) par++;
			else impar++;
		}

		if(abs(par - impar) > 1) {
			cout << -1 << endl;
			continue;
		}

		ll ans = INF;
		if(impar >= par){
			ll sum = 0;
			fr(i, v.size()){
				sum += abs(v[i] - i - i - 1);
			}
			ans = min(ans, sum);
		}
		if(par >= impar){
			ll sum = 0;
			fr(i, v.size()){
				sum += abs(v[i] - i - i);
			}
			ans = min(ans, sum);
		}
		cout << ans << endl;
	}
}
