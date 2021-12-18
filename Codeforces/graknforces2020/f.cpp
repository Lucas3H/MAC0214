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

int n;
deque<int> backup;
deque<int> resto;

deque<pii> ans;
void build_pwr2(deque<int> v){
	int tam = v.size();
	if(tam == 1) return;
	deque<int> l, r;
	while(v.size() > tam/2) {
		r.push_front(v.back());
		v.pop_back();
	}
	build_pwr2(v);
	build_pwr2(r);
	fr(i, tam/2) ans.pb({v[i], r[i]});
}	

signed main(){
	fastio;

	cin>> n;
	vector<deque<int>> v;
	int tot = 0;
	while(tot < n){
		int pwr = 1;
		while(tot + pwr * 2 < n) pwr *= 2;
		deque<int> davez;
		for(int i = tot; i < tot + pwr; i++) davez.pb(i);
		v.pb(davez);
		tot += pwr;
		build_pwr2(davez);
		// for(auto x: davez) cout << x << " ";
		// cout << endl;
	}
	while(v.size() > 2){
		int t = v.size();
		int tam = v[t - 1].size();
		if(v[t - 1].size() == v[t - 2].size()){
			fr(i, tam) ans.pb({v[t - 1][i], v[t - 2][i]});
			fr(i, tam) v[t - 2].pb(v[t - 1][i]);
			v.pop_back();
		}
		else{
			fr(i, tam){ 
				ans.pb({v[0][i], v[t - 1][i]});
				v[t - 1].pb(v[0][i]);
			}
			fr(i, tam) v[0].pop_front();
		}
	}
	cout << ans.size() << endl;
	for(auto x: ans) cout << x.f + 1 << " " << x.s + 1 <<endl;
}