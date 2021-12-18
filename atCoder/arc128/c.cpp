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

ll n, m, s;
vector<pii> a;

signed main(){
	cin >> n >> m >> s;
	fr(i, n){
		ll x;
		cin >>x;
		a.pb({x, 1});
	}
	while(a.size() > 1){
		bool ok = 1;
		fr(i, (ll)a.size() - 1){
			if(a[i].f * a[i + 1].s > a[i + 1].f * a[i].s){
				ok = 0;
				a[i].f += a[i + 1].f;
				a[i].s += a[i + 1].s;
				a.erase(a.begin() + i + 1, a.begin() + i + 2);
			}
		}
		if(ok) break;
	}

	double ans = 0.0, t = (double) s;
	frm(i, (ll)a.size()){
		double part = min(t / a[i].s, (double)m);
		ans += part * a[i].f;
		t -= part * a[i].s;
	}
	printf("%.12lf\n", ans);
}
