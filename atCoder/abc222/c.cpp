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

#define MAXN 110
#define MOD 1000000007
#define INF 2000000000000000100

int n, m;

// {victories, indice}
pii ranks[MAXN];
char a[MAXN][MAXN];

bool comp(pii l, pii r){
	if(l.f == r.f) return l.s < r.s;
	return l.f > r.f;
}

void proc(int ind){
	for(int i = 1; i <= 2*n; i+=2){
		int x = ranks[i].s, y = ranks[i + 1].s;
		if(a[x][ind] == 'G'){
			if(a[y][ind] == 'C') ranks[i].f++;
			else if(a[y][ind] == 'P') ranks[i + 1].f++;
		}
		else if(a[x][ind] == 'C'){
			if(a[y][ind] == 'G') ranks[i + 1].f++;
			else if(a[y][ind] == 'P') ranks[i].f++;
		}
		else{
			if(a[y][ind] == 'C') ranks[i + 1].f++;
			else if(a[y][ind] == 'G') ranks[i].f++;
		}
	}
	sort(ranks + 1, ranks + 2*n + 1, comp);

	// frr(i, 2*n) cout << ranks[i].s << endl;
	// cout << endl;
}

signed main(){
	fastio;
	cin >> n >> m;
	frr(i, 2*n) frr(j, m) cin >> a[i][j];
	frr(i, 2*n) ranks[i] = {0, i};
	frr(i, m) proc(i);
	frr(i, 2*n) cout << ranks[i].s << endl;
}
