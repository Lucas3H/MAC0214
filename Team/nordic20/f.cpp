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

#define MAXN 200010
#define MOD 1000000007
#define INF 2000000000000000100
#define eps 0.000000001

ll a[MAXN];
deque<pii> pequenos, grandes;
ll n, m, k;

vector<ll> ans;

signed main(){
	fastio;
	// lembrar de botar ll
	cin >> n >> m >> k;
	frr(i, n) {
		cin >> a[i];
		pequenos.pb({a[i], i});
	}

	if(k%m != 0){
		cout << "impossible" << endl;
		return 0;
	}
	k = k / m;
	sort(all(pequenos));
	fr(i, k){
		grandes.pb(pequenos.back());
		pequenos.pop_back();
	}

	ll sum = 0;
	frr(i, n){
		if(grandes.size()){
			pii v = grandes.back();
			if(sum * m <= v.f * (i - 1)){
				grandes.pop_back();
				ans.pb(v.s);
				sum++;
				continue;
			}
		}
		if(pequenos.size()){
			pii v = pequenos.back();
			if(sum * m > v.f * (i - 1)){
				pequenos.pop_back();
				ans.pb(v.s);
				continue;
			}
		}

		cout << "impossible" << endl;
		return 0;
	}
	for(auto x: ans) cout << x << " ";
	cout << endl;
}
