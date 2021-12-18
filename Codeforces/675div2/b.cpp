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
typedef pair<ll, ll> pll;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 100010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

ll best(ll a, ll b, ll c, ll d){
	ll v[4] = {a, b, c, d};

	sort(v, v + 4);

	return (v[1] - v[0] + v[2] - v[1] + v[3] - v[1]);
}

int main(){
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;

	while(t--){
		ll n, m;
		cin >> n >> m;
		ll a[200][200];

		fr(i, n){
			fr(j, m) cin >> a[i][j];
		}

		ll ans = 0;

		fr(i, (n + 1)/2){
			fr(j, (m + 1)/2){
				
				if(i == n - i - 1 || j == m - j - 1) ans += best(a[i][j], a[n - 1 - i][j], a[i][m - 1 - j], a[n - 1 - i][m - 1 - j])/2;
				else ans += best(a[i][j], a[n - 1 - i][j], a[i][m - 1 - j], a[n - 1 - i][m - 1 - j]);
				//cout << i << " " << j << " " << ans << endl;
			}
		}

		cout << ans << endl;
	}
}
