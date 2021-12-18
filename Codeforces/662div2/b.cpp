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

int n, q;
set<pii> plank;
int fr[MAXN];

signed main(){
	fastio;
	cin >> n;
	fr(i, n){
		int x;
		cin >> x;
		plank.erase({-fr[x], x});
		fr[x]++;
		plank.insert({-fr[x], x});
	}

	cin >> q;
	while(q--){
		char op;
		int x;
		cin >> op >> x;
		plank.erase({-fr[x], x});
		if(op == '-') fr[x]--;
		else fr[x]++;
		plank.insert({-fr[x], x});

		vector<int> aux;
		for(auto x: plank) {
			aux.pb(x.s);
			if(aux.size() > 2) break;
		}


		if(fr[aux[0]] < 4){
			cout << "NO" << endl;
			continue;
		}
		fr[aux[0]] -= 4;

		int ok = 0;
		for(auto x : aux) ok += fr[x] / 2;
		fr[aux[0]] += 4;

		//dbg(ok);

		if(ok < 2) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

}
