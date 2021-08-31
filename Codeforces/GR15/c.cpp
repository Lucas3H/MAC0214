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

int n, k;
int marked[MAXN];
pii seg[MAXN];
int solve(int a, int b){
	int x = 0;
	for(int i = a; i != b; i = (i + 1) % (2*n)){
		x += (marked[i] == 0);
	}
	return min(x, 2*n - 2*k - x);
}

int intersec(int a, int b, int c, int d){
	int sum = 0;
	for(int i = a; i != b; i = (i + 1) % (2*n)){
		if(i == c || i == d) sum++;
	}
	return sum%2;
}

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		cin >> n >>  k;
		fr(i, 2*n) marked[i] = 0;
		fr(i, k) {
			cin >> seg[i].f >> seg[i].s;
			seg[i].f--;
			seg[i].s--;
			marked[seg[i].f] = 1;
			marked[seg[i].s] = 1;
		}

		int ans = 0;
		fr(i, k) ans += solve(seg[i].f, seg[i].s);
		fr(i, k){
			fr(j, i) ans += intersec(seg[i].f, seg[i].s, seg[j].f, seg[j].s);
		}
		int r = n - k;
		cout << ans + r*(r-1)/2 << '\n';
	}
}
