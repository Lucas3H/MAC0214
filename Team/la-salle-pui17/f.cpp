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

set<int> nxt, prv;
int sum[MAXN];
char cor[MAXN];

/*
	{sum, ind};
*/
set<pii> m;
int r, b, n, c;

vector<vector<int>> ans;

void update(){
	auto Iterator = m.lower_bound({r - b, -1});
	int pos = (*Iterator).second;
	vector<int> davez;

	int as = 0;

	fr(i, c){
		auto x = prv.lower_bound(-pos);
		int aux = -(*x);
		
		m.erase({sum[aux], aux});
		prv.erase(-aux);
		nxt.erase(aux);
		davez.pb(aux);

		if(cor[aux] == 'R') as++;
		else as--;
	}

	deque<int> v;
	int it = -pos + 1;

	fr(i, c - 1){
		auto x = prv.lower_bound(it);
		if(x == prv.end()) break;
		int aux = -(*x);
		it = -aux + 1;
		if(cor[aux] == 'R') v.push_front(1);
		else v.push_front(-1);
	}

	it = pos + 1;
	while(v.size() < c - 1){
		auto x = nxt.lower_bound(it);
		if(x == nxt.end()) break;
		int aux = (*x);
		it = aux + 1;
		m.erase({sum[aux], aux});

		if(cor[aux] == 'R') v.push_back(1);
		else v.push_back(-1);
	}

	int s = 0;
	for(auto x: v) s += x;

	fr(i, c - 1){
		auto x = nxt.lower_bound(it);
		if(x == nxt.end()) break;
		int aux = (*x);
		it = aux + 1;

		if(cor[aux] == 'R') s++;
		else s--;

		m.erase({sum[aux], aux});
		sum[aux] = s;
		m.insert({sum[aux], aux});

		s -= v[i];
	}

	sort(all(davez));
	ans.pb(davez);
}

signed main(){
	fastio;
	cin >> n >> r >> b;
	c = r + b;
	
	int R = 0, B = 0;
	for(int i = 1; i <= n; i++){
		cin >> cor[i];
		if(cor[i] == 'R') sum[i] = 1, R++;
		else sum[i] = -1, B++;
		sum[i] += sum[i - 1];
	}

	if(n%(r + b) != 0 || R%r != 0){
		cout << "NO" << endl;
		return 0;
	}

	if(n / (r + b) != R / r){
		cout << "NO" << endl;
		return 0;
	}

	frr(i, n) {
		prv.insert(-i);
		nxt.insert(i);
	}

	for(int i = n; i >= c; i--){
		sum[i] = sum[i] - sum[i - c];
		m.insert({sum[i], i});
	}	

	fr(i, n / (r + b)) {
		update();
	}

	cout << "YES" << endl;
	cout << ans.size() << endl;

	frm(i, (int)ans.size()){
		vector<int> v = ans[i];
		for(auto x: v) cout << x << " ";
		cout << endl; 
	}
}
