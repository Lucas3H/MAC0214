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

ll h, w, c, q;
array<ifnt, 3> p[MAXN];
ll ans[MAXN];
set<ll> rows, columns;

signed main(){
	fastio;
	cin >> h >> w >> c >> q;
	fr(i, q) cin >> p[i][0] >> p[i][1] >> p[i][2];

	frm(i, q){
		if(p[i][0] == 1){
			if(rows.count(p[i][1])) continue;
			ans[p[i][2]] += w;
			h--;
			rows.insert(p[i][1]);
		}
		else{
			if(columns.count(p[i][1])) continue;
			ans[p[i][2]] += h;
			w--;
			columns.insert(p[i][1]);
		}
	}
	frr(i, c) cout << ans[i] << " ";
	cout << endl;
}
