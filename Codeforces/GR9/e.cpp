#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 1010
#define MOD 1000000007
#define INF 1000000000000000100

int n;
pii a[MAXN];

vector<pii> ans;

void construct(int p){
	vector<pair<pii, int>> v;
	frr(i, p-1){
		if(a[i].f > a[p].f)
			v.pb({a[i], i});
		else if(a[i].f == a[p].f && a[p].s < a[i].s)
			v.pb({a[i], i});
	}

	sort(all(v));
	for(auto x: v){
		ans.pb({x.s, p});
		swap(a[x.s], a[p]);
	}
	// frr(i, n) cout << a[i].f << " ";
	// cout << endl;
}

signed main(){
	fastio;
	cin >> n;
	frr(i, n) cin >> a[i].f, a[i].s = i;
	for(int i = n; i >= 1; i--) construct(i);
	cout << ans.size() << endl;
	for(auto x: ans) cout << x.f << " " << x.s << endl;
}
