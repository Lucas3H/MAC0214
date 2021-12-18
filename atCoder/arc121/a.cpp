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
array<int, 3> p[MAXN];
multiset<int> ans[MAXN];
map<pii, int> m;

void unico(array<int, 3> x, array<int, 3> y){
	pii davez;
	if(x[2] > y[2]) davez = {y[2], x[2]};
	else davez = {x[2], y[2]};
	m[davez] = max(m[davez], abs(x[0] - y[0]));
}

signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> p[i][0] >> p[i][1], p[i][2] = i;
	sort(p, p + n);
	multiset<int> resp;

	unico(p[n - 1], p[0]);
	unico(p[n - 2], p[0]);
	unico(p[n - 1], p[1]);

	fr(i, n) swap(p[i][0], p[i][1]);
	
	sort(p, p + n);
	unico(p[n - 1], p[0]);
	unico(p[n - 2], p[0]);
	unico(p[n - 1], p[1]);

	for(auto x: m) resp.insert(-x.s);
	resp.erase(resp.begin());
	cout << -((*resp.begin())) << endl;
}
