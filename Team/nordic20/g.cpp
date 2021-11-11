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

#define MAXN 1000010
#define MOD 1000000007
#define INF 2000000000000000100

/*
	x -> número de caras completos
*/
/*
	y -> número de 1's sem dois
	t1 -> total de 1's
*/
ll x = 0, y = 0, t1 = 0;
ll ans = 0;
ll n;
ll a[MAXN];


signed main(){
	fastio;
	cin >> n;
	frr(i, n) cin >> a[i];
	frr(i, n){
		if(a[i] == 1){
			t1++;
		}
		else if(a[i] == 3){
			ans = (ans + x) % MOD;
		}
		else{
			x = (2 * x + y + t1) % MOD;
		}
	}
	cout<< ans << endl;
}

