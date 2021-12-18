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

#define MAXN 510
#define MOD 1000000007
#define INF 2000000000000000100

int n;
int frA[MAXN], frB[MAXN];

void solve(){
	fr(i, MAXN) frA[i] = frB[i] = 0;
	cin >> n;
	frr(i, n) {
		int x;
		cin >> x;
		x += 200;
		frA[x]++;
	}
	frr(i, n) {
		int x;
		cin >> x;
		x += 200;
		frB[x]++;
	}


	frm(i, MAXN){
		if(frB[i] < frA[i]){
			cout << "NO" << endl;
			return;
		}

		if(frB[i] > frA[i]){
			if(frB[i] <= frA[i] + frA[i - 1]){
				frA[i - 1] -= frB[i] - frA[i];
			}
			else{
				cout << "NO" << endl;
				return;
			}
		}
	}

	cout << "YES" << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--) solve();

}
