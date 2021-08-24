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

#define mp make_pair
#define pq priority_queue

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

int n;
set<int> adj[MAXN];
int marked[MAXN];

int find(){
	int ans = 0;
	frr(i, n){
		if(adj[i].size() > adj[ans].size()) ans = i;
	}
	return ans;
}

void dfs(int u){
	marked[u] = 1;
	for(auto x: adj[u]){
		if(!marked[x]) dfs(x);
	}
}

void eliminate(){
	frr(i, n){
		if(!marked[i]) adj[i].clear();
		marked[i] = 0;
	}
}

int ask(int u, int v){
	cout << "? " << u << " " << v << endl;
	int x;
	cin >> x;
	return x;
}

int main(){
	fastio;
	cin >> n;
	fr(i, n-1){
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	int davez, ans;
	while(true){
		davez = find();
		if(davez == 0) break;
		
		vector<int> aux;
		for(int x : adj[davez]) aux.pb(x);
		
		if(aux.size() == 1){
			int x = ask(davez, aux.back());
			cout << "! " << x << endl;
			return 0;
		}

		int x = ask(aux[0], aux[1]);
		if(x == aux[0]){
			adj[aux[0]].erase(davez);
			dfs(aux[0]);
			eliminate();
			ans = aux[0];
		}
		else if(x == aux[1]){
			adj[aux[1]].erase(davez);
			dfs(aux[1]);
			eliminate();
			ans = aux[1];	
		}
		else{
			adj[davez].erase(aux[0]);
			adj[davez].erase(aux[1]);
			dfs(davez);
			eliminate();
			ans = davez;
		}
	}
	cout << "! " << ans << endl;
}
