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
#define INF 2000000000000000100

int h[10];
vector<pair<char, int>> ans;

void solve(int a, int b){
	if(h[a]%2 != h[b]%2) ans.pb({'E', b}), h[b]++;
	while(h[a] < h[b]){
		ans.pb({'G', a});
		h[a]+=3, h[b]++;
	}
	while(h[a] > h[b]){
		ans.pb({'E', a});
		h[b]+=3, h[a]++;
	}
}

signed main(){
	fastio;
	fr(i, 10) cin >> h[i]; 
	fr(i, 5){
		solve(2*i, 2*i + 1);
	}
	int it = 10;
	while(it--){
		fr(i, 5) fr(j, i){
			while(h[2*j] < h[2*i]){
				ans.pb({'C', 2*j});
				h[2*j]+=2, h[2*j + 1]+=2;
			}
			while(h[2*j] > h[2*i]){
				ans.pb({'C', 2*i});
				h[2*i]+=2, h[2*i + 1]+=2;
			}
		}
	}
	cout << ans.size() << endl;
	for(auto x: ans) cout << x.f << " " << x.s << endl;
}
