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

#define MAXN 1000010
#define MOD 1000000007
#define INF 2000000000000000100

ll acu[MAXN];
ll n;
ll cap;
string s;
ll ans[MAXN];


signed main(){
	fastio;
	cin >> n >> s;
	char c = s.back();
	s.pop_back();
	if(c == 'T') cap = stoll(s) * 1024 * 1024;
	else if(c == 'G') cap = stoll(s) * 1024;
	else cap = stoll(s);
	frr(i, n){
		cin >> acu[i];
		acu[i] += acu[i - 1];
	}

	ll r = 1;
	ll val1 = n, val2 = -1;
	for(ll l = 1; l <= n; l++){
		while(r <= n && acu[r] - acu[l - 1] <= cap) r++;
		ans[l] = r - l;
		if(r <= n) {
			if(ans[l] < val1){
				val1 = ans[l];
				val2 = l;
			}
		}
	}

	cout<< val1 << ' ' << val2 << endl;


}
