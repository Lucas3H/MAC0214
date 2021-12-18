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

int a[MAXN];

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		int sum = 0;
		fr(i, n){
			cin >> a[i];
			sum += a[i];
		}

		int p = 1;
		for(int i = 2; i * i <= sum; i++){
			if(sum%i == 0) p = 0;
		}

		if(p == 0){
			cout<< n << endl;
			fr(i, n) cout << i + 1 << " ";
			cout << endl;
		}
		else{
			int ok = 1;
			cout << n - 1 << endl;
			fr(i, n){
				if(a[i]%2 == 0) cout << i + 1 << " ";
				else if(!ok) cout << i + 1 << ' ';
				else ok = 0;
			}
			cout << endl;
		}
	}
}
