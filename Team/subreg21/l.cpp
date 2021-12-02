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

#define MAXN 600010
#define MOD 1000000007
#define INF 2000000000000000100

vector<pii> edges[30];
int n, m;

void add(int l1, int r1, int l2, int r2){
	int tam = r1 - l1 + 1;
	frm(i, 30){
		if((1 << i)&tam){
			edges[i].pb({l1, l2});
			l1 += (1 << i);
			l2 += (1 << i);
		}
	}
}

int sz[MAXN], pai[MAXN];

int find(int x){
	if(pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}

bool join(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return false;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	pai[b] = a;
	return true;
}

void pushAll(int s){
	frr(i, 2 * n) sz[i] = 1, pai[i] = i;
	for(auto x : edges[s - 1]) join(x.f, x.s);
	for(auto x: edges[s]){
		int u = x.f, v = x.s;
		if(join(u, v)) edges[s - 1].pb({u, v});
		
		if(join(u + (1 << (s - 1)), v + (1 << (s - 1)))){
			edges[s - 1].pb({u + (1 << (s - 1)), v + (1 << (s - 1))});
		}
	}
}

char c[MAXN];
void build(){
	cin >> n >> m;
	frr(i, n) cin >> c[i];
	for(int i = n + 1; i <= 2 * n; i++) c[i] = c[2 * n + 1 - i];
	fr(i, m){
		int l, r;
		cin >> l >> r;
		add(l, r, 2 * n + 1 - r, 2 * n + 1 - l);
	}
}

void solve(){
	for(int i = 29; i >= 1; i--) pushAll(i);

	for(int i = 1; i <= n; i++) join(i, 2 * n + 1 - i);

	fr(j, 2) frr(i, 2 * n){
		int p = find(i);
		if(c[i] == '?'){
			if(c[p] != '?') c[i] = c[p];
		}
		else{
			if(c[p] == '?') c[p] = c[i];
			else if(c[p] != c[i]){
				cout << 0 << endl;
				exit (0);
			}
		}
	} 
	set<int> choice;
	frr(i, 2 * n) if(c[i] == '?')choice.insert(find(i));
	ll ans = 1;
	fr(i, choice.size()) ans = ans * 2 % MOD;
	cout << ans << endl;
} 

signed main(){
	fastio;
	build();
	solve();
}
