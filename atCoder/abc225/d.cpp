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

int prv[MAXN], nxt[MAXN];
int q;

void connect(int x, int y){
	nxt[x] = y;
	prv[y] = x;
}

void disconnect(int x, int y){
	nxt[x] = 0, prv[y] = 0;
}

void print(int x){
	int it = x;
	while(prv[it] != 0){
		it = prv[it];
	}
	vector<int> ans;
	while(it != 0){
		ans.pb(it);
		it = nxt[it];
	}
	cout << ans.size() << " ";
	for(auto x : ans) cout << x << " ";
	cout << endl;
}

signed main(){
	fastio;
	int n, q;
	cin >> n >> q;

	while(q--){
		int op, x, y;
		cin >> op >> x;
		if(op == 1){
			cin >> y;
			connect(x, y);
		}
		else if(op == 2){
			cin >> y;
			disconnect(x, y);
		}
		else print(x);
	}
}
