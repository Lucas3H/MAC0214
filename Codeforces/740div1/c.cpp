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

vector<int> ans;
vector<int> v;

int find(int x){
	for(int i = 0; i < v.size(); i++) if(v[i] == x) return i;
		return -1;
}

void solve(){
	if(v.size() == 1) return;
	int n = v.size(), a = find(n), b;
	
	if(a > 0){
		ans.pb(a);
		reverse(v.begin(), v.begin() + a + 1);
	}
	
	b = find(n - 1);
	if(b > 1) {
		ans.pb(b - 1);
		reverse(v.begin(), v.begin() + b);
	}
	ans.pb(b + 1);
	reverse(v.begin(), v.begin() + b + 2);

	ans.pb(2);
	reverse(v.begin(), v.begin() + 3);

	ans.pb((int)v.size() - 1);
	reverse(all(v));
	v.pop_back(), v.pop_back();
	solve();
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		v.resize(n);
		int ok = 1;
		fr(i, n) {
			cin >> v[i];
			if((i - v[i])%2 == 0) ok = 0;
		}
		if(!ok) cout << -1 << endl;
		else{
			ans.clear();
			solve();
			cout << ans.size() << endl;
			for(auto x: ans) cout << x + 1 << " ";
			cout << endl;
		}
	}
}
