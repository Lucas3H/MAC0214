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

int pref[MAXN]; // Mínimo
int suf[MAXN]; // Máximo
int acu[MAXN]; // soma
string s;
int n;

void solve(){
	cin >> s;
	reverse(all(s));
	n = s.size();

	fr(i, n){
		if(s[i] == 'R') acu[i + 1] = acu[i] + 1;
		else acu[i + 1] = acu[i] - 1;
	}
	pref[0] = MOD;
	frr(i, n) pref[i] = min(pref[i - 1], acu[i]);
	suf[n + 1] = 0;
	for(int i = n; i >= 1; i--){
		suf[i] = max(suf[i + 1], acu[n] - acu[i - 1]);
	} 

	for(int i = n; i >= 0; i--){
		int sl = acu[i];
		int ml = sl - pref[i];
		if(ml > 0) continue;
		if(sl + suf[i + 1] > 0) continue;

		cout << n - i << endl;
		return;
	}
	cout << -1 << endl;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--) solve();
}
