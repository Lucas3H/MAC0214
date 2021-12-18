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

#define MAXN 2001	
#define MOD 1000000007
#define INF 2000000000000000100

string ans;
ll tri[MAXN];


signed main(){
	fastio;
	ll n;
	fr(i, MAXN) tri[i] = i * (i + 1) / 2;

	ll val = 0;
	for(ll aux = 1; aux <= 1000000; aux++){
		n = aux;
		ans.clear();
		ll tot = 0;
		for(ll i = MAXN - 1; i > 0;){
			if(tri[i] <= n){
				n -= tri[i];
				fr(j, i) ans.pb('7');
				ans.pb('1');
				tot++;
			}
			else i--;
		}
		ans.pop_back();
		//cout << ans << endl;
		val = max(val, tot);
	}
	cout << val << endl;
}
