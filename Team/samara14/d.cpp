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

vector<pii> adj[MAXN][MAXN];
char m[MAXN][MAXN];
int maior[MAXN];
pii maior_par[MAXN];

int r, c, v;

void build1(){
	auto f = [&](int i, int j) { return i + j;};
	
	frr(i, c) maior[i] = -MOD;
	frr(i, c) maior_par[i] = {-1, -1};
	for(int i = 1; i <= r; i++){
		int maior_davez = -MOD;
		pii p = {-1, -1};
		for(int j = 1; j <= c; j++){
			if(m[i][j] == '.') continue;
			if(maior_davez < maior[j]) {
				maior_davez = maior[j];
				p = maior_par[j];
			}

			if(f(i, j) - maior_davez <= v) {
				adj[i][j].pb(p);
			}
			if(maior_davez < f(i, j)){
				maior_davez = f(i, j);
				p = {i, j};
			}

			maior[j] = maior_davez;
			maior_par[j] = p;
		}
	}
}

void build2(){	
	auto f = [&](int i, int j) { return i + c + 1 - j;};

	frr(i, c) maior[i] = -MOD;
	frr(i, c) maior_par[i] = {-1, -1};
	for(int i = 1; i <= r; i++){
		int maior_davez = -MOD;
		pii p = {-1, -1};
		for(int j = c; j >= 1; j--){
			if(m[i][j] == '.') continue;
			if(maior_davez < maior[j]) {
				maior_davez = maior[j];
				p = maior_par[j];
			}

			if(f(i, j) - maior_davez <= v) {
				adj[i][j].pb(p);
			}
			if(maior_davez < f(i, j)){
				maior_davez = f(i, j);
				p = {i, j};
			}

			maior[j] = maior_davez;
			maior_par[j] = p;
		}
	}
}

void build3(){
	auto f = [&](int i, int j) { return (r + 1 - i) + j;};
	
	frr(i, c) maior[i] = -MOD;
	frr(i, c) maior_par[i] = {-1, -1};
	for(int i = r; i >= 1; i--){
		int maior_davez = -MOD;
		pii p = {-1, -1};
		for(int j = 1; j <= c; j++){
			if(m[i][j] == '.') continue;
			if(maior_davez < maior[j]) {
				maior_davez = maior[j];
				p = maior_par[j];
			}

			if(f(i, j) - maior_davez <= v) {
				adj[i][j].pb(p);
			}
			if(maior_davez < f(i, j)){
				maior_davez = f(i, j);
				p = {i, j};
			}

			maior[j] = maior_davez;
			maior_par[j] = p;
		}
	}
}

void build4(){	
	auto f = [&](int i, int j) { return (r + 1 - i) + c + 1 - j;};

	frr(i, c) maior[i] = -MOD;
	frr(i, c) maior_par[i] = {-1, -1};
	for(int i = r; i >= 1; i--){
		int maior_davez = -MOD;
		pii p = {-1, -1};
		for(int j = c; j >= 1; j--){
			if(m[i][j] == '.') continue;
			if(maior_davez < maior[j]) {
				maior_davez = maior[j];
				p = maior_par[j];
			}

			if(f(i, j) - maior_davez <= v) {
				cout << i << " " << j << " | " << p.f << " " << p.s << endl; 
				adj[i][j].pb(p);
			}
			if(maior_davez < f(i, j)){
				maior_davez = f(i, j);
				p = {i, j};
			}

			maior[j] = maior_davez;
			maior_par[j] = p;
		}
	}
}

pii ini, fim;
int pr[MAXN][MAXN];
void dfs(pii a){
	pr[a.f][a.s] = 1;
	if(abs(a.f - fim.f) + abs(a.s - fim.s) <= v){
		cout << "Hello, Deimos!" << endl;
		exit (0);
	}
	for(auto p : adj[a.f][a.s]){
		if (!pr[p.f][p.s]) dfs(p);
	}
}

signed main(){
	fastio;
	cin >> r >> c >> v;
	cin >> ini.f >> ini.s >> fim.f >> fim.s;
	frr(i, r) frr(j, c) cin >> m[i][j];
	build1(), build2(), build3(), build4();
	dfs(ini);
	cout << "Dire victory" << endl;
}
