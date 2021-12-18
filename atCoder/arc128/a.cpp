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
int a[MAXN], v[MAXN];

signed main(){
	fastio;
	cin >> n;
	frr(i, n) cin >> a[i];
	a[0] = a[1];
	a[n + 1] = a[n];
	int sum = 0;
	fr(i, n){
		if(a[i + 1] >= a[i] && a[i + 1] > a[i + 2]){
			v[i + 1] = 1;
			sum++;
		}
		if(a[i + 1] < a[i] && a[i + 1] <= a[i + 2]){
			v[i + 1] = 1;
			sum++;
		}
	}

	if(sum%2){
		for(int i =  n; i >= 1; i--){
			if(v[i]){
				v[i] = 0;
				break;
			}
		}
	}
	frr(i, n) cout << v[i] << " ";
	cout << endl;

}
