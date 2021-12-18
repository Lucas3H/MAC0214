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

#define MAXN 1001
#define MOD 1000000007
#define INF 2000000000000000100

ll a[MAXN][MAXN];
ll h, w;
ll h1, w1, h2, w2;
ll acu[MAXN][MAXN], val1[MAXN][MAXN], val2[MAXN][MAXN];
struct SEG2D{
	ll n,m;
	ll st[2*MAXN][2*MAXN];

	SEG2D(ll r, ll c){
		n = r, m = c;
		build();
	}
	SEG2D(){
		n = 0, m = 0;
	}

	ll op(ll a, ll b){return max(a, b);}

	void build(){
		fr(i, n)fr(j, m)st[i+n][j+m]=val2[i][j];
		fr(i, n)for(ll j=m-1;j;--j)
			st[i+n][j]=op(st[i+n][j<<1],st[i+n][j<<1|1]);
		for(ll i=n-1;i;--i)fr(j, 2*m)
			st[i][j]=op(st[i<<1][j],st[i<<1|1][j]);
		//fr(i, 2 * n) fr(j, 2 * m) dbg(st[i][j]);
	}
	ll query(ll x0, ll x1, ll y0, ll y1){
		ll r=0;
		for(ll i0=x0+n,i1=x1+n;i0<i1;i0>>=1,i1>>=1){
			ll t[4],q=0;
			if(i0&1)t[q++]=i0++;
			if(i1&1)t[q++]=--i1;
			fr(k, q)for(ll j0=y0+m,j1=y1+m;j0<j1;j0>>=1,j1>>=1){
				if(j0&1){
					r=op(r,st[t[k]][j0++]);
				}
				if(j1&1){
					r=op(r,st[t[k]][--j1]);
				}
			}
		}
		return r;
	}
};

SEG2D seg;

signed main(){
	fastio;
	cin >> h >> w >> h1 >> w1 >> h2 >> w2;
	fr(i, h) fr(j, w) cin >> a[i][j];
	h2 = min(h2, h1), w2 = min(w2, w1);

	frm(i, h) frm(j, w){
		acu[i][j] = acu[i + 1][j] + acu[i][j + 1] - acu[i + 1][j + 1] + a[i][j];
	}

	fr(i, h) fr(j, w){
		val1[i][j] = acu[i][j] - acu[i + h1][j] - acu[i][j + w1] + acu[i + h1][j + w1];
		val2[i][j] = acu[i][j] - acu[i + h2][j] - acu[i][j + w2] + acu[i + h2][j + w2];
	}
	// fr(i, h) {
	// 	fr(j, w) cout << val2[i][j] << " ";
	// 	cout << endl;
	// }


	seg = SEG2D(h, w);
	ll ans = 0;
    fr(i, h - h1 + 1) fr(j, w - w1 + 1){
    	// cout << i << " " << j << endl;
    	// dbg(val1[i][j]);
    	// cout << i << " " << i + h1 - h2 << endl;
    	// cout << j << " " <<  j + w1 - w2 << endl;
    	// dbg(seg.query(i, i + h1 - h2, j, j + w1 - w2));
    	ans = max(ans, val1[i][j] - seg.query(i, i + h1 - h2 + 1, j, j + w1 - w2 + 1));

    	// dbg(ans);
    }
    cout << ans << endl;
}
