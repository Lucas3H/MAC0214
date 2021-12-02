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

set<pii> s;
int ans[MAXN],t[MAXN];
int p[MAXN];
int n, m;

void solve(int ind){
	int nxt = -ind;
	auto it = s.lower_bound({nxt, -1});
	while(it != s.end()){
		// dbg((*it).f);
		// dbg(nxt);	
		if((*it).f < nxt + p[ind]){
			ans[(*it).s] = ind;
			nxt = (*it).f + p[ind] + 1; // talvez tenha um mais um
			s.erase(it);
		}
		else nxt = nxt + 2 * p[ind];
		it = s.lower_bound({nxt, -1});
	}
}

signed main(){
	fastio;
	cin >> n >> m;
	fr(i, n) cin >> p[i];
	fr(i, m){
		ans[i] = -1;
		cin >> t[i];
		s.insert({t[i], i});
	}
	fr(i, n) solve(i);
	fr(i, m){
		if(ans[i] == -1) cout << -1 << " " << -1 << endl;
		else cout << ans[i] << ' ' << t[i] + ans[i] << endl;
	}
}
