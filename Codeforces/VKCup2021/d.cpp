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
#define INF 2000000000000000100

vector<int> wish[MAXN];
int ans[MAXN], a[MAXN];

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		frr(i, n) wish[i].clear();
		frr(i, n){
			cin >> a[i];
			wish[a[i]].pb(i);
		}

		vector<int> alone, chose;
		frr(i, n){
			if(wish[i].size() == 0) alone.pb(i);
			else {
				ans[wish[i].back()] = i;
				fr(j, (int)wish[i].size() - 1) chose.pb(wish[i][j]);
			}
		}
		fr(i, alone.size()) ans[chose[i]] = alone[i];

		vector<int> equal;
		frr(i, n) if(ans[i] == i) equal.pb(i);
		for(int j = 0; j < (int)equal.size() - 1; j+=2) swap(ans[equal[j]], ans[equal[j + 1]]);
		if(equal.size() % 2 == 1){
			int davez = equal.back();
			swap(ans[wish[a[davez]].back()], ans[davez]);
		}

		cout << n - alone.size() << endl;
		frr(i, n) cout << ans[i] << " ";
		cout << endl;
	}
}
