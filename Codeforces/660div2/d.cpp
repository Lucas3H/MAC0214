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

ll n;
ll a[MAXN], b[MAXN];
ll in[MAXN];
vector<ll> out[MAXN];

signed main(){
	fastio;
	cin >> n;

	frr(i, n) cin >> a[i];
	frr(i, n) {
		cin >> b[i];
		if(b[i] == -1) continue;
		in[b[i]]++;
		out[i].pb(b[i]);
	}

	vector<ll> ord, guarda;
	ll ans = 0;
	queue<ll> fila;
	frr(i, n) if(in[i] == 0) fila.push(i);

	while(fila.size()){
		ll davez = fila.front();
		fila.pop();
		
		if(a[davez] >= 0){
			ans += a[davez];	
			if(b[davez] != -1) a[b[davez]] += a[davez];
			ord.pb(davez);
		}
		else guarda.pb(davez);
		
		for(auto x: out[davez]){
			in[x]--;
			if(in[x] == 0) fila.push(x);
		}
	}
	frm(i, (int)guarda.size()){
		ans += a[guarda[i]];
		ord.pb(guarda[i]);
	}

	cout << ans << endl;
	for(auto x: ord) cout << x <<" ";
	cout << endl;

}
