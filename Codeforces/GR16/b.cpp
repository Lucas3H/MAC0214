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

string s;

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		cin >> s;

		// 1 se tem no max 1 bloco de 0
		// 0 se é tudo 1
		// 2 caso contrario
		vector<int> b;
		int i = 0;
		while(i < s.size()){
			int ini = i;
			while(i < s.size() && s[i] == s[ini]) i++;
			b.pb(i - ini);
		}

		if(b.size() == 1){
			if(s[0] == '1') cout<< 0 << endl;
			else cout<<1 << endl;
		}
		else if(b.size() == 2) cout <<1  << endl;
		else if(b.size() == 3){
			if(s[0] == '1') cout << 1 << endl;
			else cout << 2 << endl;
		}
		else cout << 2 << endl;

	}
}
