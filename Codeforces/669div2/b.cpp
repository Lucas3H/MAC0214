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

int t, n;
vector<int> a;
vector<int> ans;

signed main(){
	fastio;
	cin >> t;

	while(t--){
		cin >> n;
		a.resize(n);
		fr(i, n) cin >> a[i];
		sort(all(a));
		ans.clear();

		int last = 0;
		fr(i, n){
			int davez = 0;
			fr(j, a.size()){
				if(__gcd(last, a[davez]) < __gcd(last, a[j])) davez = j;
			}
			// dbg(__gcd(last, a[0]));
			// dbg(davez);
			ans.pb(a[davez]);
			last = __gcd(last, a[davez]);
		
			a.erase(a.begin() + davez, a.begin() + davez + 1);
		}
		for(auto x: ans) cout << x << " ";
		cout << endl;
	}

}
