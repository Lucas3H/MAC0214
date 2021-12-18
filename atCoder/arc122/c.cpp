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

ll fib[MAXN];
ll n, N;
vector<ll> f;

signed main(){
	fastio;
	cin >> n;
	N = n;

	fib[0] = 0, fib[1] = 1;
	ll i = 2;
	for(; fib[i - 1] <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];
	i--;
	while(n && i >= 1){
		if(fib[i] <= n){
			//dbg(fib[i]);
			f.pb(i);
			n -= fib[i];
		}
		i--;
	}

	vector<ll> ans;
	ll a = 1, b = 0;
	ans.pb(1);
	for(ll i = 1; i < f.size(); i++){
		for(ll j = f[i]; j < f[i - 1]; j++){
			if(a > b) {
				ans.pb(4);
				b = a + b;
			}
			else {
				ans.pb(3);
				a = a + b;
			}
		}
		if(a > b){
			ans.pb(1);
			a++;
		}
		else{
			ans.pb(2);
			b++;
		}
	}
	for(ll j = 1; j < f.back(); j++){
		if(a > b) {
			ans.pb(4);
			b = a + b;
		}
		else {
			ans.pb(3);
			a = a + b;
		}
	}

	// dbg(ans.size());
	// dbg(f.size());
	// dbg(f[0]);	
	if(ans.size() > 130){
		assert(0);
	}
	// dbg(a);
	// dbg(b);
	if(a == N){
		cout << ans.size() << endl;
		for(auto x: ans) cout << x << endl;
	}
	else if(b == N){
		cout << ans.size() << endl;
		for(auto x: ans){
			if(x == 3) cout << 4 << endl;
			else if(x == 4) cout << 3 << endl;
			else if(x == 1) cout << 2 << endl;
			else cout << 1 << endl;
		}
	}
	else assert(0);

	// dbg(a);
	// dbg(b);
}
