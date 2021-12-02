#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_ll_distribution<ll>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100

ll fib[MAXN];
map<pii, bool> m;
vector<ll> ans;

void solve(ll i, ll n){
	if(n == 1){
		for(auto x: ans){
			fr(i, x - 1) cout << 'A';
			cout << 'B';
		}
		cout << endl;
		exit (0);
	}
	if(i == 1) return;
	if(m[{n, i}] != 0) return;
	m[{n, i}] = 1;
	ll qtd = 0;
	while(n%fib[i] == 0){
		n /= fib[i];
		ans.pb(i);
		qtd++;
	}
	fr(j, qtd){
		solve(i - 1, n);
		n *= fib[i];
		ans.pop_back(); 
	}
	solve(i - 1, n);

}


ll n;
signed main(){
	fastio;
	cin >> n;
	fib[1] = 1;
	fib[2] = 2;
	ll i = 2;
	while(fib[i] < n){
		i++;
		fib[i] = fib[i - 1] + fib[i - 2];
	}	
	solve(i, n);
	cout << "IMPOSSIBLE" << endl;
}
