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

string a, b;

bool test_inv(int ia, int ib){
	while(ia >= 0 && ib < b.size()){
		if(a[ia] != b[ib]) return false;
		ia--;
		ib++;
	}
 	if(ib == b.size()) return true;
	else return false;
}

bool test(int ini){
	int i = ini;
	while(i < a.size()){
		if(a[i] != b[i - ini]) return false;
		if(test_inv(i - 1, i - ini + 1)) return true;
		i++;
		if(i - ini == b.size()) return true;
	}
	return false;
}

signed main(){
	fastio;

	int t;
	cin >> t;
	while(t--){
		cin >> a >> b;
		int ok = 0;
		fr(i, a.size()){
			if(test(i)) {
				ok = 1;
				break;
			}
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
