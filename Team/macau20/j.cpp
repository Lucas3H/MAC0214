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
#define MOD 1000000007
#define INF 1000000000000000100

ll n, m;

struct SEG{
	ll nd[4*MAXN];
	ll v[MAXN];
	ll t;

	ll op(ll a, ll b){
		if(t == 0) return max(a, b);
		else return a + b;
	}

	void build(ll i, ll l, ll r){
		if(l == r) nd[i] = v[l];
		else{
			ll m = (l + r)/2;
			build(2*i, l, m);
			build(2*i + 1, m + 1, r);
			nd[i] = op(nd[2*i], nd[2*i + 1]);
		}
	}

	void update(ll i, ll l, ll r, ll pos, ll val){
		if(l == r) nd[i] = val;
		else{
			ll m = (l + r)/2;
			if(pos <= m) update(2*i, l, m, pos, val);
			else update(2*i + 1, m + 1, r, pos, val);
			nd[i] = op(nd[2*i], nd[2*i + 1]);
		}
	}

	ll query(ll i, ll l, ll r, ll ql, ll qr){
		if(ql > r || l > qr) return 0;
		else if(ql <= l && r <= qr) return nd[i];
		else{
			ll m = (l + r)/2;
			return op(query(2*i, l, m, ql, qr), query(2*i + 1, m + 1, r, ql ,qr));
		}
	}

	array<ll, 3> find(ll i, ll l, ll r, ll ql, ll qr, ll start){
		if(ql > r || l > qr) return {-1, -1, -1};
		else if(ql <= l && r <= qr) {
			if(nd[i] >= start)return {i, l, r};
			else return {-1, -1, -1};	
		}
		else{
			ll m = (l + r)/2;
			array<ll, 3> esq = find(2*i, l, m, ql, qr, start);
			array<ll, 3> dir = find(2*i + 1, m + 1, r, ql, qr, start);
			if(esq[0] != -1) return esq;
			else return dir;
		}
	}

	ll search(ll start, ll val){
		array<ll, 3> v = find(1, 1, n, start, n, val);

		if(v[0] == -1) return n + 1;

		ll l = v[1], r = v[2], i = v[0];
		while(l < r){
			ll m = (l + r)/2;
			if(nd[2*i] >= val){
				r = m;
				i = 2*i;
			}
			else{
				l = m + 1;
				i = 2*i + 1;
			}
		}
		return l;
	}
};

SEG maximo, sum;
set<ll> pos_color[MAXN];

ll find(ll ini, ll start){
	ll l = ini, r = n + 1, m;
	while(l < r - 1){
		m = (l + r)/2;
		if(maximo.query(1, 1, n, ini, m) >= start) r = m;
		else l = m;
	}
	return r;
}


ll c[MAXN], v[MAXN], prv[MAXN], last[MAXN];
ll query(ll ini, ll k){
	ll removed = 0, repeated = 1, davez = maximo.search(ini, ini);
	map<ll, vector<ll>> used;
	while(davez != n + 1 && repeated <= k){
		if(used[c[davez]].size() == 0) 
			used[c[davez]].pb(v[prv[davez]]);

		//cout << davez << ' ' << v[davez] << endl;

		used[c[davez]].pb(v[davez]);
		davez = maximo.search(davez + 1, ini);
		repeated++;
	}

	for(auto x: used){
		sort(all(x.s));
		fr(i, x.s.size() - 1) removed += x.s[i];
	}

	//cout << ini << " | " << davez - 1 << endl;

	return sum.query(1, 1, n, ini, davez - 1) - removed;
}

void update(ll pos, ll new_c, ll new_v){
	auto x = pos_color[c[pos]].lower_bound(pos + 1);
	if(x != pos_color[c[pos]].end()){
		ll davez = *x;
		prv[davez] = prv[pos];
		maximo.update(1, 1, n, davez, prv[davez]);
	}
	else last[c[pos]] = prv[pos];

	pos_color[c[pos]].erase(pos);


	c[pos] = new_c;
	pos_color[c[pos]].insert(pos);

	x = pos_color[c[pos]].lower_bound(pos + 1);
	if(x != pos_color[c[pos]].end()){
		ll davez = *x;
		prv[pos] = prv[davez];
		prv[davez] = pos;
		maximo.update(1, 1, n, davez, prv[davez]);
		maximo.update(1, 1, n, pos, prv[pos]);
	}
	else{
		prv[pos] = last[c[pos]];
		last[c[pos]] = pos;
		maximo.update(1, 1, n, pos, prv[pos]);
	}


	v[pos] = new_v;
	sum.update(1, 1, n, pos, new_v);
}

signed main(){
	fastio;
	cin >> n >> m;
	frr(i, n) cin >> c[i] >> v[i];
	frr(i, n){
		prv[i] = last[c[i]];
		last[c[i]] = i;
		pos_color[c[i]].insert(i);
	}

	maximo.t = 0, sum.t = 1;
	frr(i, n){
		maximo.v[i] = prv[i];
		sum.v[i] = v[i];
	}
	sum.build(1, 1, n), maximo.build(1, 1, n);

	//cout << maximo.search(4, 1) << endl;

	while(m--){
		ll op, a, b, c;
		cin >>  op >> a >> b;
		if(op == 1){
			cin >> c;
			update(a, b, c);
		}
		else cout << query(a, b) << '\n';
	}
}
