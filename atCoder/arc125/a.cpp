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
#define INF 1000000000000000100

int a[MAXN], b[MAXN];
int n, m;

signed main(){
	fastio;
	int closest[2] = {MOD, MOD};
	cin >> n >> m;
	fr(i, n) cin >> a[i];
	fr(i, m) cin >> b[i];
	fr(i, n) closest[a[i]] = min(closest[a[i]], min(i, n - i));

	int ap[2] = {0, 0};
	fr(i, m) ap[b[i]]++;

	int changes = 0;
	fr(i, m-1) if(b[i] != b[i+1]) changes++;

	if(changes > 0){
		int ans = m + changes + closest[1 - a[0]];
		if(a[0] == b[0]) ans--;
		if(ans >= MOD) {
			cout<< -1 << endl;
		}
		else{
			cout << ans << endl;
		}
	}
	else{
		if(a[0] != b[0]){
			int ans = closest[b[0]] + m;
			if(ans >= MOD) {
				cout<< -1 << endl;
			}
			else{
				cout << ans << endl;
			}
		}
		else cout << m << endl;
	}
}
