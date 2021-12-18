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

vector<ll> y;
ll acu[MAXN];
string s;
ll k;

bool testa(ll tam){
	ll l = 1, r = tam - 1, m = (l + r)/2;
	ll sum = 0;
	frr(i, m) sum += (y[i] - y[i - 1] - 1) * i;
	for(ll i = m + 1; i <= r; i++) sum += (y[i] - y[i - 1] - 1) * (r - i + 1);
	while(r < y.size()){
		if(sum <= k) return true;
		sum -= acu[m] - acu[l - 1];
		if(tam%2) sum += acu[r + 1] - acu[m + 1];
		else sum += acu[r + 1] - acu[m];
		l++, r++;
		m = (l + r)/2;
	}
	return false;
}

signed main(){
	fastio;
	cin >> s >> k;
	fr(i, s.size()){
		if(s[i] == 'Y') y.pb(i);
	}
	if(y.size() == 0){
		cout << 0 << endl;
		return 0;
	}
	frr(i, (ll)y.size() - 1) acu[i] = acu[i-1] + y[i] - y[i - 1] - 1;

	//dbg(testa(3));
	//testa(5);
	ll l = 1, r = y.size() + 1, m;
	while(l < r - 1){
		m = (l + r)/2;
		if(testa(m)) l = m;
		else r = m;
	}
	cout << l << endl;
}
 