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
int ans[MAXN];

int ask(int a, int b){
	cout << "? " << a << ' ' << b << endl;
	cin >> a;
	return a;
}

set<int> s;

signed main(){
	fastio;
	cin >> n;
	frr(i, n) s.insert(i);

	int cur = 1;
	for(int i = 2; i <= n; i++){
		int r1 = ask(cur, i), r2 = ask(i, cur);
		if(r1 > r2){
			s.erase(r1);
			ans[cur] = r1;
			cur = i;
		}
		else{
			s.erase(r2);
			ans[i] = r2;
		}
	}
	ans[cur] = *(s.begin());

	cout << "! ";
	frr(i, n) cout << ans[i] << " ";
	cout << endl;

}
