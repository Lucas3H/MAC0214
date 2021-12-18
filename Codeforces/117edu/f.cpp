#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = (int)n-1; i >= 0; i--)

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

set<pii> good;

signed main(){
	fastio;
	int q;
	cin >> n >> m >> q;
	fr(i, q){
		int a, b;
		cin >> a >> b;
		good.insert({a, b});
	}

	vector<pii> cur;
	cur.pb({1, 1});
	int ans = 0;

	while(cur.size()){
		vector<pii> nxt;
		for(auto x: cur){
			if(x == mp(n, m)){
				cout << ans << endl;
				return 0;
			}

			int sum = x.f + x.s;
			if(good.count(x)) sum++;
			nxt.pb({min(sum, n), x.s});
			nxt.pb({x.f, min(sum, m)});
		}

		ans++;

		sort(all(nxt));
		cur.clear();
		int maximo = 0;
		frm(i, (int)nxt.size()){
			if(nxt[i].s > maximo){
				cur.pb(nxt[i]);
				maximo = nxt[i].s;
			}
		}
	}
}
