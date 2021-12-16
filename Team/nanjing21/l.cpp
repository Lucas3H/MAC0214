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

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100

int n, m;
vector<pii> v, aux;

void solve(){
	cin >> n >> m;
	aux.clear(), v.clear();
	fr(i, n){
		int x;
		cin >> x;
		aux.pb({x, 1});
	}
	fr(i, m){
		int x;
		cin >> x;
		aux.pb({x, 0});
	}
	sort(all(aux));
	int i = 0;
	while(i < n + m){
		if(aux[i].s == 0) {
			v.pb(aux[i]);
			int ini = aux[i].f;
			while(i < n + m && aux[i].f == ini) i++;
		}
		else v.pb(aux[i++]);
	}

	i = 0;
	int ans = 0;
	while(i < v.size()){
		if(v[i].s == 0) i++;
		else{
			int ini = i;
			while(i < v.size() && v[i].s == 1) i++;
			ans = max(ans, i - ini);
		}
	}

	if(ans)cout << ans << endl;
	else cout << "Impossible" << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--) solve();
}
