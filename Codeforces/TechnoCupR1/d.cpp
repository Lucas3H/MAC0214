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

int ask(int pos, int a, int b){
	cout << "? ";
	fr(i, pos - 1) cout << a << " ";
	cout << b << " ";
	fr(i, n - pos) cout << a << " ";
	cout << endl;

	int x;
	cin >> x;
	return x;
}

int ans[MAXN], nxt[MAXN], prv[MAXN];

signed main(){
	fastio;
	cin >> n;
	int zero = 0;
	frr(i, n){
		int x = ask(i, 2, 1);
		if(x < i){		
			prv[i] = x;	
			nxt[x] = i;
		}
	}
	frr(i, n){
		int x = ask(i, 1, 2);
		if(x < i){		
			prv[x] = i;	
			nxt[i] = x;
		}	
	}
	int tot = 1, it = nxt[0];
	while(tot <= n){
		ans[it] = tot;
		it = nxt[it];
		tot++;
	}

	cout<< "! ";
	frr(i, n) cout << ans[i] << " ";
	cout << endl;
}
