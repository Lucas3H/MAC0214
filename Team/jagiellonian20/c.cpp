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
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 100010
#define MOD 1000000007
#define INF 1000000000000000100

ll n, d;
deque<ll> h;

signed main(){
	fastio;
	ll t;

	cin >> t;

	while (t--){
		cin>>n >> d;
		h.resize(n);
		for (int i = 0; i < n; i++) cin>>h[i];
		sort(all(h));
		frr(i, n + 1) h.push_front(-i*d);
		n = 2*n + 1;
		fr(i, n) h[i] = h[i] - i*d;
		// fr(i, n) cout << h[i] << " ";
		// cout << endl;
		

		ll slope = 0, linear = 0;
		priority_queue< pair<ll, ll> > pq;

		for (int i = 0; i < n; i++){
			slope += 1; 
			linear -= 1 * h[i];
			pq.push({h[i], 2});

			while (slope > 0){
				ll pnt, frq;
				tie(pnt, frq) = pq.top(), pq.pop();
				ll aux = min(slope, frq);
				slope -= aux;
				frq -= aux;
				linear += pnt * aux;
				if (frq > 0)
					pq.push({pnt, frq});
			}
		}

		cout<<linear<<'\n';
	}
}
