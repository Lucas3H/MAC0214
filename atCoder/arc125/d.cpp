#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_ll_distribution<ll>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 200010
#define MOD 998244353
#define INF 1000000000000000100

struct BIT{
    vector<ll> bit;
    ll n;

    BIT() : n(0) {};
    BIT(ll tam){n = tam, bit.resize(n + 1, 0);}
    BIT(vector<ll> & a){
        n = (ll)a.size(), bit.resize(n + 1, 0);
        for(ll i = 1; i <= n; i++) update(i, a[i-1]);
    }
    BIT(ll a[], ll tam){
        n = tam, bit.resize(n + 1, 0);
        for(ll i = 1; i <= n; i++) update(i, a[i-1]);
    } 
    
    inline ll op(ll x, ll y) {return (x + y) % MOD;}
    
    void update(ll i, ll val){
        for(; i <= n; i += i & (-i)) bit[i] = op(bit[i], val);
    }

    ll query(ll i){
        ll sum = 0;
        for(; i > 0; i -= i & (-i)) sum = op(sum, bit[i]);
        return sum;
    }

    /*Lower_bound*/
    ll lower_bound(ll v){
	    ll sum = 0, pos = 0;
        for(ll i = (ll)ceil(log2(n)); i >= 0; i--){
            if(pos + (1 << i) < n && op(sum, bit[pos + (1 << i)]) < v){
                sum = op(sum, bit[pos + (1 << i)]);
                pos += (1 << i);
            }
        }
	    return pos + 1; 
    } 
};

BIT b(MAXN);
ll last[MAXN];
ll a[MAXN], val[MAXN];
ll n;

signed main(){
	fastio;
	cin >> n; frr(i, n) cin >> a[i];

	frr(i, n){
		if(last[a[i]] == 0){
			val[i] = (b.query(i) + 1)%MOD;
		}
		else{
			val[i] = ((b.query(i) - b.query(last[a[i]] - 1))%MOD + MOD)%MOD;
			b.update(last[a[i]], -val[last[a[i]]]);
		}

		//dbg(val[i]);
		b.update(i, val[i]);
		last[a[i]] = i;
	}

	cout << (b.query(n)%MOD + MOD)%MOD << endl;
}
