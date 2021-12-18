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
#define INF 2000000000000000100

vector<ll> fr[MAXN];
ll n;
pair<ll, vector<ll>> tenta(ll tam){
	pq<pair<ll, ll>> m;
	frr(i, MAXN - 1){
		ll sum = 0;
		for(auto x: fr[i]) sum += min(x, tam);
		m.push({sum, i});

	}
	vector<ll> ans;
	ll val = 0;
	fr(i, tam){
		val += m.top().f, ans.pb(m.top().s);
		m.pop();
	}
	return {val, ans};
}

signed main(){
	fastio;
	cin >> n;
	fr(i, n){
		ll m, k;
		cin >> m >> k;
		fr[m].pb(k);
	}

	pii ans = {0, 1};
	vector<ll> msg;
	frr(i, 20){
		pair<ll, vector<ll>> p = tenta(i);
		if(p.f * ans.s > ans.f * i){
			ans = {p.f, i};
			msg = p.s;
		}
	}
	//cout <<ans.f << " " <<ans.s << endl;
	cout << msg.size() << endl;
	for(auto x: msg) cout << x << " ";
	cout << endl;
}
