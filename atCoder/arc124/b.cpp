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

int a[MAXN], b[MAXN];
int n;

map<int, int> m2;

bool test(int x){
	map<int, int> m1;
	frr(i, n){
		m1[a[i]^x]++;
	}
	for(auto x: m1){
		if(m2[x.f] != x.s) return false;
	} 
	return true;
}

signed main(){
	fastio;
	cin >> n;
	frr(i, n) cin >> a[i];
	frr(i, n) cin >> b[i];
	frr(i, n) m2[b[i]]++;
	set<int> ans;
	frr(i, n){
		if(test(a[1]^b[i])) ans.insert(a[1]^b[i]);
	}
	cout << ans.size() << endl;
	for(auto x: ans) cout << x << endl;
}
