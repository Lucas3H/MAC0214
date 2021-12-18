#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i <= n; i++)
#define frm(i, n) for(ll i = (ll)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_ll_distribution<ll>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 1000010
#define MOD 1000000007
#define INF 2000000000000000100

ll ans[MAXN][2];
ll m, d;
ll r[MAXN], s[MAXN];

void solve(ll n, ll ind){
	set<pii> line;
	ll in = 0, ir = 0, sum = 0;
	while(in < n && ir < m){
		if(in * d <= r[ir + 1]){
			sum += s[ir];
			line.insert({r[ir + 1] - in*d + 1, ir + 1});
			in++;
		}
		else ir++;
	}
	for(ll i = 0; i <= d; i++){
		while(line.size()){
			pii p = (*line.begin());
			if(p.f > i) break;

			line.erase(line.begin());
			sum -= s[p.s - 1];
			sum += s[p.s];
			if(p.s < m) line.insert({i + r[p.s + 1] - r[p.s], p.s + 1});
		}

		ans[i][ind] = sum;
		//cout << i << " " << sum << endl;
	}
}

ll n;
signed main(){
	fastio;
	cin >> n >> m >> d;
	fr(i, m + 1) cin >> r[i];
	fr(i, m) cin >> s[i];

	if(n == 1){
		cout << s[0] << endl;
		return 0;
	}

	solve(n / 2, 0);
	cout<< endl;
	solve((n + 1)/2, 1);

	ll ret = 0;
	//cout << ans[1][0] << " " << ans[2][1] << endl;
	for(ll i = 0; i <= d; i++){
		ret = max(ret, ans[i][0] + ans[d - i][1]);
	}
	cout << ret << endl;
}
