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

int n;
int a[MAXN];
int fr[40];

void put(int x){
	int ind = 0;
	while(x){
		fr[ind] += x%2;
		x /= 2;
		ind++;
	}
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		fr(i, 40) fr[i] = 0;
		cin >> n;
		fr(i, n){
			int a;
			cin >> a;
			put(a);
		}

		int ans = 0;
		fr(i, 40) ans = __gcd(ans, fr[i]);
		if(ans == 0){
			frr(i, n) cout << i << " ";
			cout << endl;
			continue;
		}
		for(int i = 1; i <= ans; i++){
			if(ans%i == 0) cout << i << ' ';
		}
		cout << endl;
	}
}
