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

#define MAXN 100010
#define MOD 1000000007
#define INF 1000000000000000100

/*
	0 acabou, 1 foi pra braixo, 2 foi pra cima, 3 se foi na horizontal
*/

int ask(pii p){
	cout << p.f << " " << p.s << endl;
	string s;
	cin >> s;
	if(s == "Done") return 0;
	else if(s[0] == 'U') return 1;
	else if(s[0] == 'D') return 2;
	else return 3;
}

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		pii p = {1, 1};
		int res;
		if((res = ask(p)) == 0) continue;

		while(true){
			int inc = (p.s == 1) ? 1 : -1;
			bool deu = false;
			int ap = 0;
			for(int i = 1; i <= 7; i++){
				p.s += inc;
				res = ask(p);
				if(res == 0) {
					deu = true;
					break;
				}
				else if(res == 2) p.f++, ap = 1;
				else if(res == 1) ap = 1; 
			}
			if(deu) break;
			if(ap != 1) p.f++;
		}
	}
}
