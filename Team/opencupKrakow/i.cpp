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

#define MAXN (1 << 20)
#define MOD 1000000007
#define INF 2000000000000000100

vector<int> divisors[MAXN];
int fr[MAXN], v[2*MAXN];

signed main(){
	fastio;
	for(int i = 1; i < MAXN; i++){
		for(int j = i; j < MAXN; j+=i) {
			int d = (i ^ j);
			if(__gcd(d, j) == i) divisors[j].pb(d);
		}
	}

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		fr(i, MAXN) fr[i] = 0;
		frr(i, n) cin >> v[i];
		frr(i, n) fr[v[i]]++;

		ll ans = 0;
		frr(i, n){
			for(auto x: divisors[v[i]]){
				ans += fr[x];
			}
		}

		cout << ans / 2 << '\n';
	}
}
