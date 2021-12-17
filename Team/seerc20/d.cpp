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

#define MAXN 10010
#define MOD 1000000007
#define INF 2000000000000000100

vector<pii> ans;
deque<int> pilha[MAXN];
int n;

void apply(int a, int b){
	pilha[b].pb(pilha[a].back());
	pilha[a].pop_back();
	ans.pb({a, b});
}

void ordena(vector<int> & p, int davez){
	if(p.size() == 3){
		if(pilha[p[0]][2] != davez && pilha[p[1]][2] == davez) swap(p[0], p[1]);
		if(pilha[p[0]][2] != davez && pilha[p[2]][2] == davez) swap(p[0], p[2]);
		if(pilha[p[1]][2] != davez && pilha[p[2]][2] == davez) swap(p[1], p[2]);
		if(pilha[p[1]][0] == davez && pilha[p[2]][1] == davez) swap(p[1], p[2]);
	}
	else{		
		if(pilha[p[1]][2] == davez && pilha[p[1]][1] == davez) swap(p[0], p[1]);
		if(pilha[p[1]][2] == davez && pilha[p[1]][0] == davez) swap(p[0], p[1]);
		if(pilha[p[0]][2] != davez && pilha[p[1]][2] == davez) swap(p[0], p[1]);
	}
}

int get(){
	int ok = 0;
	frr(i, n + 1){
		if(pilha[i].size() == 0) continue;
		if(pilha[i][0] == pilha[i][1] && pilha[i][1] == pilha[i][2]) ok++;
	}
	return ok;
}

int processa(vector<int> p, int davez){
	if(p.size() == 4){
		vector<array<int, 2>> v;
		if(pilha[p[1]][2] == davez){
			if(pilha[p[2]][2] == davez){
				v = {{1, 4}, {2, 4}, {3, 4}, {3, 1}, {3, 2}};
			}
			else if(pilha[p[2]][1] == davez){
				v = {{1, 4}, {2, 4}, {3, 2}, {3, 4}, {3, 1}};
			}
			else{
				v = {{1, 4}, {2, 4}, {3, 1}, {3, 2}, {3, 4}};
			}
		}
		else if(pilha[p[1]][1] == davez){
			if(pilha[p[2]][1] == davez){
				v = {{1, 4}, {2, 1}, {2, 4}, {3, 2}, {3, 4}, {3, 2}};
			}
			else{
				v = {{1, 4}, {2, 1}, {2, 4}, {3, 2}, {3, 2}, {3, 4}};
			} 
		}
		else{
			v = {{2, 4}, {2, 4}, {1, 2}, {3, 1}, {3, 4}, {3, 2}};
		}
		int tot = get();
		for(auto x : v) apply(p[x[0] - 1], p[x[1] - 1]);
		if(tot == get()) {
			assert(0); 
		}
		return p[2];
	}
	else{
		vector<array<int, 2>> v;
		
		if(pilha[p[0]][1] == davez){
			if(pilha[p[1]][2] == davez){
				v = {{0, 2}, {0, 2}, {1, 2}, {1, 0}, {1, 0}};
				// p[1]
			}
			else if(pilha[p[1]][1] == davez){
				v = {{0, 2}, {0, 2}, {1, 0}, {1, 2}, {1, 0}};
				// p[1]
			}
			else{
				v = {{0, 2}, {0, 2}, {1, 0}, {1, 0}, {1, 2}};
				// p[1]
			}
			for(auto x : v) apply(p[x[0]], p[x[1]]);
			return p[1];
		}
		else if(pilha[p[0]][0] == davez){
			if(pilha[p[1]][2] == davez){
				v = {{0, 2}, {1, 2}, {0, 1}, {0, 2}};
				// p[0]
				for(auto x : v) apply(p[x[0]], p[x[1]]);
				return p[0];
			}
			else if(pilha[p[1]][1] == davez){
				v = {{1, 2}, {0, 1}, {0, 2}, {1, 0}, {1, 0}, {1, 2}};
				// p[1]
				for(auto x : v) apply(p[x[0]], p[x[1]]);
				return p[1];
			}
			else{
				v = {{1, 2}, {1, 2}, {0, 1}, {0, 2}, {0, 1}};
				// p[0]
				for(auto x : v) apply(p[x[0]], p[x[1]]);
				return p[0];
			}
		}
		else{
			v = {{0, 2}, {1, 0}, {2, 1}};
			// p[2];
			for(auto x : v) apply(p[x[0]], p[x[1]]);
			return p[2];
		}
	}
}

vector<int> get_pilhas(int & davez){
	int i = 1;
	
	while(i <= n + 1 && (pilha[i].size() == 0 || (pilha[i][2] == pilha[i][1] && pilha[i][2] == pilha[i][0]))){
		i++;
	} 
	vector<int> ret;
	if(i > n + 1) return ret;
	davez = pilha[i][2];
	while(i <= n + 1){
		if(pilha[i].size() == 0){
			i++;
			continue;
		}
		if(pilha[i][2] == davez || pilha[i][1] == davez || pilha[i][0] == davez) ret.pb(i);
		i++;
	}
	return ret;
}

signed main(){
	fastio;
	cin >> n;
	fr(j, 3) frr(i, n){
		int x;
		cin >> x;
		pilha[i].push_front(x);
	}

	vector<int> p;
	int vazio = n + 1;
	while(true){
		int davez = -1;
		p = get_pilhas(davez);
		if(p.size() == 0) break;
		ordena(p, davez);
		p.pb(vazio);
		vazio = processa(p, davez);
	}
	if(vazio != n + 1) fr(i, 3) apply(n + 1, vazio);
	cout << ans.size() << endl;
	for(auto x: ans) cout << x.f << ' ' << x.s << endl;
}
