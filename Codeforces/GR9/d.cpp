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
#define INF 1000000000000000100

set<int> pos[MAXN];
int a[MAXN];
int n;

int mex(){
	fr(i, n + 1) if(pos[i].size() == 0) return i;
	return n;
}

signed main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		fr(i, n+1) pos[i].clear();
		fr(i, n) cin >> a[i], pos[a[i]].insert(i);

		vector<int> ans;
		set<int> not_fixed;
		fr(i, n) if(a[i] != i) not_fixed.insert(i);
		fr(i, n){
			int m = mex();
			if(m < n){
				pos[a[m]].erase(m);
				a[m] = m;
				pos[a[m]].insert(m);
				not_fixed.erase(m);
				ans.pb(m + 1);
			}
			else{
				if(not_fixed.size()){
					int x = *(not_fixed.begin());
					int v = *(pos[x].begin());
					pos[a[v]].erase(v);
					a[v] = m;
					pos[a[v]].insert(v);
					ans.pb(v+1);

					m = mex();
					pos[a[m]].erase(m);
					a[m] = m;
					pos[a[m]].insert(m);
					ans.pb(m + 1);

					not_fixed.erase(x);
				}
				else break;
			}
		}
		cout << ans.size() << endl;
		for(auto x: ans) cout << x << ' ';
		cout << endl;
	}
}
