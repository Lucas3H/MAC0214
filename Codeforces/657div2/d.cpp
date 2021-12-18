#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = (int)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;

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

set<int> cc;
map<int, vector<int>> bota;
map<int, vector<int>> tira;

int n, hour, minu, k;
int h[MAXN], m[MAXN];

signed main(){
	fastio;
	cin >> n >> hour >> minu >> k;
	set<int> cur;
	frr(i, n){
		cin >> h[i] >> m[i];
		int t = m[i] % (minu / 2);
		bota[t].pb(i);
		cc.insert(t);
		if(t + k >= minu / 2) {
			cur.insert(i);
			tira[t + k - minu / 2].pb(i);
			cc.insert(t + k - minu / 2);
		}
		else{
			tira[t + k].pb(i);
			cc.insert(t + k);
		}
	}

	cc.insert(0);

	int ans = 0, sz = cur.size();

	for(auto t : cc){
		for(auto x : tira[t]) cur.erase(x);
		if(cur.size() < sz){
			sz = cur.size();
			ans = t;
		}
	// 	cout << t << " " << cur.size() << endl;
	// 	for(auto x : cur) cout << x << " ";
	// 	cout << endl;
	// cout << endl;
		for(auto x : bota[t]) cur.insert(x);
	}

	cout << sz << " " << ans << endl;

	cur.clear();
	frr(i, n){
		int t = m[i] % (minu / 2);
		if(t + k >= minu / 2) cur.insert(i);
	}

	for(auto t : cc){
		for(auto x : tira[t]) cur.erase(x);
		if(ans == t){
			for(auto x : cur) cout << x << " ";
			cout << endl;
			break;
		}
		for(auto x : bota[t]) cur.insert(x);
	}
}
