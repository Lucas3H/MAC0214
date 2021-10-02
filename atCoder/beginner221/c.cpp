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

vector<char> v;

signed main(){
	fastio;
	string s;
	cin >> s;
	fr(i, s.size()){
		v.pb(s[i]);
	}	

	vector<ll> perm;
	fr(i, s.size()) perm.pb(i);
	ll ans = 0;
	do{	
		fr(i, v.size() - 1){
			string a, b;	
			ll j = 0;
			while(j <= i) a.pb(v[perm[j++]]);
			while(j < v.size()) b.pb(v[perm[j++]]);
			if(a[0] == '0' || b[0] == '0') continue;
			ans = max(stoll(a)*stoll(b), ans);
			//cout << a << " " << b << endl;
		}
	}while(next_permutation(all(perm)));
	cout << ans << endl;
}
