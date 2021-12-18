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

char e[51][51];
int n;

pii nxt(int i, int j){
	if(j == n - 1) return {i + 1, i + 2};
	else return {i, j + 1};
}

signed main(){
	fastio;
	cin >> n;
	if(n < 6 || (n - 1) * n % 3 != 0){
		cout << "No" << endl;
		return 0;
	}
	fr(i, n) fr(j, n) e[i][j] = 'W';

	int lim = n * (n - 1) / 6;
	pii p = {0, 1};
	fr(i, lim){
		e[p.f][p.s] = 'R';
		e[p.s][p.f] = 'R';
		p = nxt(p.f, p.s);
	}
	int davez = p.f, last = p.s, cur = lim;
	for(int i = last; i < n; i++){
		e[davez][i] = 'B';
		e[i][davez] = 'B';
		cur--;
	}
	for(int l = davez + 1; l < last; l++){
		for(int r = last; r < n; r++){
			e[l][r] = 'B';
			e[r][l] = 'B';
			cur--;
		}
	}

	fr(i, n) {
		fr(j, i){
			if(cur == 0) break;
			if(e[i][j] == 'W'){
				e[i][j] = 'B';
				e[j][i] = 'B';
				cur--;
			}
		}

		if(cur == 0) break;
	}

	fr(i, n) fr(j, i) fr(k, j){
		if(e[i][j] != e[i][k] && e[i][k] != e[k][j] && e[i][j] && e[j][j]){
			assert(0);
			return 0;
		}
	}

	cout << "Yes" << endl;
	fr(i, n - 1){
		for(int j = i + 1; j < n; j++) cout << e[i][j];
		cout << endl;
	}
}
