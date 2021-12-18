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

#define MAXN 9010
#define MOD 1000000007
#define INF 2000000000000000100

int fst[MAXN];
vector<pii> cur;
vector<int> pos[MAXN];
int n;

void solve(vector<int> & p, int x){
	int i = 0, j = 0;

	while(j < p.size()){
		while(i < cur.size() && cur[i].f < p[j]){
			fst[cur[i].s^x] = min(fst[cur[i].s^x], p[j]);
			i++;
		}
		j++;
	}

	cur.clear();
	fr(i, MAXN) if(fst[i] != MOD) cur.pb({fst[i], i});
	sort(all(cur));
}

signed main(){
	fastio;
	fr(i, MAXN) fst[i] = MOD;
	cur.pb({0, 0});
	fst[0] = 0;
	cin >> n;
	fr(i, n){
		int a;
		cin >> a;
		pos[a].pb(i + 1);
	}
	frr(i, 5000) solve(pos[i], i);
	vector<int> ans;
	fr(i, MAXN) if(fst[i] < MOD) ans.pb(i);

	cout<< ans.size() << endl;
	for(auto x: ans) cout<< x<< " ";
	cout<< endl;
}