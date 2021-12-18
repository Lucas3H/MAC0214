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

#define MAXN 300010
#define MOD 1000000007
#define INF 2000000000000000100

struct SEG{
	pii nd[4*MAXN];
	int v[MAXN];
	int n;

	pii op(pii a, pii b){
		if(a > b) return b;
		else return a;
	}

	void build(int i, int l, int r){
		if(l == r) nd[i] = mp(v[l], l);
		else{
			int m = (l + r)/2;
			build(2*i, l, m);
			build(2*i + 1, m + 1, r);
			nd[i] = op(nd[2*i], nd[2*i + 1]);
		}
	}

	pii query(int i, int l, int r, int ql, int qr){
		if(ql > r || l > qr) return {MOD, MOD};
		else if(ql <= l && r <= qr) return nd[i];
		else{
			int m = (l + r)/2;
			return op(query(2*i, l, m, ql, qr), query(2*i + 1, m + 1, r, ql, qr));
		}
	}
	void update(int i, int l, int r, int pos, int val){
		if(l == r){
			nd[i] = mp(val, pos);
		}
		else{
			int m = (l + r)/2;
			if(pos <=m) update(2*i, l, m, pos, val);
			else update(2*i + 1, m + 1, r, pos, val);
			nd[i] = op(nd[2*i], nd[2*i + 1]);
		}
	}

	SEG(int n, int a[]){
		n = n;
		frr(i, n) v[i] = a[i];
	}
	SEG() {};
};

int n;
int v[MAXN];
int dist[MAXN], pai[MAXN], b[MAXN];
SEG s;
vector<int> adj[MAXN];


signed main(){
	fastio;
	mem(dist, -1);

	cin >> n;
	queue<int> fila;
	
	frr(i, n) {
		int a;
		cin >> a;
		if(i == a){
			dist[i] = 1;
			pai[i] = 0;
			v[i] = MOD;
			fila.push(i);
		}
		else v[i] = i - a;
	}
	s = SEG(n, v);
	s.build(1, 1, n);
	frr(i, n) {
		cin >> b[i], adj[i + b[i]].pb(i);
	}
	pii q;
	int davez;


	while(fila.size()){
		davez = fila.front();
		fila.pop();
		for(auto x: adj[davez]){
			q = s.query(1, 1, n, x + 1, n);
			while(q.f <= x){
				dist[q.s] = dist[davez] + 1;
				pai[q.s] = x;

				fila.push(q.s);
				s.update(1, 1, n, q.s, MOD);
				q = s.query(1, 1, n, x + 1, n);
			}
		}
	}

	cout << dist[n] << endl;
	if(dist[n] >= 0){
		int it = pai[n];
		while(it != 0){
			cout << it << " ";
			it += b[it];
			it = pai[it];
		}
		cout << 0 << endl;
	}

}
