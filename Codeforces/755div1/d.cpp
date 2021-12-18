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

#define mem(v, k) memset(v, k, sizeof(v))
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

vector<pii> adj[60][(1 << 11)];
int inv[60][(1 << 11)], dist[60][(1 << 11)];
int pos[11][60][2];
pii pai[60][(1 << 11)];

void build_pos(int ind, vector<int> s){
	vector<int> nxt;
	nxt.resize(52, 0);

	fr(i, s.size()){
		pos[ind][s[i]][nxt[s[i]]] = i;
		nxt[s[i]]++;
	}
}

int n;

int get_nxt_mask(int mask, int cur_letter, int nxt_letter){
	int ret = 0;
	fr(i, n){
		int cur = (((1 << i) & mask) != 0);
		if(pos[i][nxt_letter][0] > pos[i][cur_letter][cur]) continue;
		else if(pos[i][nxt_letter][1] > pos[i][cur_letter][cur]) ret += (1 << i);
		else return -1;
	}
	return ret;
}

void build_adj(int cur_letter, int mask){
	adj[cur_letter][mask].clear();
	fr(nxt, 52){
		int m = (get_nxt_mask(mask, cur_letter, nxt));
		if(m != -1) {
			adj[cur_letter][mask].pb({nxt, m});
			inv[nxt][m]++;
		}
	}
}

bool is_valid(int letter, int mask){
	fr(i, n){
		int cur = (((1 << i) & mask) != 0);
		if(pos[i][letter][cur] == -1) return false;
	}
	return true;
}

vector<int> get_vector(string s){
	vector<int> v;
	for(auto x: s){
		if(x <= 'z' && x >= 'a') v.pb(x - 'a');
		else v.pb(x - 'A' + 26);
	}
	return v;
}

void solve(){
	mem(pos, -1); 
	mem(dist, 0);
	mem(inv, 0);
	fr(i, 60) fr(j, (1 << 10)) pai[i][j] = {-1, -1};

	cin >> n;
	fr(i, n){
		string s;
		cin >> s;
		build_pos(i, get_vector(s));
	}
	fr(i, 52) fr(j, (1 << n)) if(is_valid(i, j)) build_adj(i, j);

	queue<pii> fila;
	int ans = 0;
	pii ini = {-1, -1};
	fr(i, 52) fr(j, (1 << n)) {
		if(is_valid(i, j) && inv[i][j] == 0){
			fila.push({i, j});
			dist[i][j] = 1;
			ans = 1;
			ini = {i, j};
		}
	}

	while(fila.size()){
		pii davez = fila.front();
		fila.pop();

		for(auto x: adj[davez.f][davez.s]){
			inv[x.f][x.s]--;
			if(dist[x.f][x.s] < dist[davez.f][davez.s] + 1){
				pai[x.f][x.s] = {davez.f, davez.s};
				dist[x.f][x.s] = dist[davez.f][davez.s] + 1;
			}

			if(inv[x.f][x.s] == 0) {
				fila.push({x.f, x.s});
				if(ans < dist[x.f][x.s]){
					ans = dist[x.f][x.s];
					ini = {x.f, x.s};
				}
			}
		}
	}

	vector<char> lcs;

	while(ini.f != -1){
		if(ini.f >= 26) lcs.pb('A' + ini.f - 26);
		else lcs.pb('a' + ini.f);
		ini = pai[ini.f][ini.s];
	}
	cout << ans << endl;
	frm(i, (int)lcs.size()) cout << lcs[i];
	cout << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--) solve();
}
