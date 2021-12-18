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

int a[MAXN], b[MAXN], c[MAXN], p[MAXN];

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		frr(i, n) cin >> a[i];
		frr(i, n) cin >> b[i];
		frr(i, n) cin >> c[i];

		frr(i, n - 1){
			if(a[i] != p[i - 1]){
				p[i] = a[i];
			}
			else if(b[i] != p[i - 1]){
				p[i] = b[i];
			}
			else{
				p[i] = c[i];
			}
			cout << p[i] << ' ';
		}
		if(a[n] != p[n-1] && a[n] != p[1]) p[n] = a[n];
		else if(b[n] != p[n-1] && b[n] != p[1]) p[n] = b[n];
		else p[n] = c[n];
		cout << p[n] << endl;
	}
}
