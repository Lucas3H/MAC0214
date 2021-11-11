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
vector<array<int, 3>> v;

set<pii> pos, neu;

signed main(){
	fastio;
	cin >> n;
	fr(i, n){
		int x, y, z;
		char c;
		cin >> x >> y >> c;
		if(c == 'N') z = -1;
		else if(c == '-') z = 0;
		else z = 1;
		v.pb({2*x + y, -2*x + y, z});
	}
	sort(all(v));


	// Resolve os negativos
	frm(i, v.size()){
		int x = v[i][0], y = v[i][1], z = v[i][2];
		if(z == 0) neu.insert({y, x});
		else if(z == 1) pos.insert({y, x});
		else{
			auto it = neu.lower_bound({y, -MOD});
			while(it != neu.end()){
				neu.erase(it);
				it = neu.lower_bound({y, -MOD});
			}

			it = pos.lower_bound({y, -MOD});
			if(it != pos.end()){
				cout << "impossible" << endl;
				return 0;
			}
		}
	}
	v.clear();
	for(auto x: neu) v.pb({x.s, x.f, 0});
	for(auto x: pos) v.pb({x.s, x.f, 1});

	sort(all(v));
	pos.clear();
	neu.clear();

	int ans = 0;
	// Resolve só com negativos e positivos
	frm(i, v.size()){
		int x = v[i][0], y = v[i][1], z = v[i][2];
		//cout << x << " " << y << " " << z << endl;
		
		if(z == 0) neu.insert({y, x});
		else {
			auto it = pos.lower_bound({y, -MOD});
			if(it == pos.end()){
				it = neu.lower_bound({y, -MOD});
				if(it != neu.end()){
					int davez = (*(neu.rbegin())).f;
					pos.insert({davez, MOD});
				}
				else pos.insert({y, x});
				ans++;
			}
		}
	}

	cout << ans << endl;
}

