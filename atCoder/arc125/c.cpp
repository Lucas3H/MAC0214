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
#define INF 1000000000000000100

int n, k;
set<int> tot, a;

signed main(){
	fastio;
	cin >> n >> k;
	fr(i, k){
		int x; cin >> x; a.insert(x);
	}
	frr(i, n) tot.insert(i);
	for(auto x: a) tot.erase(x);

	// if(k == 1){
	// 	frm(i, n) cout << i + 1 << " ";
	// 	cout << endl;
	// 	return 0;
	// }
	vector<int> ans;
	while(a.size() > 1){
		ans.pb(*(a.begin()));
		a.erase(a.begin());
		if(tot.size() && *(tot.begin()) < ans.back()){
			ans.pb(*(tot.begin()));
			tot.erase(tot.begin());
		}
	}
	for(int i = n; i > *(a.begin()); i--){
		ans.pb(i);
		tot.erase(i);
	}
	ans.pb(*(a.begin()));
	while(tot.size()){
		auto x = tot.rbegin();
		ans.pb(*(x));
		tot.erase(*x);
	}
	for(auto x: ans) cout << x << " ";
	cout << endl;
}
