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

int m[MAXN][5];
int n;

bool superior(int i, int j){
	int sum = 0;
	fr(k, 5) sum += m[i][k] < m[j][k];
	return sum >= 3;
}

int main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		cin >> n;
		fr(i, n) fr(j, 5) cin >> m[i][j];

		int davez = 0;
		frr(i, n-1){
			if(superior(i, davez)) davez = i;
		}

		bool ok = true;
		fr(i, n){
			if(i != davez && superior(i, davez)) ok = false; 
		}

		if(ok) cout << davez+1 << '\n';
		else cout << -1 << '\n';
 	}
}
