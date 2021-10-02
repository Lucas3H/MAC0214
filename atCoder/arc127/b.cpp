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

int n, l;
vector<int> base3(int x, int v[]){
	vector<int> ret;
	fr(i, l-1){
		ret.pb(v[x%3]	);
		x /= 3;
	}
	return ret;
}

int resto[20][3];
vector<vector<int>> ans; 
signed main(){
	fastio;
	cin >> n >> l;
	fr(i, l) fr(j, 3) resto[i][j] = n;
	int v[3] = {0, 1, 2};
	fr(i, n){
		vector<int> ret = base3(i, v);
		ret.pb(2);
		ans.pb(ret);
		fr(j, l) resto[j][ret[j]]--;
	}

	v[0] = 1, v[1] = 2, v[2] = 0;

	fr(i, n){
		vector<int> ret = base3(i, v);
		ret.pb(1);
		ans.pb(ret);
		fr(j, l) resto[j][ret[j]]--;
	}
	v[0] = 2, v[1] = 0, v[2] = 1;
	fr(i, n){
		vector<int> ret = base3(i, v);
		ret.pb(0);
		ans.pb(ret);
		fr(j, l) resto[j][ret[j]]--;
	}
	for(auto v : ans){
		frm(j, l) cout << v[j];
		cout << endl;
	}
}
