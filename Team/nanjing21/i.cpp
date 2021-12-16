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

#define MAXN 210
#define MOD 1000000007
#define INF 2000000000000000100

using coord = long double;
const long double pi = acos(-1);
const long double EPS = 1e-8;

int sign(coord x) { return (x > EPS) - (x < -EPS); }
coord sq(coord x) { return x * x; }

struct point {
	coord x, y;
	point() : x(0), y(0) {} point(coord _x, coord _y): x(_x), y(_y) {}
	inline point operator+(point p){ return {x + p.x, y + p.y}; }
	inline point operator-(point p){ return {x - p.x, y - p.y}; }
	inline point operator*(coord o){ return {x * o, y * o}; }
	inline point operator/(coord o){ return {x / o, y / o}; }
	inline void operator=(point p){ x = p.x, y = p.y; }

	inline coord operator*(point p){ return x * p.x + y * p.y; } // |a||b|cos(tht)
	inline coord operator^(point p){ return x * p.y - y * p.x; } // |a||b|sin(tht), this -> p

	inline int ccw(point p){ return sign(*this ^ p); } // ccw  1 left, 0 over, -1 right

	inline long double norm(){ return hypot(x, y); }
	inline coord norm2(){ return x * x + y * y; }

	inline point rot90(){return {-y, x}; }
	inline point rot(long double ang){ return {cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y}; }
	inline point project(point p){return p * (((*this) * p)/p.norm2()); }

	inline bool operator<(point &p){ return sign(x - p.x) != 0 ? sign(x - p.x) < 0 : sign(y - p.y) < 0; } // lex_sort
	inline bool operator==(point p){ return sign(x - p.x) == 0 and sign(y - p.y) == 0; }

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

void swap(point &a, point &b){ point aux = a; a = b; b = aux; }

struct line {
	point p; coord c; //p * <x,y> = c
	line() {} line(point _p, coord _c): p(_p), c(_c) {}
	line(point a, point b) : p((b - a).rot90()), c(p * a) {}
	line get_parall(point v){ return line(p, p * v); }// parallel line at point v
	line get_perp(){ return line(p.rot90(), c); }// perpendicular line

	bool contains(point v){ return sign(p * v - c) == 0; }
	bool intsec(line l){ return sign(p ^ l.p) != 0; } // false if is the same line

	coord dist(point v){ return abs(p * v - c) / p.norm(); }

	point get_intsec(line l){ coord d = p^l.p; return point((c*l.p.y - l.c*p.y)/d, (p.x*l.c - c*l.p.x)/d); }
};

struct segment {
	point a, b; // a != b
	segment() {} segment(point _a, point _b): a(_a), b(_b) {}

	bool contains(point p){ return sign((p-a)^(b-a)) == 0 and sign((p-a)*(b-a)) >= 0 and sign((p-b)*(a-b)) >= 0; }
	
	int ccw(point p){ return((b - a).ccw(p - a)); } // ccw  1 left, 0 over, -1 right  of seg a->b

	bool intsec(segment q){ segment p = *this;
		if (p.contains(q.a) or p.contains(q.b) or q.contains(p.a) or q.contains(p.b)) return true;
		return p.ccw(q.a) * p.ccw(q.b) == -1 and q.ccw(p.a) * q.ccw(p.b) == -1;	
	}
	
	coord len2(){ return (a - b).norm2(); }

	long double dist(segment q){segment p = *this; 
		return p.intsec(q)? 0 : min({p.dist(q.a), p.dist(q.b), q.dist(p.a), q.dist(p.b)});	}

	long double dist(point p){
		if (sign(((p - a) * (b - a))) >= 0 and sign((p - b) * (a - b)) >= 0)
			return abs((p - a) ^ (b - a)) / (b - a).norm();
		return min((p - a).norm(), (p - b).norm());
	}

	line getline(){return line(a, b); }
};

vector<point> get_intsec(segment p, segment q){ // returns intersection points/segment
		if (!p.intsec(q)) return {};
		if (((p.b - p.a)^(q.b - q.a)) == 0){
			point a, b;
			if (p.contains(q.a) and p.contains(q.b)) a = q.a, b = q.b;
			else if (q.contains(p.a) and q.contains(p.b)) a = p.a, b = p.b;
			else if (p.contains(q.a) and q.contains(p.a)) a = q.a, b = p.a;
			else if (p.contains(q.a) and q.contains(p.b)) a = q.a, b = p.b;
			else if (p.contains(q.b) and q.contains(p.a)) a = q.b, b = p.a;
			else a = q.b, b = p.b;
			if (a == b) return {a};
			return {a, b};
		}	
		return {(p.getline()).get_intsec(q.getline())};
}





int n, m, vy;
point p[MAXN];
vector<pair<int, double>> adj[MAXN];

bool add(int a, int b){
	if(a == 2 * n && b == 2 * n + 1) goto nxt;
	if((a / 2 == b / 2) || p[a].y >= p[b].y) return false;
	nxt:	
	segment s = segment(p[a], p[b]);

	for(int i = 0; i < 2 * n; i += 2){
		if(a / 2 == i / 2 || b / 2 == i / 2) continue;
		vector<point> intersec = get_intsec(s, segment(p[i], p[i + 1]));
		if(intersec.size()) return false;
	}

	return true;
}

double dist[MAXN];
void dijkstra(){
	vector<pair<double, int>> v;
	fr(i, 2 * n + 2) {
		v.pb({p[i].y, i});
		dist[i] = MOD;
	}
	sort(all(v));
	dist[2 * n] = 0;
	for(auto x : v){
		int cur = x.s;
		// dbg(cur);
		for(auto y : adj[cur]){
			dist[y.f] = min(dist[y.f], max(dist[cur], y.s));
		}
		//printf("%d %lf\n", cur, dist[cur]);
	} 

	if(dist[2 * n + 1] > 100000000) printf("-1\n");
	else printf("%.12lf\n", dist[2 * n + 1]);
}

signed main(){
		cin >> n >> m >> vy;
	fr(i, n){
		cin >> p[2 * i].x >> p[2 * i].y;
		cin >> p[2 * i + 1].x >> p[2 * i + 1].y;
	}
	fr(i, 2 * n) fr(j, 2 * n) if(add(i, j) && abs(abs(p[i].x) - m) > EPS) {
		//cout << i << " " << j << " " << vy * abs((p[i].x - p[j].x) / (p[i].y - p[j].y)) << endl;
		adj[i].pb({j, vy * abs((p[i].x - p[j].x) / (p[i].y - p[j].y))});
	}

	fr(i, 2 * n){
		p[2 * n] = point(p[i].x, -1000000);
		p[2 * n + 1] = point(p[i].x, 1000000);
		if(add(2 * n, i) && abs(abs(p[i].x) - m) > EPS) {
			adj[2 * n].pb({i, 0});
		}
		if(add(i, 2 * n + 1) && abs(abs(p[i].x) - m) > EPS) {
			adj[i].pb({2 * n + 1, 0});
		}
		p[2 * n] = point(p[i].x + 2 * EPS, -1000000);
		p[2 * n + 1] = point(p[i].x + 2 * EPS, 1000000);
		if(add(2 * n, 2 * n + 1) && p[2 * n].x < m){
			adj[2 * n].pb({2 * n + 1, 0});
		}
		p[2 * n] = point(p[i].x - 2 * EPS, -1000000);
		p[2 * n + 1] = point(p[i].x - 2 * EPS, 1000000);
		if(add(2 * n, 2 * n + 1) && p[2 * n].x > -m){
			adj[2 * n].pb({2 * n + 1, 0});
		}
	}

	dijkstra();
}
