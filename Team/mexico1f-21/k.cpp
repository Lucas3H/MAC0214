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
#define INF 2000000000000000100

void solve(string & s){
	s = '0' + s;
	vector<int> v;
	int sum = 0;
	for(auto x: s){
		sum += x - '0';
	}

	if(sum%3 == 0){
		v.pb(3);
	}
	int num = (s[s.size() - 2] - '0')*10 + (s[s.size() - 1] - '0');
	if(num%2 == 0){
		v.pb(2);
	}
	if(v.size() == 2) v.pb(6);
	if(num%5 == 0) v.pb(5);
	if(num%4 == 0) v.pb(4);
	sort(all(v));
	if(v.size() == 0) cout << -1 << endl;
	else{
		for(int i = 0; i < v.size() - 1; i++) cout << v[i] << " ";
		cout << v.back() << endl;
	}
}

string s;
		
signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		cin >> s;
		solve(s);
	}
}
