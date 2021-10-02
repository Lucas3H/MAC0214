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

#define MAXN 200010
#define MOD 1000000007
#define INF 1000000000000000100

int pai[MAXN];
int q[MAXN];
set<int> adj[MAXN];
vector<int> adj1[MAXN];
int last_small[MAXN];
int last_big[MAXN];
int n, m;

int big[MAXN];

void build_small(int v, int ind){
	pai[ind] = last_small[v];
	for(int x: adj1[v]){
		last_small[x] = ind;
		if(big[x])
			pai[ind] = max(pai[ind], last_big[x]);
	}
}

void build_big(int v, int ind){
	last_big[v] = ind;
	pai[ind] = last_small[v]; 
	for(int x: adj1[v]){
		if(big[x])
			pai[ind] = max(pai[ind], last_big[x]);
	}
} 

int find(int x){
	if(pai[x] == 0) return x;
	else return pai[x] = find(pai[x]);
}

signed main(){
	fastio;
	int nq;
	cin >> n >> m >> nq;
	fr(i, m){
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	frr(i, n){
		int t = adj[i].size();
		if(t * t > m) big[i] = 1;
	}

	frr(i, n){
		if(big[i]){
			set<int> aux = adj[i];
			for(auto x: aux){
				if(!big[x]) adj[i].erase(x);
			}
		}
		for(auto x: adj[i]) adj1[i].pb(x);
	}

	frr(i, nq){
		cin >> q[i];
		if(big[q[i]]) build_big(q[i], i);
		else build_small(q[i], i);
	}

	frr(i, n){
		int last = last_small[i];
		for(auto x: adj1[i]) {
			if(big[x]) last = max(last, last_big[x]);
		}
		if(last == 0) cout << i << " ";
		else cout << q[find(last)] << " ";
	}
	cout << endl;
}
