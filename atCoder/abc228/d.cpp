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

#define MAXN (1 << 20)
#define MOD 1000000007
#define INF 2000000000000000100

set<ll> a;
ll q;
ll ans[MAXN];

signed main(){
	fastio;
	fr(i, (1 << 20)) a.insert(i);
	mem(ans, -1);
	cin >> q;
	
	while(q--){
		ll x, y;
		cin >> x >> y;
		ll ini = y;
		y = y%(1 << 20);
		if(x == 2){
			cout << ans[y] << endl;
		}
		else{
			auto it = a.lower_bound(y);
			if(it != a.end()){
				ans[(*it)] = ini;
				a.erase(it);
			}
			else{
				ans[*(a.begin())] = ini;
				a.erase(a.begin());
			}
		}
	}
}
