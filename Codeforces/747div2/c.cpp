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

#define MAXN 300010
#define MOD 1000000007
#define INF 2000000000000000100

int n;
string s;
int f[MAXN];

void build(int x){
	for(int i = 1; i * i <= x; i++){
		if(x % i == 0){
			f[i]++;
			f[x / i]++;
		}
	}
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		char c;
		cin >> n >> c;
		cin >> s;

		bool acaba_em_um = false, acaba_em_zero = true;
		fr(i, n){
			if(s[i] != c){	
				acaba_em_zero = false;
			}
		}
		if(acaba_em_zero){
			cout<< 0 << endl;
			continue;
		}
		fr(i, n + 1) f[i] = 0;
		fr(i, n) if(s[i] != c) build(i + 1);
 		frr(i, n){
 			if(f[i] == 0){
 				cout << 1 << endl;
 				cout << i << endl;
 				acaba_em_um = true;
 				break;
 			}
 		}
 		if(acaba_em_um) continue;

 		cout << 2 << endl;
 		cout << n << " " << n - 1 << endl;
 	}
}
