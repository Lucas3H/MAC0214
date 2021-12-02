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

int b, l;
int v[MAXN], p[MAXN];
int resto = 0;


signed main(){
	fastio;
	cin >> b >> l;
	fr(i, l) cin >> v[i];
	p[0] = 1;
	
	fr(i, l){
		if((l - 1 - i)%2 == 0) resto = (resto + v[i]) % (b + 1);
		else resto = (resto - v[i] + b + 1) % (b + 1);
	}
	if(resto == 0){
		cout << 0 << " " << 0 << endl;
		return 0;
	}

	fr(i, l){
		if((l - 1 - i)%2 == 0){
			if(resto <= v[i]){
				cout<< i +1  << ' ' << v[i] - resto << endl;
				return 0;
			}
		}
		else{
			if((resto + v[i]) >= b + 1){
				cout << i + 1 << " " << resto + v[i] - b - 1 << endl;
				return 0;
			}
		}
	}
	cout<< -1 << ' ' << -1 << endl;
}
