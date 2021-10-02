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
#define db cout << "Debug" << '\n';
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 1000010
#define MOD 1000000007
#define INF 2000000000000000100

/*
	{sign, pos%2}
*/
int acu[MAXN];
vector<int> fr[2*MAXN][2];

int n, q;
string s;

void find(int l, int r){
	int dist = acu[r] - acu[l-1];
	if(dist > 0){
		auto ind = lower_bound(all(fr[acu[l-1] + dist/2 + 1 + n + 1][0]), l);
		if(ind == fr[acu[l] + dist/2 + 1 + n + 1][0].end()) assert(0);
		cout << *ind << '\n';
	}
	else{
		auto ind = lower_bound(all(fr[acu[l-1] - abs(dist)/2 - 1 + n + 1][1]), l);

		if(ind == fr[acu[l] - abs(dist)/2 - 1 + n + 1][1].end()) assert(0);
		cout << *ind << '\n';
	}
}

void solve(int l, int r){
	if(acu[l-1] == acu[r]) {
		cout << 0 << '\n';
		return;
	}

	if((r - l + 1)%2 == 0){
		cout << 2 << '\n';
		cout << l << " ";
		find(l+1, r);
	}
	else{
		cout << 1 << '\n';
		find(l, r);
	}
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		cin >> n >> q;
		cin >> s;
		fr(i, 2*n + 2) fr[i][0].clear(), fr[i][1].clear();
		fr(i, n){
			if(s[i] == '+' && i%2 == 0) {
				acu[i+1] = acu[i] + 1;
				fr[acu[i+1] + n + 1][0].pb(i+1);
			}
			else if(s[i] == '+' && i%2) {
				acu[i+1] = acu[i] - 1;
				fr[acu[i+1] + n + 1][1].pb(i+1);
			}
			else if(s[i] == '-' && i%2 == 0) {
				acu[i+1] = acu[i] - 1;	
				fr[acu[i+1] + n + 1][1].pb(i+1);
			}
			else if(s[i] == '-' && i%2) {
				acu[i+1] = acu[i] + 1;
				fr[acu[i+1] + n + 1][0].pb(i+1);
			}
		}
		
		fr(i, q){
			int l, r;
			cin >> l >> r;
			solve(l, r);
		}
	}
}
