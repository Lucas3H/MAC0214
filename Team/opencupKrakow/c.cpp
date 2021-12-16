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
#define INF 2000000000000000100

int n;
vector<int> adj[MAXN];
vector<int> cycle;
stack<int> aux;
int pr[MAXN];
int is_cycle[MAXN];

int find(int v, int p){
	aux.push(v);
	pr[v] = 1;
	
	for(auto x: adj[v]){
		if(x == p) continue;
		if(pr[x]){
			while(aux.top() != x){
				is_cycle[aux.top()] = 1;
				cycle.pb(aux.top());
				aux.pop();
			}
			cycle.pb(x);
			is_cycle[x] = 1;
			return 1;
		}
		else{
			if(find(x, v)) return 1;
		}
	}
	
	aux.pop();

	return 0;
}

int leafs(int v, int p){
	if(adj[v].size() == 1) return 1;
	int l = 0; 
	for(auto x : adj[v]){
		if(is_cycle[x]) continue;
		if(x != p) l += leafs(x, v);
	}
	return l;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		while(aux.size()) aux.pop();
		cycle.clear();

		cin >> n;
		frr(i, n) adj[i].clear(), pr[i] = is_cycle[i] = 0;
		
		frr(i, n){
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		find(1, -1);
		deque<int> vals, pos;
		int ans = 0;
		for(auto x: cycle) {
			int aux = leafs(x, x);
			vals.pb(aux);
			if(aux > 0) pos.pb(aux);
			ans += aux;
			// dbg(aux);
			// dbg(x);
		}

		if(pos.size() == 0) ans = 3;
		else if(pos.size() == 1) ans += 2;
		else{
			while(vals.front() == 0) {
				vals.pb(vals.front());
				vals.pop_front();
			}
			int i = 0, maximo = 0;
			while(i < vals.size()){
				int ini = i;
				i++;
				while(i < vals.size() && vals[i] == 0) i++;
				maximo = max(maximo, i - ini - 1);
			}

			ans += min(2, maximo);
		}
		cout<< ans << endl;

	}
}
