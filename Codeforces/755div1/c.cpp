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

#define MAXN 300010
#define MOD 1000000007
#define INF 1000000000000000100

ll n;
vector<ll> acu;

vector<ll> bit[2];
    
struct BIT{
    ll n, tipo = 0; // 0 is min and 1

    BIT() : n(0) {};
    BIT(ll tam, ll t){
    	n = tam;
    	tipo = t;
    	bit[tipo].clear();
    	if(tipo) bit[tipo].resize(n + 1, -INF);
    	else bit[tipo].resize(n + 1, INF);
    }
    
    inline ll op(ll x, ll y) {return (tipo ? max(x, y) : min(x, y));};
    
    void update(ll i, ll val){
        for(; i <= n; i += i & (-i)) bit[tipo][i] = op(bit[tipo][i], val);
    }

	ll sum;
    ll query(ll i){
        if(tipo) sum = -INF;
        else sum = INF;
        for(; i > 0; i -= i & (-i)) sum = op(sum, bit[tipo][i]);
        return sum;
    }

    ll pos = 0;
    ll upper_bound(ll v){
	    sum = 0, pos = 0;
	    if(tipo) sum = -INF;
        else sum = INF;
        for(ll i = (ll)ceil(log2(n)); i >= 0; i--){
            if(pos + (1 << i) <= n){
            	if(tipo == 1 && op(sum, bit[tipo][pos + (1 << i)]) <= v){
                	sum = op(sum, bit[tipo][pos + (1 << i)]);
                	pos += (1 << i);
                }
                if(tipo == 0 && op(sum, bit[tipo][pos + (1 << i)]) >= v){
                	sum = op(sum, bit[tipo][pos + (1 << i)]);
                	pos += (1 << i);
                }
            }
        }
	    return pos + 1; 
    } 
};

BIT minimo, maximo;
map<ll, vector<ll>> m;

ll lowerBound(vector<ll> & v, ll val){
	ll l = -1, r = v.size(), m;
	while(l < r - 1){
		m = (l + r)/2;
		if(v[m] >= val) l = m;
		else r = m;
	}
	return v.size() - r;
}

ll aux, lim;
ll update(ll ind){
	lim = min(minimo.upper_bound(acu[ind]), maximo.upper_bound(acu[ind]));
	aux = lowerBound(m[acu[ind]], lim);
	if(ind == 0) return aux;

	m[acu[ind]].push_back(ind);
	if(ind % 2) minimo.update(ind, acu[ind]);
	else maximo.update(ind, acu[ind]);

	return aux;
}

void solve(){
	m.clear();
	cin >> n;
	minimo = BIT(n, 0);
	maximo = BIT(n, 1);
	acu.resize(n + 1);
	acu[0] = 0;

	frr(i, n) {
		cin >> acu[i];
		if(i%2) acu[i] = acu[i - 1] + acu[i];
		else acu[i] = acu[i - 1] - acu[i];
	}
	ll ans = 0;
	for(ll i = n; i >= 0; i--){
		ans += update(i);
		acu.pop_back();
	}
	cout << ans << endl;
}

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--) solve();
}
