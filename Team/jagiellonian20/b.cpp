#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define mp make_pair
#define pq priority_queue

#define MAXN 1000010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 1000000000000000100

void solve(deque<ll> & fr, ll k){
	if(k == 0) return;
	deque<ll> l;
	fr(i, (1 << (k - 1))) {
		l.pb(fr.front());
		fr.pop_front();
	}

	solve(l, k-1), solve(fr, k-1);
	fr(i, (1 << (k - 1))){
		l.pb(fr[i] + l[i]);
	}
	// for(auto x: salva) cout << x << ' ';
	// cout << endl;

	// for(auto x: l) cout << x << ' ';
	// cout << endl;
	fr = l;
}	

deque<ll> fr;
		
int main(){
	fastio;
	ll t;
	cin >> t;

	while(t--){
		fr.clear();
		ll n;
		cin >> n;
		fr.resize((1 << 20), 0);
		fr(i, n){
			ll a;
			cin >> a;
			fr[a]++;
		}

		deque<ll> novo = fr;
		solve(fr, 20);
		ll ans = 0;
		fr(i, (1 << 20)) ans += (ll)fr[i]*novo[i];
		cout << ans << endl;
	}

}
