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

ll ask(ll l, ll r){
	cout << "? " << l << " " << r << endl;
	cin >> l;
	return l;
}

// Retorna o i
ll bb(ll n){
	ll l = 0, r = n, m;
	while(l < r - 1){
		m = (l + r)/2;
		if(ask(1, m) == 0) l = m;
		else r = m;
	}
	return l;
}

ll get(ll val){
	val *= 2;
	ll ini = (ll)ceil(sqrt((double) val + 1));
	while(ini * (ini - 1) > val) ini--;
	return ini;
}

void solve(){
	ll n;
	cin >> n;
	ll l = bb(n);

	ll tam = ask(l, n) - ask(l + 1, n) + 1;
	ll meio = l + tam;

	ll num1 = ask(meio, n);
	ll r = meio + get(num1) - 1;

	cout << "! " << l << " " << meio << " " << r << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--) solve();
}
