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

int n, m;
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
    
    inline int op(int x, int y) {return max(x, y);}
    
    void update(int i, int val){
        for(; i <= n; i += i & (-i)) bit[i] = op(bit[i], val);
    }

    int query(int i){
        int sum = 0;
        for(; i > 0; i -= i & (-i)) sum = op(sum, bit[i]);
        return sum;
    }

    /*Lower_bound*/
    int lower_bound(int v){
	    int sum = 0, pos = 0;
        for(int i = (int)ceil(log2(n)); i >= 0; i--){
            if(pos + (1 << i) < n && op(sum, bit[pos + (1 << i)]) < v){
                sum = op(sum, bit[pos + (1 << i)]);
                pos += (1 << i);
            }
        }
	    return pos + 1; 
    } 
};

BIT b;

vector<int> a[MAXN];
ll dp[MAXN];


signed main(){
	fastio;
	cin >> n >> m;
	b = BIT(n);

	frr(i, m){
		int x, y;
		cin >> x >> y;
		a[x].pb(y);
	}

	frr(i, n){
		sort(all(a[i]));
		frm(j, (int)a[i].size()){
			int x = a[i]	[j];
			int val = b.query(x - 1);
			if(dp[x] < val + 1){
				b.update(x, val + 1);
				dp[x] = val + 1;
				//cout << i << " | " << x << " " << dp[x] << endl;
			}
		}
	}

	cout << b.query(n) << endl;
}
