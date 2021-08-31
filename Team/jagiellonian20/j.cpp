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

#define MAXN 1000010
#define MOD 1000000007
#define INF 1000000000000000100

pair<vector<int>, bool> dir[3][3][MAXN];
map<array<int, 3>, int> m;

struct DSU{
	vector<int> pai, sz;
	DSU(){
	}
	DSU(int n){
		pai = vector<int>(n+1, 0);
		sz = vector<int>(n+1, 1);
		for(int i = 1; i <= n; i++) pai[i] = i;
	}

	int find(int x){
		if(pai[x] == x) return x;
		else return pai[x] = find(pai[x]);
	}
	void join(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		if(sz[a] < sz[b]) swap(a, b);
		pai[b] = a, sz[a] += sz[b];
	}
};

DSU d;
void join(int ind, pair<vector<int>, bool> & v){
	if(v.f.size()) d.join(ind, v.f[0]);
	if(v.s) return;
	v.s = true;
	for(int i = 0; i < (int)v.f.size() - 1; i++) {
		d.join(v.f[i], v.f[i+1]);
	}
}

int x[MAXN], y[MAXN], z[MAXN];

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		m.clear();
		fr(i, MAXN) fr(j, 3) fr(k, 3){
			dir[j][k][i].f.clear();
			dir[j][k][i].s = false;
		}
		
		int n;
		cin >> n;
		frr(i, n){
			cin >> x[i] >> y[i] >> z[i];
			if(x[i] == -1) dir[1][2][z[i]].f.pb(i), dir[2][1][y[i]].f.pb(i);
			else if(y[i] == -1) dir[0][2][z[i]].f.pb(i), dir[2][0][x[i]].f.pb(i);
			else dir[1][0][x[i]].f.pb(i), dir[0][1][y[i]].f.pb(i);
			m[{x[i], y[i], z[i]}] = i;
		}
		d = DSU(n);
		frr(i, n){
			int v;
			if(x[i] == -1){
				if((v = m[{-1, y[i] - 1, z[i]}])) d.join(i, v);
				if((v = m[{-1, y[i] + 1, z[i]}])) d.join(i, v);
				if((v = m[{-1, y[i], z[i] - 1}])) d.join(i, v);
				if((v = m[{-1, y[i], z[i] + 1}])) d.join(i, v);

				join(i, dir[0][1][y[i] - 1]);
				join(i, dir[0][1][y[i]]);
				join(i, dir[0][1][y[i] + 1]);


				join(i, dir[0][2][z[i] - 1]);
				join(i, dir[0][2][z[i]]);
				join(i, dir[0][2][z[i] + 1]);
			}
			else if(y[i] == -1){
				if((v = m[{x[i] - 1, -1, z[i]}])) d.join(i, v);
				if((v = m[{x[i] + 1, -1, z[i]}])) d.join(i, v);
				if((v = m[{x[i], -1, z[i] - 1}])) d.join(i, v);
				if((v = m[{x[i], -1, z[i] + 1}])) d.join(i, v);

				join(i, dir[1][0][x[i] - 1]);
				join(i, dir[1][0][x[i]]);
				join(i, dir[1][0][x[i] + 1]);


				join(i, dir[1][2][z[i] - 1]);
				join(i, dir[1][2][z[i]]);
				join(i, dir[1][2][z[i] + 1]);
			}
			else{
				if((v = m[{x[i] - 1, y[i], -1}])) d.join(i, v);
				if((v = m[{x[i] + 1, y[i], -1}])) d.join(i, v);
				if((v = m[{x[i], y[i] - 1, -1}])) d.join(i, v);
				if((v = m[{x[i], y[i] + 1, -1}])) d.join(i, v);

				join(i, dir[2][0][x[i] - 1]);
				join(i, dir[2][0][x[i]]);
				join(i, dir[2][0][x[i] + 1]);


				join(i, dir[2][1][y[i] - 1]);
				join(i, dir[2][1][y[i]]);
				join(i, dir[2][1][y[i] + 1]);
			}
		}

		int q;
		cin >> q;

		while(q--){
			int v[3], u[3];
			fr(i, 3) cin >> v[i];
			fr(i, 3) cin >> u[i];

			int a, b;
			if(m[{v[0], v[1], -1}]) a = m[{v[0], v[1], -1}];
			else if(m[{v[0], -1, v[2]}]) a = m[{v[0], -1, v[2]}];
			else a = m[{-1, v[1], v[2]}];

			if(m[{u[0], u[1], -1}]) b = m[{u[0], u[1], -1}];
			else if(m[{u[0], -1, u[2]}]) b = m[{u[0], -1, u[2]}];
			else b = m[{-1, u[1], u[2]}];

			//cout << a << " " << b << endl;

			if(d.pai[a] == d.pai[b]) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
