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
#define INF 1000000000000000100


int n;
vector<int> vals;
string s;

void build(){
	vals.resize(n+1);
	int last[2] = {0, 0};
	vals[1] = 1;
	if(s[0] != '?') last[s[0] - '0'] = 1;
	frr(i, n-1){
		if(s[i] == '?') vals[i+1] = vals[i] + 1;
		else{
			if(s[i] == '0') {
				vals[i+1] = i + 1 - last[1];
				last[0] = i + 1;
			}
			else{
				vals[i+1] = i + 1 - last[0];
				last[1] = i + 1;
			}
		}
	}
}

int solve(int p){
	if(p == 1) return n;

	int ini = 1, ans = 0;
	while(ini + p - 1 <= n){
		if(vals[ini + p - 1] >= p) ini = ini + p, ans++;
		else ini = ini + p - 1 - vals[ini + p - 1] + 1;
	}
	return ans;
}

signed main(){
	fastio;
	cin >> n;
	cin>>s;
	build();
	frr(i, n) cout << solve(i) << " ";
	cout << endl;
}
