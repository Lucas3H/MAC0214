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

ll a[MAXN], b[MAXN], c[MAXN];
ll n, m;

bool comp1(ll x, ll y){
	return a[x] > a[y];
}

bool comp2(ll x, ll y){
	return (uint64_t)c[x] * (uint64_t)b[y] < (uint64_t)c[y] * (uint64_t)b[x];
}


signed main(){
	fastio;
	cin >> n >> m;
	frr(i, n) cin >> a[i];
	frr(i, m) cin >> b[i];
	frr(i, m) cin >> c[i];

	deque<ll> snacks, childs;
	frr(i, n) snacks.pb(i);
	frr(i, m) childs.pb(i);

	sort(all(snacks), comp1);
	sort(all(childs), comp2);

	ll tam = 0;
	ll sum_snacks = 0, sum_b = 0;
	frr(i, n) sum_snacks += a[i];
	frr(i, m) sum_b += b[i];
	ll ans = sum_snacks, sum_c = 0;

	frr(i, n){
		sum_snacks -= a[snacks[i-1]];
		while(childs.size()){
			if(i * b[childs.front()] >= c[childs.front()]){
				sum_b -= b[childs.front()];
				sum_c += c[childs.front()];
				childs.pop_front();
			}
			else break;
		}
		ans = min(ans, sum_snacks + sum_c + i * sum_b);
	}
	cout << ans << endl;
}
