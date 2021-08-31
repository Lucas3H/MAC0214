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

#define MOD 1000000007
#define MAXN 600010
#define INF 1000000000000000100

pii nd[4*MAXN], lz[4*MAXN];

void build(ll i, ll l, ll r){
	if(l == r){
		nd[i] = lz[i] = {MOD, MOD};
		return;
	}

	ll m = (l + r)/2;
	build(2*i, l, m);
	build(2*i + 1, m + 1, r);
	nd[i] = {MOD, MOD};
}

void push(ll i, ll l, ll r){
	if(lz[i].f != MOD){
		nd[i] = lz[i];
		if(l < r) lz[2*i] = lz[2*i + 1] = lz[i];
		lz[i].f = MOD;
	}
}

void update(ll i, ll l, ll r, ll ql, ll qr, ll val, ll linha){
	push(i, l, r);
	if(l > qr || ql > r)return ;
	else if(ql <= l && r <= qr){
		lz[i] = {val, linha};
		push(i, l, r);
	}
	else{
		ll m = (l + r)/2;
		update(2*i, l, m, ql, qr, val, linha);
		update(2*i + 1, m + 1, r, ql, qr, val, linha);
		if(nd[2*i] > nd[2*i + 1]) nd[i] = nd[2*i + 1];
		else nd[i] = nd[2*i];
	}
}

pii query(ll i, ll l, ll r, ll ql, ll qr){
	push(i, l, r);
	if(l > qr || ql > r)return {MOD, MOD};
	else if(ql <= l && r <= qr) return nd[i];
	else{
		ll m = (l + r)/2;
		pii lft = query(2*i, l, m, ql, qr), rgt = query(2*i + 1, m + 1, r, ql, qr);
		if(lft.f < rgt.f) return lft;
		else return rgt;
	}
}

vector<pii> row[MAXN];

ll pai[MAXN];
ll ok[MAXN];

signed main(){
	fastio;
	ll n, m;
	cin >> n >> m;
	map<ll, ll> comp;
	ll it = 0;
	fr(i, m){
		ll ind, l, r;
		cin >> ind >> l >> r;
		row[ind].pb({l, r});
		comp[l], comp[r];
	}
	for(auto &x: comp) x.s = ++it;

	frr(i, n) for(auto & p: row[i]) 
		p.f = comp[p.f], p.s = comp[p.s];

	build(1, 1, it);

	ll ans = n-1, last = 1;
	frr(i, n){
		ll dp = 0, nxt = 0;
		for(auto p : row[i]){
			//cout << p.f << " "<< p.s << endl;
			pii davez = query(1, 1, it, p.f, p.s);
			if(dp > davez.f) {
				dp = davez.f;
				nxt = davez.s;
			}
		}
		pai[i] = nxt;
		dp = dp + i - 1;
		for(auto p : row[i]){
			//cout << p.f << " " << p.s << endl;
			update(1, 1, it, p.f, p.s, dp - i, i);
		}
		//dbg(dp);
		if(ans > dp + n - i) last = i;
		ans = min(ans, dp + n - i);
	}

	cout << ans << endl;
	while(last != 0){
		ok[last] = 1;
		last = pai[last];
	}
	frr(i, n) if(!ok[i]) cout << i << ' ';
	cout << endl;
}
