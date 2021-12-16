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
#define INF 2000000000000000100

ll n, p, q;
ll a[MAXN], acu[MAXN], ori[MAXN];

ll get_opt(){
	ll ans = 0;
	for(ll i = n; i >= 1; i--){
		ll l = 0, r = i, m;

		while(l < r - 1){
			m = (l + r)/2;
			ll tam = i - m + 1;
			if((acu[i] - acu[m - 1]) * p >= a[i] * q * tam) r = m;
			else l = m;
		}
		ans = max(ans, i - r + 1);
	}
	return ans;
}

ll ok[MAXN];

void build_ans(ll opt){
	for(ll i = 2; i <= n - opt + 2; i++){
		ll sum = acu[i + opt - 2] - acu[i - 1];
		ll maior = a[i + opt - 2];

		ll l = 0, r = i, m;
		while(l < r - 1){
			ll m = (l + r)/2;

			if((sum + a[m]) * p >= maior * q * opt) r = m;
			else l = m;
		}
		if(r < i){
			ok[r]++;
			ok[i + opt - 1]--;
		}
		//cout << r << " -> " << i << " " << i + opt - 2 << endl;
	}
}

void solve(){
	cin >> n;
	frr(i, n) cin >> a[i], ori[i] = a[i];
	sort(a + 1, a + n + 1);
	frr(i, n) acu[i] = acu[i -1] + a[i];
	frr(i, n) ok[i] = 0;
	cin >> p >> q;

	ll opt = get_opt();
	if(opt == 1){
		cout << 0 << endl << endl;
		return;
	}

	build_ans(opt);
	ll sum = 0;
	set<ll> deu;
	frr(i, n) {
		sum += ok[i];
		if(sum > 0) deu.insert(a[i]);
	}

	vector<ll> ans;
	frr(i, n) if(!deu.count(ori[i])) ans.pb(i);

	cout << ans.size() << endl;
	for(auto x : ans) cout << x << " ";
	cout << endl;
}

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--) solve();
}
