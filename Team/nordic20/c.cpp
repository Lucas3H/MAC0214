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
#define INF 2000000000000000100

int n;
int a[MAXN];
vector<pii> ans;
pq<pii> fila;
pii x, y;
	
signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> a[i];
	fr(i, n) if(a[i]) fila.push({a[i], i});

	while(fila.size() >= 2){
		x = fila.top();
		fila.pop();
		y = fila.top();
		fila.pop();
		ans.pb({x.s, y.s});
		x.f--, y.f--;
		if(x.f) fila.push(x);
		if(y.f) fila.push(y);
	}
	if(fila.size() == 0){
		cout << "yes" << endl;
		for(auto x: ans) cout << x.f + 1 << " " << x.s + 1 << endl;
	}
	else cout << "no" << endl;

}
