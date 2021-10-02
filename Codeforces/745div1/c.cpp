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
#define RAIZ 451
#define MOD 1000000007
#define INF 2000000000000000100

int change[MAXN];
int start[MAXN];
int x[MAXN], y[MAXN];
int fr[RAIZ][RAIZ];
int maintance = 0;
int n, m;
signed main(){
	fastio;
	cin >> n >> m;
	frr(i, n) cin >> x[i] >> y[i];
	frr(time, m){
		int op, train;
		cin >> op >> train;
		if(op == 1){
			if(x[train] + y[train] < RAIZ){
				int s = x[train] + y[train];
				int t = time%s;
				for(int i = 0; i < s; i++){
					if((i - t + s)%s >= x[train]) fr[i][s]++;
				}
			}
			else{
				for(int t = time; t < MAXN; t+=x[train] + y[train]){
					if(t + x[train] < MAXN)change[t + x[train]]++;
					if(t + x[train] + y[train] < MAXN)change[t + x[train] + y[train]]--;
				}
			}
			start[train] = time;
		}
		else{
			int s = x[train] + y[train];
			if(s < RAIZ){
				int t = start[train]%s;
				for(int i = 0; i < s; i++){
					if((i - t + s)%s >= x[train]) fr[i][s]--;
				}
			}
			else{
				int pos = ((time - start[train] - 1)/s + 1)*s + start[train];
				if(pos - time < y[train]) maintance--;
				for(int t = start[train]; t < MAXN; t+=s){
					if(t + x[train] < MAXN) change[t + x[train]]--;
					if(t + s < MAXN)change[t + s]++;
				}
			}
		}
		// frr(i, m) cout << change[i] << " ";
		// cout << endl;
		// dbg(maintance);
		maintance += change[time];
		int ans = maintance;
		for(int i = 2; i < RAIZ; i++) ans += fr[time%i][i];
		cout<< ans << '\n';
	}
}