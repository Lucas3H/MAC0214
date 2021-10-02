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

stack<string> davez;

ll solve(ll p){
	string s = davez.top();
	if((ll)s.size() == 0) {
		davez.pop();
		return p;
	}
	if(s[0] == '0') {
		string t;
		for(ll i = 1; i < (ll)s.size(); i++) t.pb(s[i]);
		davez.pop();
		if(t.size() == 0) return p;
		else return (stol(t) + 1) * p;
	}
	else if(s[0] > '1'){
		ll pwr10 = 1, prv = 0, ans = 0, sum_p = 0;
		fr(j, (ll)s.size()){
			ans += ((ll)s.size() - j + p)*(pwr10 - sum_p);
			prv = pwr10 - sum_p;
			sum_p += prv;
			pwr10 *= 10;	
		}
		string t;
		for(ll i = 0; i < (ll)s.size(); i++) t.pb(s[i]);

		davez.pop();
		if(t.size() == 0) ans += p * (1 - sum_p);
		else ans += p * (stol(t) + 1 - sum_p);
		return ans;
	}
	else{
		string t;
		ll pwr10 = 1;
		fr(j, (ll)s.size()-1) pwr10 *= 10;
		for(ll i = 1; i < (ll)s.size(); i++) t.pb(s[i]);
		if(t.size() == 0) return p + 1 + p * pwr10;
		
		davez.push(t);
		ll ret = solve(	p + 1) + p * pwr10; 
		davez.pop();
		return ret;
	}
}

signed main(int argc, char ** argv){
	fastio;

	string s;
	//fr(i, strlen(argv[1])) s.pb(argv[1][i]);
	cin >> s;
	ll ans = 0;
	frr(i, (ll)s.size()-1){
		ll pwr10 = 1, prv = 0, sum_p = 0;
		fr(j, i){
			ans += (i - j)*(pwr10 - sum_p);
			prv = pwr10 - sum_p;
			sum_p += prv;
			pwr10 *= 10;
		}
	}
	davez.push(s);
	ans += solve(0);

	cout << ans << endl;
}
