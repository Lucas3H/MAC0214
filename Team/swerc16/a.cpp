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
typedef pair<long double,long double> pdd;
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

#define MAXN 100010
#define MOD 1000000007
#define INF 1000000000000000100

long double dist(long double x, long double y){
	return sqrt((long double)(x*x + y * y));
}

long double norm(pdd x, pdd y){
	return sqrt((x.f - y.f) * (x.f - y.f) + (x.s - y.s) * (x.s - y.s));
}

int n;
long double x, y;
long double l[30];
long double a, b, c, sum = 0;
pdd ans[30];

long double cross(pdd p1, pdd p2){
	return p1.f*p2.s - p2.f*p1.s;
}

long double dot(pdd p1, pdd p2){
	return p1.f*p2.f + p1.s*p2.s;
}

signed main(){
	cin >> n;
	long double maior = 0.0;
	int maior_ind;
	fr(i, n){
		cin >> l[i];
		sum += l[i];
		if(maior < l[i]){
			maior = l[i];
			maior_ind = i;
		}
		maior = max(maior, l[i]);
		
	}
	cin >> x >> y;
	c = dist(x, y);
	if(c < 0.00000001) {
		x = 0.0001, y = 0.0001;
		c = dist(x, y);
	}

	if(c >= sum || n == 1){
		pdd last = mp(0.0, 0.0);
		fr(i, n){
			pdd p = mp(last.f + l[i] * x / c, last.s + l[i] * y / c);
			printf("%.6Lf %.6Lf\n", p.f, p.s);
			last = p;
		}
		return 0;
	}
	if(maior > sum - maior + c){
		pdd last = mp(0.0, 0.0);
		int i = 0;
		pdd p;
		while(i < maior_ind){
			p = mp(last.f - l[i] * x / c, last.s - l[i] * y / c);
			printf("%.6Lf %.6Lf\n", p.f, p.s);
			last = p;
			i++;
		}
		p = mp(last.f + l[i] * x / c, last.s + l[i] * y / c);
		printf("%.6Lf %.6Lf\n", p.f, p.s);
		last = p;
		i++;

		while(i < n){
			p = mp(last.f - l[i] * x / c, last.s - l[i] * y / c);
			printf("%.6Lf %.6Lf\n", p.f, p.s);
			last = p;
			i++;
		}

		return 0;
	}

	sum += c;
	l[n] = c;
	if(c > maior) {
		maior_ind = n;
		maior = c;
	}
	int ind = (maior_ind + 1) % (n + 1);
	while(ind != maior_ind && a < (sum - maior)/2){
		a += l[ind];
		ind = (ind + 1) % (n + 1);
	}
	b = sum - maior - a;
	c = maior;

	if(a > b + c){
		ind = (ind + n) % (n + 1);
		a -= l[ind];
		b += l[ind];
	}

	/*
		[maior_ind] -> c
		[maior_ind + 1, ind] -> a
		[ind, maior_ind - 1] -> b
	*/

	long double ang = 0;

	pdd last = mp(0.0, 0.0), p;
	int i = (maior_ind + 1) % (n + 1);

	while(i != ind){
		ans[i] = last;
		last = mp(last.f + l[i] * cos(ang), last.s + l[i] * sin(ang));
		i = (i + 1) % (n + 1);
	}

	//cout << a << ' ' << b << ' ' << c << endl;
	ang += acos(-1) - acos((b * b + a * a - c * c)/(2 * a * b));
	while(i != maior_ind){
		ans[i] = last;
		last = mp(last.f + l[i] * cos(ang), last.s + l[i] * sin(ang));
		i = (i + 1) % (n + 1);
	}
	ans[i] = last;

	//fr(i, n + 1) printf("%.6Lf %.6Lf\n", ans[i].f, ans[i].s);	

	last = p;
	pdd pivot = ans[0];
	fr(i, n + 1) ans[i] = {ans[i].f - pivot.f, ans[i].s - pivot.s};

	//fr(i, n+1) printf("%.6Lf %.6Lf\n", ans[i].f, ans[i].s);

	long double rot_ang = asin(cross(ans[n], mp(x, y)) / (norm(ans[n], mp(0, 0)) * norm(mp(x, y), mp(0, 0))));
	// dbg((norm(ans[n], mp(0, 0))));
	// dbg((norm(mp(x, y), mp(0, 0))));

	if(dot(ans[n], mp(x, y)) < 0) rot_ang = acos(-1) - rot_ang;

	fr(i, n+1) ans[i] = {ans[i].f * cos(rot_ang) - ans[i].s * sin(rot_ang), ans[i].f * sin(rot_ang) + ans[i].s * cos(rot_ang)};
	frr(i, n) printf("%.6Lf %.6Lf\n", ans[i].f, ans[i].s);
}
