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
int a[MAXN], b[MAXN], c[MAXN];

signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> a[i];
	fr(i, n) cin >> b[i];
	fr(i, n) cin >> c[i];
	vector<int> v;
	int ind = 0;
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	fr(i, n){
		if(b[i] > a[ind]){
			ind++;
			v.pb(b[i]);
		}
	}
	ind = 0;
	fr(i, n){
		if(ind < v.size() && c[i] > v[ind]){
			ind++;
		}
	}
	cout << ind << endl;
}
