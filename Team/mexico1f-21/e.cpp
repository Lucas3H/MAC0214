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

#define MAXN 1010
#define MOD 1000000007
#define INF 2000000000000000100

int mc[4] = {-1, 0, 1, 0};
int mr[4] = {0, 1, 0, -1};
char m[MAXN][MAXN];
int dist[MAXN][MAXN];
int r, c;

bool inside(int x, int y){
	if(m[x][y] == 'X' || m[x][y] == '#') return false;
	if(x >= 1 && x <= r && y >= 1 && y <= c) return true;
	else return false;
}

void bfs(int a, int b){
	queue<pii> fila;
	fila.push({a, b});
	dist[a][b] = 0;

	while(fila.size()){
		pii davez = fila.front();
		fila.pop();

		fr(i, 4){
			if(inside(davez.f + mr[i], davez.s + mc[i]) && \
				dist[davez.f + mr[i]][davez.s + mc[i]] == -1){
				dist[davez.f + mr[i]][davez.s + mc[i]] = dist[davez.f][davez.s] + 1;
				fila.push({davez.f + mr[i], davez.s + mc[i]});
			}
		}
	}
}

signed main(){
	fastio;
	mem(dist, -1);
	cin >> r >> c;
	pii e;
	frr(i, r) frr(j, c) {
		cin >> m[i][j];
		if(m[i][j] == 'E') e = {i, j};
	}
	bfs(e.f, e.s);

	int q;
	cin >> q;

	while(q--){
		int x, y;
		cin >> x >> y;
		if(m[x][y] == '#') cout << 'W' << endl;
		else if(m[x][y] == 'X') cout << 'X' << endl;
		else if(m[x][y] == 'E') cout << 'E' << endl;
		else if(dist[x][y] == -1) cout << '?' << endl;
		else{
			int ans = 0;
			fr(i, 4){
				if(inside(x + mr[i], y + mc[i]) && dist[x + mr[i]][y + mc[i]] < dist[x][y]){
					ans = i;
					break;
				}
			}
			if(ans == 0) cout << 'L' << endl;
			else if(ans == 1) cout << 'D' << endl;
			else if(ans == 2) cout << 'R' << endl;
			else cout << 'U' << endl;
		}
	}
}
