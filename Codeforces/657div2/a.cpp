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

string s = "abacaba";
string t;
int n;

// if easy, question mark is anything
bool match(string cur, int ini, bool easy){
	if(t.size() < ini + s.size()) return false;
	fr(i, s.size()){
		if(cur[ini + i] == s[i]) continue;
		if(easy && cur[ini + i] == '?') continue;
		return false;
	}
	return true;
}

bool ok(string cur){
	int num = 0;
	fr(i, cur.size()) if(match(cur, i, false)) num++;
	return num == 1;
}


signed main(){
	fastio;
	int tst;
	cin >> tst;
	while(tst--){
		cin >> n >> t;
		int achou = 0;
		fr(i, t.size()){
			if(match(t, i, true)){
				string cur = t;
				fr(j, s.size()) cur[i + j] = s[j];
				if(ok(cur)){
					for(auto & x : cur) if(x == '?') x = 'z';
					cout << "Yes" << endl;
					cout << cur << endl;
					achou = 1;
					break;
				}
			}
		}
		if(!achou) cout << "No" << endl;
	}
}