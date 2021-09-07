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

ll n, q;
set<pii> s;
ll nd[4*MAXN];
ll query(ll i, ll l, ll r, ll ql, ll qr){
	if(ql > qr)return 0;
	if(ql > r || l > qr) return 0;
	else if(ql <= l && r <= qr)return nd[i];
	else{
		ll m = (l + r)/2;
		return query(2*i, l, m, ql, qr) + query(2*i + 1, m + 1, r, ql, qr);
	}
}

ll v[MAXN];
void update(ll i, ll l, ll r, ll x, ll val){
	if(x < 1 || x > n) return;
	if(l == r) nd[i] = val;
	else{
		ll m = (l + r)/2;
		if(x <= m) update(2*i, l, m, x, val);
		else update(2*i + 1, m + 1, r , x, val);
	
		nd[i] = nd[2*i] + nd[2*i + 1];
	}
}

ll f(ll l, ll r){
	if(l > r)return 0;
	return (r - l + 1)*(r - l) / 2 + r - l + 1;
}

void update(ll pos, ll val){
	if(v[pos-1] <= v[pos] && v[pos] <= v[pos + 1]){
		if(v[pos-1] > val){
			auto x = s.lower_bound(mp(pos, -1));
			ll l = (*x).s, r = (*x).f;


			update(1, 1, n, pos - 1, f(l, pos - 1));
			update(1, 1, n, r, f(pos, r));
			s.erase(x);

			s.insert({r, pos});
			s.insert({pos - 1, l});
		}
		else if(val > v[pos + 1]){
			auto x = s.lower_bound(mp(pos, -1));
			ll l = (*x).s, r = (*x).f;

			update(1, 1, n, pos, f(l, pos));
			update(1, 1, n, r, f(pos+1, r));
			s.erase(x);

			s.insert({r, pos+1});
			s.insert({pos, l});
		}
	}
	else if(v[pos-1] > v[pos] && v[pos] <= v[pos + 1]){
		if(v[pos - 1] <= val && val <= v[pos + 1]){
			auto x = s.lower_bound(mp(pos - 1, -1));
			ll l = (*x).s, r = (*x).f;
			update(1, 1, n, pos - 1, 0);
			s.erase(x);

			x = s.lower_bound(mp(pos, -1));
			r = (*x).f;
			s.erase(x);
			update(1, 1, n, r, f(l, r));

			//cout << l << " " << r << endl;

			s.insert({r, l});
		}
		if(v[pos - 1] <= val && val > v[pos + 1]){
			auto x = s.lower_bound(mp(pos, -1));
			ll l = (*x).s, r = (*x).f;
			update(1, 1, n, r, f(pos + 1, r));
			s.erase(x);
			if(pos + 1 <= r) s.insert({r, pos + 1});


			x = s.lower_bound(mp(pos - 1, -1));
			l = (*x).s, r = (*x).f;
			//cout << l << " " << pos << endl;

			update(1, 1, n, pos - 1, 0);
			update(1, 1, n, pos, f(l, pos));
			s.erase(x);
			s.insert({pos, l});
		}
		if(v[pos - 1] > val && val > v[pos + 1]){
			auto x = s.lower_bound(mp(pos, -1));
			ll l = (*x).s, r = (*x).f;
			update(1, 1, n, r, f(pos + 1, r));
			s.erase(x);
			if(pos + 1 <= r) s.insert({r, pos + 1});

			update(1, 1, n, pos, 1);
			s.insert({pos, pos});
		}
	}
	else if(v[pos-1] > v[pos] && v[pos] > v[pos + 1]){
		if(val >= v[pos - 1]){
			update(1, 1, n, pos, 0);
			s.erase({pos, pos});

			auto x = s.lower_bound(mp(pos - 1, -1));
			ll l = (*x).s, r = (*x).f;
			s.erase(x);
			update(1, 1, n, pos - 1, 0);
			
			update(1, 1, n, pos, f(l, pos));
			s.insert({pos, l});
		}
		else if(val <= v[pos + 1]){
			update(1, 1, n, pos, 0);
			s.erase({pos, pos});

			auto x = s.lower_bound(mp(pos + 1, -1));
			ll l = (*x).s, r = (*x).f;
			s.erase(x);
			
			update(1, 1, n, r, f(pos, r));
			s.insert({r, pos});
		}
	}
	else if(v[pos-1] <= v[pos] && v[pos] > v[pos + 1]){
		if(v[pos - 1] <= val && val <= v[pos + 1]){
			auto x = s.lower_bound(mp(pos, -1));
			ll l = (*x).s, r = (*x).f;
			update(1, 1, n, pos, 0);
			s.erase(x);

			x = s.lower_bound(mp(pos + 1, -1));
			r = (*x).f;
			s.erase(x);
			update(1, 1, n, r, f(l, r));

			s.insert({r, l});
		}
		else if(val <= v[pos + 1]){
			auto x = s.lower_bound(mp(pos, -1));
			ll l = (*x).s, r = (*x).f;
			update(1, 1, n, pos - 1, f(l, pos - 1));
			update(1, 1, n, pos, 0);
			s.erase(x);
			if(pos - 1 >= l) s.insert({pos - 1, l});


			x = s.lower_bound(mp(pos + 1, -1));
			l = (*x).s, r = (*x).f;

			update(1, 1, n, r, f(pos, r));
			s.erase(x);
			s.insert({r, pos});
		}
		else if(v[pos - 1] > val && val > v[pos + 1]){
			auto x = s.lower_bound(mp(pos, -1));
			ll l = (*x).s, r = (*x).f;
			update(1, 1, n, pos - 1, f(l, pos - 1));
			s.erase(x);
			s.insert({pos - 1, l});

			update(1, 1, n, pos, 1);
			s.insert({pos, pos});
		}
	}


	v[pos] = val;

	// frr(i, n) cout << v[i] << " ";
	// cout<< endl;
	// for(auto x: s){
	// 	cout<< x.s << " " << x.f << endl;
	// }
}
 
ll query(ll l, ll r){
	ll ans = 0;

	auto xl = s.lower_bound(mp(l - 1, -1));
	ll ql = (*xl).f + 1;

	ans += f(l, ql - 1);

	auto xr = s.lower_bound(mp(r + 1, -1));
	ll qr = (*xr).s - 1;

	ans += f(qr + 1, r);


	if(ql > qr) return f(l, r);
	//cout << ql << " " << qr << " " << ans << endl;
	// cout << f(qr + 1, r) << " " << f(l, ql - 1) << endl;


	return ans + query(1, 1, n, ql, qr);
}

void build(){
	ll l = 1, r = 1;
	while(r < n){
		if(v[r + 1] >= v[r]) r++;
		else{
			s.insert({r, l});
			update(1, 1, n, r, f(l, r));
			l = r + 1, r = r + 1;
		}
	}
	s.insert({r, l});
	update(1, 1, n, r, f(l, r));
	s.insert({n + 1, n + 1});
	s.insert({0, 0});
}

signed main(){
	fastio;
	cin >> n >> q;
	v[0] = MOD;
	v[n +1] = -MOD;
	frr(i, n) cin >> v[i];

	build();

	while(q--){
		ll op, a, b;
		cin >> op >> a >> b;

		if(op == 1) update(a, b);
		else cout << query(a, b) << endl;
	}
}
