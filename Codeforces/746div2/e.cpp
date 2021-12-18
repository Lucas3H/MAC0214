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

#define MAXN 1000010
#define MOD 1000000007
#define INF 2000000000000000100

int n;
int acu[(1 << 20)], f[(1 << 20)][2];
int a[(1 << 20)];

signed main(){
	fastio;
	cin >> n;
	frr(i, n) cin >> a[i];
	fr(i, (1 << 20)) fr(j, 2) f[i][j] = -1;
 
	int ans = 0;
	frm(ind, 20){
		int i = 1;
		int sum = 0;
		while(i <= n){
			int ini = i;
			while(i <= n && (a[i] & (1 << ind)) == (a[ini] & (1 << ind))) i++;
			if((a[ini] & (1 << ind)) == 0) {
				if(sum%2) for(int j = ini; j < i; j++) acu[j] ^= (1 << ind);
				continue;
			}
			
			f[acu[ini - 1]][(ini - 1)%2] = ini - 1;
			for(int j = ini; j < i; j++){
				sum++;
				if(sum%2) acu[j] = acu[j] ^ (1 << ind);
				if(f[acu[j]][j%2] != -1){
					ans = max(ans, j - f[acu[j]][j%2]);
					//cout << j << ' ' << acu[j] << " "<< ans << endl;
				}
				else f[acu[j]][j%2] = j;
			}
			for(int j = ini - 1; j < i; j++) f[acu[j]][j%2] = -1;
			// cout << ini << ' ' << i << " " << ind << endl;
			// frr(i, n) cout << acu[i] << ' ';
			// cout << endl;
		}
	}
	cout << ans << endl;
}
