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

#define MAXN 500010
#define MOD 1000000007
#define INF 2000000000000000100


int pai[MAXN];
int sz[MAXN], cor[MAXN];
int n, m;
vector<int> adj_cur[MAXN];
vector<int> ans;

int find(int x){
	if(x == pai[x]) return x;
	else return pai[x] = find(pai[x]);
}

void dfs(int v, int p){
	for(auto x: adj_cur[v]){
		if(x != p){
			cor[x] = 1 - cor[v];
			dfs(x, v);
		}
	}
}

void acaba(){
	sort(all(ans));
	if(ans.size() == 0){
		cout << "IMPOSSIBLE" << endl;
	}
	else{
		for(auto x: ans) cout << x << endl;
	}	
	exit (0);
}

void join(int a, int b){
	int A = a, B = b;
	a = find(a), b = find(b);
	if(a == b){
		if(cor[A] == cor[B]) acaba();
		return;
	}
	if(sz[a] < sz[b]) {
		swap(a, b);
		swap(A, B);
	}
	
	if(cor[A] == cor[B]){
		cor[B] = 1 - cor[B];
		dfs(B, 0);
	}

	adj_cur[A].pb(B);
	adj_cur[B].pb(A);
	
	sz[a] += sz[b];
	pai[b] = a;
}

pii get_par(int x){
	int c = cor[x];
	return mp(find(x), c);
}

deque<pair<int, pii>> edges; 

void tenta(){
	int val = edges.front().f;

	// Pega todos os caras de mesmo valor
	vector<pii> davez;
	fr(i, edges.size()){
		if(edges[i].f == val) {
			pii a = get_par(edges[i].s.f), b = get_par(edges[i].s.s);
			if(a.f == b.f && a.s != b.s) continue;
			davez.pb(edges[i].s);
		}
		else break;
	}

	if(davez.size() == 0) return; 

	// Caso 1: tem mais de 1 cara no mesmo par {componente, cor}
	set<pii> s;
	for(auto x: davez){
		pii p1 = get_par(x.f), p2 = get_par(x.s);
		
		if(p1 == p2) s.insert(p1);
	}
	if(s.size() >= 2){
		ans.pb(val);
		return;
	}

	// Caso 2: tem somente 1 cara no mesmo par {componente, cor}
	// Se tiver uma aresta tal que ambas as extremidades são dintintas desse
	if(s.size() == 1){
		pii par = *(s.begin());

		for(auto x: davez){
			pii p1 = get_par(x.f), p2 = get_par(x.s);
	
			if(par != p1 && par != p2){
				ans.pb(val);
				return;
			}
		}
		return;
	}

	pii A = get_par(davez[0].f), B = get_par(davez[0].s);

	set<pii> ligadosA, ligadosB;
	frr(i, (int)davez.size() - 1){
		pii a = get_par(davez[i].f), b = get_par(davez[i].s);
		
		if((a == A && b == B) || (a == B && b == A)) continue;
		if(a == b) continue;

		if(a == A) ligadosA.insert(b);
		else if(b == A) ligadosA.insert(a);
		else if(b == B) ligadosB.insert(a);
		else if(a == B) ligadosB.insert(b);
		else{
			ans.pb(val);
			return;
		}
	}

	// É estrela
	if(ligadosA.size() == 0 || ligadosB.size() == 0) return;

	// É triângulo
	if(ligadosA.size() == 1 && ligadosB.size() == 1){
		if(*(ligadosA.begin()) == *(ligadosB.begin())) return;
	}

	ans.pb(val);
}

void coloca(){
	int ini = edges.front().f;
	while(edges.size() && edges.front().f == ini){
		pii davez = edges.front().s;
		join(davez.f, davez.s);
		edges.pop_front();
	}
}

bool comp(pair<int, pii> a, pair<int, pii> b){
	return a > b;
}
signed main(){
	fastio;
	cin >> n >> m;
	frr(i, n){
		pai[i] = i;
		sz[i] = 1;
	}
	fr(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		edges.pb({c, {a, b}});
	}
	sort(all(edges), comp);

	while(edges.size()) {
		tenta();
		coloca();
	}

	ans.pb(0);
	acaba();
}
