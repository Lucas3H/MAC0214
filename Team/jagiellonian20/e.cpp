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

#define MAXN 4000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

map<int, int> m;
int n, q;
int nd[4*MAXN];

void build(int i, int l, int r){
	nd[i] = MOD;
	if(l < r){
		int m = (l + r)/2;
		build(2*i, l, m);
		build(2*i + 1, m + 1, r);
	}
}

void update(int i, int l, int r, int pos, int val){
	if(l == r){
		nd[i] = val;
	}
	else{
		int m = (l + r)/2;
		if(pos <= m)update(2*i, l, m, pos, val);
		else update(2*i + 1, m + 1, r, pos, val);
		nd[i] = min(nd[2*i], nd[2*i + 1]);
	}
}

int query(int i, int l, int r, int ql, int qr){
	if(ql > r || l > qr) return MOD;
	else if(ql <= l && r <= qr) return nd[i];
	else{
		int m = (l + r)/2;
		return min(query(2*i, l, m, ql, qr), query(2*i + 1, m + 1, r, ql, qr));
	}
}

map<int, int> id;
vector<pii> y_coord;
int l[MAXN], r[MAXN];

void coordinate_compression(vector<array<int, 4>> & qu){
	for(auto x: qu){
		if(x[1] == q) {
			y_coord.pb({x[2], 0});
			y_coord.pb({x[3], MOD});
		}
		else if(x[1] < q){
			y_coord.pb({x[2], x[1]});
			y_coord.pb({x[3], x[1] + q});
		}
	}

	map<pii, int> m;
	sort(all(y_coord));
	fr(i, y_coord.size())
		m[y_coord[i]] = i+1;
	for(auto & x: qu){
		if(x[1] == q){
			x[2] = m[{x[2], 0}];
			x[3] = m[{x[3], MOD}];
		}
		else if(x[1] < q){	
			x[2] = m[{x[2], x[1]}];
			x[3] = m[{x[3], x[1] + q}];
		}
		else{
			x[2] = m[{x[2], x[1] - q - 1}];
			x[3] = m[{x[3], x[1]}];
		}
		if(x[1] < q){
			id[x[2]] = x[1];
			id[x[3]] = x[1];
			l[x[1]] = x[2];
			r[x[1]] = x[3];
		}
	}
}

int ans[MAXN];

int main(){
	fastio;
	cin >> n >> q;
	/*
		{x, q, lo, hi}
	*/
	vector<array<int, 4>> que;
	fr(i, n){
		int a, b, c;
		cin >> a >> b >> c;
		array<int, 4> x;
		x[0] = a;
		x[1] = q;
		x[2] = b - c;
		x[3] = b + c;
		que.pb(x);
	}
	/*
		{x0, y0, x1, y1}
		{x0, i, y0, y1}
		{x1, i + q, y0, y1}
	*/
	vector<array<int, 4>> rectangle;
	fr(i, q){
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		array<int, 4> x;
		x[0] = min(a, c);
		x[1] = i;
		x[2] = e;
		x[3] = f;
		que.pb(x);
		ans[i] = -1;
		x[0] = max(a, c);
		x[1] = i + q + 1;
		x[2] = e;
		x[3] = f;
		que.pb(x);
	}

	coordinate_compression(que);

	n = y_coord.size();
	build(1, 1, n);
	sort(all(que));
	for(auto x: que){
		if(x[1] < q){
			//cout << x[1] << " " << x[2] << " " << x[3] << endl; 
			update(1, 1, n, x[2], x[3]);
		}
		else if(x[1] > q){
			int i = x[1] - q - 1;
		
			if(ans[i] == -1) {
				//cout << i << ' ' << x[2] << endl;
				ans[i] = 0;
				update(1, 1, n, x[2], MOD);
			}
		}
		else{
			int low = x[2], high = x[3], v;
			//cout << x[0] << "         " << low << ' ' << high << endl;
			while((v = query(1, 1, n, low, high)) <= high){
				int i = id[v];
				//cout << v << " " << i << " | " << l[i] << " " << r[i] << endl;
				update(1, 1, n, l[i], MOD);
				ans[i] = 1;
			}
			//dbg(v);
		}
	}

	fr(i, q){
		if(ans[i]) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
}
