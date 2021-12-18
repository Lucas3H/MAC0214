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

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100

int fr[MAXN];
int n;

void solve(){
	cin >> n;
	frr(i, n) fr[i] = 0;
	fr(i, n){
		int x;
		cin >> x;
		fr[x]++;
	}
	int f = 1,q = 0;
	frr(i, n){
		if(fr[f] < fr[i]) {
			f = i;
			q = 1;
		}
		else if(fr[f] == fr[i]) q++;
	}

	cout << (n - fr[f] * q) / (fr[f] - 1) + q - 1 << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--) {
		solve();
	}
}
