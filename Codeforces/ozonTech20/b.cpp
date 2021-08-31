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

#define mp make_pair
#define pq priority_queue

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

int open[MAXN], close[MAXN];
string s;

int main(){
	fastio;
	cin >> s;
	fr(i, s.size()){
		open[i+1] = open[i];
		close[i+1] = close[i];
		if(s[i] == '(') open[i+1]++;
		else close[i+1]++;
	}

	int ans = 0, n = s.size();
	fr(i, n+1){
		if(close[n] - close[i] == open[i]){
			ans = i;
			break;
		}
	}

	vector<int> pos;
	fr(i, ans) if(s[i] == '(') pos.pb(i+1);
	for(int i = ans; i < n; i++) if(s[i] == ')') pos.pb(i+1);
	if(pos.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << 1 << endl;
	cout << pos.size() << endl;
	
	for(auto x: pos) cout << x << " ";
	cout << endl;
}
