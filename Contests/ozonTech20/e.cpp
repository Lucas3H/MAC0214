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

int ans[MAXN];
int n, m, tot;

int get(int x){
	int val = x/2;
	if(x%2) return (val) * (val);
	else return val * (val - 1);
}

int main(){
	fastio;
	cin >> n >> m;
	frr(i, n) ans[i] = i;

	if(m > get(n)){
		cout << -1 << endl;
		return 0;
	}

	ll sum = 0;

	for(int i = n; i >= 2; i--){
		if(get(i-1) >= m) ans[i] = ans[i] * 2 * n + 1;
		else{
			int gap = m - get(i-1);
			int pos = i - 2*gap;
			ans[i] = ans[pos] + ans[i-1];
			break;
		}
	}

	frr(i, n) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}
