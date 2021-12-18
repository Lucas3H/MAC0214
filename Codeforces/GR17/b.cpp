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

deque<int> d;
int n;

bool ok(vector<int> & v){
	fr(i, v.size()){
		int t = (int)v.size() - 1 - i;
		if(v[i] != v[t]) return false;
	}
	return true;
}

void solve(){
	d.clear();
	cin >> n;
	fr(i, n){
		int x;
		cin >> x;
		d.pb(x);
	}

	int a = -1, b = -1;
	while(d.size() > 1){
		if(d.front() == d.back()){
			d.pop_front();
			d.pop_back();
		}
		else{
			a = d.front(), b = d.back();
			break;
		}
	}

	if(d.size() <= 1){
		cout << "YES" << endl;
		return;
	}

	vector<int> v;
	for(auto x: d) if(x != a) v.pb(x);

	if(ok(v)){
		cout << "YES" << endl;
		return;
	}

	v.clear();
	for(auto x: d) if(x != b) v.pb(x);

	if(ok(v)){
		cout << "YES" << endl;
		return;
	}

	cout << "NO" << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--) solve();
}
