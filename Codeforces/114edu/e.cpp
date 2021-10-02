#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_ll_distribution<ll>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 1000010
#define MOD 998244353
#define INF 2000000000000000100

/*
	[lin][0 ou 1][col%2]
*/
ll lin[MAXN][2][2], col[MAXN][2][2];
ll n, m, t;
ll p[MAXN];
map<pii, ll> vals;
set<pii> aux;

ll linhas_ruins = 0, colunas_ruins = 0;
/*
	0 -> (linha + coluna par => 0 na casa/linhas + coluna impar => 1 na casa)
	1 -> (linha + coluna par => 1 na casa/linhas + coluna impar => 0 na casa)
*/
ll linhas_ocupadas[2], colunas_ocupadas[2];

bool livre(ll v, ll tipo, ll paridade){
	ll t = 0;
	if(tipo == 0){
		fr(i, 2) fr(j, 2) if((v+i+j - paridade)%2 == 0)t += lin[v][i][j];
	}
	else{
		fr(i, 2) fr(j, 2) if((v+i+j - paridade)%2 == 0)t += col[v][i][j];
	}
	return t == 0;
}

bool ruim(ll v, ll tipo){
	if(tipo == 0){
		if(lin[v][0][0] > 0 && lin[v][0][1] > 0) return true;
		if(lin[v][1][0] > 0 && lin[v][1][1] > 0) return true;
		if(lin[v][1][0] > 0 && lin[v][0][0] > 0) return true;
		if(lin[v][1][1] > 0 && lin[v][0][1] > 0) return true;
	}
	else{
		if(col[v][0][0] > 0 && col[v][0][1] > 0) return true;
		if(col[v][1][0] > 0 && col[v][1][1] > 0) return true;
		if(col[v][1][0] > 0 && col[v][0][0] > 0) return true;
		if(col[v][1][1] > 0 && col[v][0][1] > 0) return true;
	}
	return false;
}

void tira(ll a, ll b){
	if(!aux.count({a, b})) return;
	ll c = vals[{a, b}];
	if(!livre(a, 0, (a + b + c)%2)) linhas_ocupadas[(a + b + c)%2]--;
	if(ruim(a, 0)) linhas_ruins--;

	// dbg(linhas_ruins);
	// dbg(colunas_ruins);

	lin[a][c][b%2]--;
	if(!livre(a, 0, (a + b + c)%2)) linhas_ocupadas[(a + b + c)%2]++;
	if(ruim(a, 0)) linhas_ruins++;

	if(!livre(b, 1, (a + b + c)%2)) colunas_ocupadas[(a + b + c)%2]--;
	if(ruim(b, 1)) colunas_ruins--;

	col[b][c][a%2]--;
	if(!livre(b, 1, (a + b + c)%2)) colunas_ocupadas[(a + b + c)%2]++;
	if(ruim(b, 1)) colunas_ruins++;
	aux.erase({a, b});
}

void add(ll a, ll b, ll c){
	if(aux.count({a, b})) tira(a, b);
	// dbg(linhas_ocupadas[0]);
	// dbg(linhas_ocupadas[1]);
	// dbg(colunas_ocupadas[0]);
	// dbg(colunas_ocupadas[1]);
	if(!livre(a, 0, (a + b + c)%2)) linhas_ocupadas[(a + b + c)%2]--;
	if(ruim(a, 0)) linhas_ruins--;
	lin[a][c][b%2]++;
	if(!livre(a, 0, (a + b + c)%2)) linhas_ocupadas[(a + b + c)%2]++;
	if(ruim(a, 0)) linhas_ruins++;

	if(!livre(b, 1, (a + b + c)%2)) colunas_ocupadas[(a + b + c)%2]--;
	if(ruim(b, 1)) colunas_ruins--;

	col[b][c][a%2]++;
	if(!livre(b, 1, (a + b + c)%2)) colunas_ocupadas[(a + b + c)%2]++;
	if(ruim(b, 1)) colunas_ruins++;

	vals[{a, b}] = c;
	aux.insert({a, b});
}

ll solve(){
	if(linhas_ruins > 0 && colunas_ruins > 0) return 0;
	else if(colunas_ruins > 0){
		return p[n - linhas_ocupadas[0] - linhas_ocupadas[1]];
	}
	else if(linhas_ruins > 0){
		return p[m - colunas_ocupadas[0] - colunas_ocupadas[1]];
	}
	else{
		ll ans = p[n - linhas_ocupadas[0] - linhas_ocupadas[1]];
		ans = (ans + p[m - colunas_ocupadas[0] - colunas_ocupadas[1]])%MOD;
		if(colunas_ocupadas[0] == 0 && linhas_ocupadas[0] == 0) ans--;
		if(colunas_ocupadas[1] == 0 && linhas_ocupadas[1] == 0) ans--;
		return (ans + MOD) % MOD;
	}
}

signed main(){
	fastio;
	p[0] = 1;
	frr(i, MAXN - 1) p[i] = p[i-1] * 2 % MOD;
	cin >> n >> m >> t;	
	fr(i, t){
		ll a, b, c;
		a--, b--;
		cin >> a >> b >> c;
		if(c == -1) tira(a, b);
		else add(a, b, c);
		cout << solve() << endl;
	}
}
