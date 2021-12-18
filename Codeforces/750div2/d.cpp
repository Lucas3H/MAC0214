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

int n, t;
int a[MAXN];

int get(int x, int y){
	return x * y / __gcd(x, y) / y;
}

signed main(){
	fastio;
	cin >> t;

	while(t--){
		cin >> n;
		fr(i, n) cin >> a[i];
		if(n%2 == 0){
			for(int i = 0; i < n; i+=2){
				if(a[i] > 0) cout << abs(a[i + 1]) << " ";
				else cout << -abs(a[i + 1]) << ' ';

				if(a[i + 1] > 0) cout << -abs(a[i]) << " ";
				else cout << abs(a[i]) << ' ';  
			}
		}
		else{
			for(int i = 0; i < n - 3; i+=2){
				if(a[i] > 0) cout << get(abs(a[i + 1]), abs(a[i])) << " ";
				else cout << -get(abs(a[i + 1]), abs(a[i])) << ' ';

				if(a[i + 1] > 0) cout << -get(abs(a[i]), abs(a[i + 1])) << " ";
				else cout << get(abs(a[i]), abs(a[i + 1])) << ' ';  
			}

			int x = a[n - 3], y = a[n - 2], z = a[n - 1];

			if(y + z != 0){
				if(x > 0) cout << get(abs(y + z), abs(x)) << " ";
				else cout << -get(abs(y + z), abs(x)) << ' ';

				if(y + z > 0) cout << -get(abs(x), abs(y + z)) << " ";
				else cout << get(abs(x), abs(y + z)) << ' '; 

				if(y + z > 0) cout << -get(abs(x), abs(y + z)) << " ";
				else cout << get(abs(x), abs(y + z)) << ' '; 
			}
			else if(x + y != 0){
				if(x + y > 0) cout << get(abs(z), abs(x + y)) << " ";
				else cout << -get(abs(z), abs(x + y)) << ' ';

				if(x + y > 0) cout << get(abs(z), abs(x + y)) << " ";
				else cout << -get(abs(z), abs(x + y)) << ' ';

				if(z > 0) cout << -get(abs(x + y), abs(z)) << " ";
				else cout << get(abs(x + y), abs(z)) << ' '; 
			}
			else{
				if(x + z > 0) cout << get(abs(y), abs(x + z)) << " ";
				else cout << -get(abs(y), abs(x + z)) << ' ';

				if(y > 0) cout << -get(abs(x + z), abs(y)) << " ";
				else cout << get(abs(x + z), abs(y)) << ' '; 

				if(x + z > 0) cout << get(abs(y), abs(x + z)) << " ";
				else cout << -get(abs(y), abs(x + z)) << ' ';
			}
		}
		cout << endl;
	}
}
