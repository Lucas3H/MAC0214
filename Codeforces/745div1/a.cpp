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

#define MAXN 410
#define MOD 1000000007
#define INF 2000000000000000100

deque<int> row[MAXN];
int row_acu[MAXN][MAXN];
int col_acu[MAXN][MAXN];
int ans = 16;
int n, m;
void solve_col(int x, int y, int c, set<int> & t, int sum){
	int prv = x;
	sum += c - y - 1 - (row_acu[x][c - 1] - row_acu[x][y]);
	for(auto davez: t){
		if(sum >= ans) break;
		sum += davez - 1 - prv - (col_acu[davez - 1][y] - col_acu[prv][y]);
		sum += davez - 1 - prv - (col_acu[davez - 1][c] - col_acu[prv][c]);

		ans = min(ans, sum + c - y - 1 - (row_acu[davez][c - 1] - row_acu[davez][y]));
		prv = davez;
		sum += (row_acu[davez][c - 1] - row_acu[davez][y]);
	}
}

void solve(int x, int y){
	deque<pii> fila;
	for(int i = x + 5; i <= n; i++){
		if(row[i].size()){
			if(row[i].front() >= y + 1) fila.pb({row[i].front(), i});
			if(row[i].front() == y + 1) row[i].pop_front();
		}
	}
	sort(all(fila));

	int sum = 0;
	sum += col_acu[x + 3][y + 1] - col_acu[x][y + 1];
	sum += col_acu[x + 3][y + 2] - col_acu[x][y + 2];
	set<int> t;
	t.insert(x + 4);
	for(int i = y + 3; i <= m; i++){
		while(fila.size() && fila.front().f < i){
			t.insert(fila.front().s);
			fila.pop_front();
			if(t.size() == 17){
				auto it = t.end();it--;
				t.erase(it);
			}
		}
		solve_col(x, y, i, t, sum);
		sum += col_acu[x + 3][i] - col_acu[x][i];
	}
}

int r[MAXN][MAXN];

deque<int> row_aux[MAXN];
signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		ans = 16;
		cin >> n >> m;
		frr(i, n) row[i].clear();
		frr(i, n) frr(j, m){
			char c;
			cin >> c;
			r[i][j] = c - '0';
			if(c == '1') row[i].pb(j);
		}

		frr(i, n) frr(j, m){
			row_acu[i][j] = row_acu[i][j - 1] + r[i][j];
			col_acu[i][j] = col_acu[i - 1][j] + r[i][j];
		}
		frr(i, n - 4) {
			frr(j, n) row_aux[j] = row[j];
			frr(j, m - 3) solve(i, j);
			frr(j, n) row[j] = row_aux[j];
		}
		cout << ans << endl;
	}
}
