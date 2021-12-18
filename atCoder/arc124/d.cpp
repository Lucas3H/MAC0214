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

#define MAXN 200010
#define MOD 1000000007
#define INF 2000000000000000100

int n, m;
int a[MAXN], pr[MAXN];

pii dfs(int ini){
	int i = a[ini];
	pii v = {0, 0};
	if(ini <= n) v.f++;
	else v.s++;

	pr[ini] = 1;
	while(i != ini){
		if(i <= n) v.f++;
		else v.s++;
		pr[i] = 1;
		i = a[i];
	}

	return v;
}

signed main(){
	fastio;
	cin >> n >> m;
	frr(i, n + m) cin >> a[i];

	vector<pii> t[3];
	
	int ans = n + m;

	frr(i, n + m){
		if(!pr[i]){
			pii p = dfs(i);
			if(p.f == 0) {
				if(p.s == 1) ans--;
				else t[2].pb(p);
			}
			else if(p.s == 0) {
				if(p.f == 1) ans--; 
				else t[0].pb(p);
			}
			else t[1].pb(p);
		}
	}

	ans += max(t[0].size(), t[2].size());
	if(t[0].size() > 0 && t[2].size() > 0){
		ans -= min(t[0].size(), t[2].size());
	
	}
	ans -= t[1].size();
	cout << ans << endl;
}
