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

#define MAXN 20
#define MOD 1000000007
#define INF 2000000000000000100

ll k, n;
array<ll, 3> v[MAXN];
ll phi, tau;

ll maximo(){
	ll sum = 0;
	ll val = 0, ans = 0;
	fr(i, k) sum += v[i][1], val += v[i][0] * v[i][1];

	frm(i, k){
		sum -= v[i][1];
		val -= v[i][0] * v[i][1];
		ll resto = phi - sum;
		if(resto >= v[i][1] && resto <= v[i][2]){
			ans = max(ans, val + resto * v[i][0]);
		}

		sum += v[i][2];
		val += v[i][0] * v[i][2];
	}
	return ans;
}

ll minimo(){
	ll sum = 0;
	ll val = 0, ans = INF;
	fr(i, k) sum += v[i][2], val += v[i][0] * v[i][2];

	frm(i, k){
		sum -= v[i][2];
		val -= v[i][0] * v[i][2];
		ll resto = phi - sum;
		if(resto >= v[i][1] && resto <= v[i][2]){
			ans = min(ans, val + resto * v[i][0]);
		}

		sum += v[i][1];
		val += v[i][0] * v[i][1];
	}
	return ans;
}

signed main(){
	fastio;
	cin >> k;
	fr(i, k){
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}
	sort(v, v + k);
	cin >> n;
	fr(i, n){
		cin >> tau >> phi;
		// cout << minimo() << " " << maximo() << endl;
		// dbg(phi * tau);
		if(minimo() <= phi * tau && phi * tau <= maximo()){
			cout << "yes" << endl;
		}
		else cout << "no" << endl;
	}
}
