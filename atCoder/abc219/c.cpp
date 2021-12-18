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

int pos[30];

bool comp(string a, string b){
	int i = 0;
	while(i < a.size() && i < b.size() && a[i] == b[i]) i++;
	//cout << a << " " << b  << " " << i << endl;
	if(i == a.size()) return true;
	else if(i == b.size()) return false;
	else return pos[a[i] - 'a'] < pos[b[i] - 'a'];
}

string s[MAXN];

signed main(){
	fastio;
	fr(i, 26){
		char c;
		cin >> c;
		pos[c - 'a'] = i;
	}
	int n;
	cin >> n;
	fr(i, n) cin >> s[i];
	sort(s, s + n, comp);
	fr(i, n) cout << s[i] << endl;
}
