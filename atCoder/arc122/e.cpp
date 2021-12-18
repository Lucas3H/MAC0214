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
#define INF 2000000000000000100

vector<ll> ans;
ll n;
ll a[MAXN];

bool get(ll tam, ll ind){
	ll r = 1;

	fr(i, tam){
		if(i != ind){
			ll g = __gcd(a[i], a[ind]);
			ll d = __gcd(r, g);
			r = (__int128) r * g / d % a[ind]; 
		}
	}

	if(r == 0) return false;
	else return true;
}

signed main(){
	fastio;
	cin >> n;
	fr(i, n) cin >> a[i];
	for(int i = n; i > 1; i--){
		bool ok = false;
		fr(j, i) if(get(i, j)) {
			swap(a[j], a[i - 1]);
			ok = true;
			break;
		}
		if(!ok){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	fr(i, n) cout << a[i] << " ";
	cout << endl;
}
