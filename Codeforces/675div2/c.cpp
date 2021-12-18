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

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;

	ll sum = 0, pwr2 = 1, n[MAXN], ans = 0, tot = 0;

	fr(i, s.size()){
		ll d = s[i] - '0';
		
		if(i > 0) {
			n[i] = (n[i-1]*(ll)10 + d)%MOD;
			ans = (ans*(ll)10 + d*((i-1)*(i)/2 + (ll)1))%MOD;
			//cout << ans << endl;
			ans = (ans + (sum - n[i-1] + MOD)*(ll)10 + i*d)%MOD;
			//cout << ans << endl;

			//cout << ans << " " << sum << endl;
		}
		else ans = d, n[0] = d;
		sum = (n[i] + sum)%MOD;
	}

	cout << (ans + sum - 2*n[s.size() - 1] + 2*MOD)%MOD << endl;

}
