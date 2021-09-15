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

struct BIT{
    vector<int> bit;
    int n;

    BIT() : n(0) {};
    BIT(int tam){n = tam, bit.resize(n + 1, 0);}
    BIT(vector<int> & a){
        n = (int)a.size(), bit.resize(n + 1, 0);
        for(int i = 1; i <= n; i++) update(i, a[i-1]);
    }
    BIT(int a[], int tam){
        n = tam, bit.resize(n + 1, 0);
        for(int i = 1; i <= n; i++) update(i, a[i-1]);
    } 
    
    inline int op(int x, int y) {return x + y;}
    
    void update(int i, int val){
        for(; i <= n; i += i & (-i)) bit[i] = op(bit[i], val);
    }

    int query(int i){
        int sum = 0;
        for(; i > 0; i -= i & (-i)) sum = op(sum, bit[i]);
        return sum;
    }
};

int x[MAXN], y[MAXN];
int n;

set<int> meio;
BIT b(1001);


signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> x[i] >> y[i];

	vector<array<int, 3>> v;
	fr(i, n) v.pb({-x[i], y[i], i});
	sort(all(v));

	int melhor, pior;

	fr(i, n){
		if(v[i][2] == 0){
			melhor = i - b.query(v[i][1]) + 1;
			break;
		}
		b.update(v[i][1], 1);
	}

	v.clear();
	fr(i, n) v.pb({x[i], y[i], i});
	sort(all(v));

	b = BIT(1001);

	fr(i, n){
		if(v[i][2] == 0){
			pior = n - (b.query(v[i][1]));
			break;
		}
		b.update(v[i][1], 1);
	}

	cout << melhor << " " << pior << endl;
}
