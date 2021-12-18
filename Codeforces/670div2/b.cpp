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

vector<ll> pos;
vector<ll> neg;
ll n;

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--){
		cin >> n;
		pos.clear(), neg.clear();

		fr(i, n){
			ll a;
			cin >> a;
			if(a > 0) pos.pb(a);
			else neg.pb(a);
		}

		sort(all(neg));
		sort(all(pos));
		ll val = 1, ans;
		
		if(pos.size() == 0){
			ll ans = 1;
			for(ll i = (ll)neg.size() - 1; i >= (ll)neg.size() - 5; i--) ans = ans * neg[i];
			cout << ans << endl;
			continue;
		}

		ll i, j;
		for(j = (ll)pos.size() - 1; j >= 0 && j >= (ll)pos.size() - 5; j--) val = val * pos[j];
		for(i = 0; i < 5 - (ll)pos.size(); i++) val = val * neg[i];

		ans = val;
		j++;
		for(; i < 5 && i < (ll)neg.size() && j < (ll)pos.size(); i++, j++) {
			val /= pos[j];
			val *= neg[i]; 
			ans = max(ans, val);
		}
		cout << ans << endl;
	}
}
