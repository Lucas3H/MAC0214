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

#define MAXN 500010
#define MOD 1000000007
#define INF 2000000000000000100

stack<int> s;
int pr[MAXN];
vector<int> adj[MAXN];
vector<int> d[MAXN];
vector<int> ans;
int n, m;

void dfs(int v, int h){
	d[h].pb(v);
	pr[v] = 1;
	s.push(v);
	if((int)s.size() >= (n + 1)/2){
		ans.clear();
		while(s.size()){
			ans.pb(s.top());
			s.pop();
		}
		return;
	}

	for(auto x: adj[v]){
		if(!pr[x]){
			dfs(x, h + 1);
		}
	}
	if(s.size()) s.pop();
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		cin >> n >> m;
		frr(i, n) adj[i].clear(), pr[i] = 0, d[i].clear();
		while(s.size()) s.pop();
		ans.clear();

		fr(i, m){
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}


		dfs(1, 1);
		if(ans.size()){
			cout << "PATH" << endl;
			cout << ans.size() << endl;
			for(auto x: ans) cout << x << " ";
			cout << endl;
		}
		else{
			vector<pii> davez;
			frr(i, n){
				for(int j = 1; j < d[i].size(); j += 2){
					davez.pb({d[i][j - 1], d[i][j]});
				}
			}

			cout << "PAIRING" << endl;
			cout << davez.size() << endl;
			for(auto x: davez) cout << x.f << " " << x.s << endl;
		}
	}
}
