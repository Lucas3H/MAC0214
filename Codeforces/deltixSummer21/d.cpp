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

#define MAXN 100010
#define MOD 1000000007
#define INF 1000000000000000100

int n, k;
int e[MAXN], ou[MAXN];
pii v[MAXN];

int ask(string tipo, int a, int b){
	cout << tipo << " " << a << " " << b << endl;
	int ret;
	cin >> ret;
	return ret;
}

signed main(){
	fastio;
	cin >> n >> k;
	frr(i, n-1) e[i+1] = ask("and", 1, i+1);
	frr(i, n-1) ou[i+1] = ask("or", 1, i+1);

	e[1] = ask("and", 2, 3);
	ou[1] = ask("or", 2, 3);

	v[1].f = (e[2] + ou[2] + e[3] + ou[3] - e[1] - ou[1])/2;

	frr(i, n) v[i].s = i;
	frr(i, n-1) v[i+1].f = e[i+1] + ou[i+1] - v[1].f;
	sort(v + 1, v + n + 1);
	cout << "finish " << v[k].f << endl;
}
