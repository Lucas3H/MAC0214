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

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100

char m[10][10];
pii eval[MAXN];
vector<int> adj[MAXN][2];
int n;

void build_edges(int m){
	vector<int> v;
	int M = m, p = 1;
	fr(i, n) v.pb(m%3), m /= 3;

	fr(i, n) {
		if(v[i] == 1) adj[M][0].pb(M - p * 1);
		else if(v[i] == 2) adj[M][1].pb(M - p * 2);
		else if(i < n - 1) {
			if(v[i + 1] == 1) adj[M][1].pb(M - 3 * p * 1 + p * 1);
			else if(v[i + 1] == 2) adj[M][1].pb(M - 3 * p * 2 + p * 2);
		}
		p *= 3;
	}
}

void get_val(int m){
	pii minimo = {INF, 1}, maximo = {-INF, 1};
	for(auto x : adj[m][0]){
		if(minimo.f * eval[x].s > minimo.s * eval[x].f) minimo = eval[x];
	}
	for(auto x : adj[m][1]){
		if(maximo.f * eval[x].s < maximo.s * eval[x].f) maximo = eval[x];
	}

	if(minimo.f * maximo.s < minimo.s * maximo.f) assert(0);

	if(minimo.f > 0 && maximo.f < 0) eval[m] = {0, 1};

	while(minimo.s < maximo.s) minimo.s *= 2, minimo.f *= 2;
	while(maximo.s < minimo.s) maximo.s *= 2, maximo.f *= 2;

	int p = 1;
	while(true){
		int den = -((-minimo.f - 1)/p + 1)
	}
}

signed main(){
	fastio;
	cin >> n;
	fr(i, 10000) build_edges(i);
	fr(i, n) fr(j, n) cin >> m[i][j];

	fr(i, 10000){

	}
}

