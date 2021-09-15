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
#define INF 1000000000000000100

pii v[3];

signed main(){
	fastio;
	fr(i, 3 ) cin >> v[i].f, v[i].s = i+1;
	sort(v, v + 3);

	cout << "First" << endl;

	while(true){
		ll x = 2*v[2].f - v[0].f - v[1].f, p;
		cout << x << endl;
		cin >> p;

		if(v[2].s == p) v[2].f += x;
		else if(v[0].s == p){
			cout << v[2].f - v[1].f << endl;
			cin >> p;
			if(p != 0) assert(0);
			else break;
		}
		else{
			cout << v[2].f - v[0].f << endl;
			cin >> p;
			if(p != 0) assert(0);
			else break;
		}
	}

}
