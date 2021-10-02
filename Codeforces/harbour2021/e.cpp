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

#define MAXN 300010
#define MOD 1000000007
#define INF 2000000000000000100

int n, m;
int v[MAXN], fr[MAXN], pos[MAXN];
int nxt[MAXN], pr[MAXN];

void dfs(int i){
	int ini = i;
	while(nxt[i] != ini){
		pr[i] = 1;
		i = nxt[i];
	}
	pr[i] = 1;
}

bool test(int shift){
	frr(i, n) {
		int p = (i - shift + n)%n;
		if(p == 0) p = n;
//		cout << p << ' ';
		nxt[i] = pos[p], pr[i] = 0;
	}
	// cout << endl;
	// frr(i, n) cout << nxt[i] << ' ';
	// cout << endl;
	int ans = 0;
	frr(i, n){
		if(nxt[i] != i && !pr[i]) {
			ans--, dfs(i);
		}
		if(nxt[i] != i) ans++;
	}
	//dbg(ans);
	return ans <= m;
}

void solve(){
	cin >> n >> m;
	frr(i, n) cin >> v[i], pos[v[i]] = i;
	fr(i, n) fr[i] = 0;
	frr(i, n) fr[(i - v[i] + n)%n]++;

	vector<int> ans;
	fr(i, n){
		if(fr[i] >= n - 2*m){
			if(test(i)) ans.pb(i);
		}
	}
	cout << ans.size() << " ";
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;
	while(t--) solve();
}
