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

#define MAXN 200010
#define MOD 1000000007
#define INF 1000000000000000100

int f1 = 0;
multiset<int> v;
int vals[MAXN], l[MAXN], r[MAXN], x[MAXN], ans[MAXN];
int n, m;

/*
	{tipo, ind};
*/
vector<int> q[2][MAXN];

signed main(){
	fastio;
	cin >> n >> m;
	fr(i, m){
		cin >> l[i] >> r[i] >> x[i];
		q[0][l[i]].pb(i), q[1][r[i]].pb(i);
	}

	frr(i, n){
		for(auto ind: q[0][i]){
			v.insert(r[ind] - x[ind] - f1);
			vals[ind] = r[ind] - x[ind] - f1;
		//	cout << "insere " << vals[ind] << " " << ind << endl;
		}

		if(v.size() > 0 && *(v.begin()) < i - f1){
			ans[i] = 1;
			f1++;
		}

		for(auto ind: q[1][i]){
		//	cout << "apaga " << vals[ind] <<endl;
			v.erase(v.find(vals[ind]));
		}
	}
	frr(i, n) cout<< ans[i] << ' ';
	cout << endl;
}	
