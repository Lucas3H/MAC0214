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

#define MAXN 100010
#define MOD 1000000007
#define INF 1000000000000000100
const ll MAXINV = 16 * (16-1) / 2;

ll dp_only_two[MAXINV + 1], cc[MAXINV + 1], pos[MAXINV + 1];
ll n, a, b, c, d, fat;
void build(){
	mem(dp_only_two, -1);
	mem(cc, 0);

	pq<pii> fila;
	fila.push({0, 0});

	while(fila.size()){
		ll davez = -1;
		while(fila.size()){
			pii p = fila.top();
			fila.pop();
			if(dp_only_two[p.s] == -1){
				dp_only_two[p.s] = -p.f;
				davez = p.s;
				break;
			}
		}

		if(davez == -1) break;
		if(davez < n*(n-1) / 2 && dp_only_two[davez + 1] == -1){
			fila.push({-dp_only_two[davez] - a, davez + 1});
		}
		if(davez > 0 && dp_only_two[davez - 1] == -1){
			fila.push({-dp_only_two[davez] - a, davez - 1});
		}
		if(dp_only_two[n*(n-1)/2 - davez] == -1){
			fila.push({-dp_only_two[davez] - b, n*(n-1)/2 - davez});
		}
	}


	cc[0] = 1;
	for(ll i = 2; i <= n; i++){
		for(ll j = i * (i - 1) / 2; j >= 0; j--){
			for(ll k = 1; k < i; k++){
				if(j - k >= 0)
					cc[j] += cc[j - k];
			}
		}
	}
}

ll inversions(vector<ll> & v){
	ll ans = 0;
	fr(i, v.size()){
		fr(j, i){
			ans += (v[j] > v[i]);
		}
	}
	return ans;
}

signed main(){
	fastio;
	ll t;
	cin >> t;

	while(t--){
		cin >> n >> a >> b >> c >> d;
		build();
		fat = 1;
		frr(i, n) fat = fat * i;

		ll rest = 0, sum = 0;

		vector<pii> dp;
		fr(i, n*(n-1)/2 + 1) {
			dp.pb({dp_only_two[i], i});
			rest += cc[i];
		}
		sort(all(dp));
		ll achou = -1;
		pii ans;
		for(ll i = 0; i < n*(n-1)/2; i++){ 
			ll davez = dp[i].s;
			rest -= cc[davez];
			sum += cc[davez] * dp[i].f;

			ll num = sum + rest * c;
			ll den = fat - rest;
			ll g = __gcd(num, den);
			num /= g;
			den /= g;

			if(dp[i].f * den <= num + c * den && num + c * den < dp[i+1].f * den){
				achou = i;
				ans = {num, den};
			}

			//cout << sum << " " << rest << " " << num << "/" << den << " | ";
		}	
		fr(i, n*(n-1)/2 + 1) pos[dp[i].s] = i;

		if(achou == -1) {
			achou = n*(n-1)/2;
			ans = {sum, fat};
		}
		//dbg(achou);

		while(d--){
			vector<ll> v(n, 0);
			fr(i, n) cin >> v[i];
			ll inv = inversions(v);
			// dbg(inv);
			// dbg(pos[inv]);
			if(pos[inv] <= achou) cout << dp[pos[inv]].f << "/" << 1 << '\n';
			else cout << ans.f + c * ans.s << "/" << ans.s << '\n';
		}
	}
}
