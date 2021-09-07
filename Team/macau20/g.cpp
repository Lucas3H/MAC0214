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

#define MAXN 400010
#define MOD 1000000007
#define INF 1000000000000000100

vector<int> v;
int pos_in_v[(1 << 8)];
bool winner[(1 << 8)];
int last[(1 << 8)];

void add(int x){
	if(pos_in_v[x] == -1){
		pos_in_v[x] = v.size();
		v.pb(x);
	}
	else{
		v.erase(v.begin() + pos_in_v[x], v.begin() + pos_in_v[x] + 1);
		v.pb(x);
		fr(i, v.size()) pos_in_v[v[i]] = i;
	}
	frm(i, v.size()){
		winner[v[i]] = false;
		fr(j, 8){
			if(pos_in_v[((1 << j) ^ v[i])] > i && !winner[((1 << j) ^ v[i])])
				winner[v[i]] = true;
		}
	}
}

bool comp(int x, int y){
	return last[x] < last[y];
}

vector<int> el;
int n, m;
signed main(){
	fastio;
	mem(pos_in_v, -1);
	cin >> n >> m;
	el.resize(n + 1);
	frr(i, n){
		cin >> el[i];
		last[el[i]] = i;
	}
	fr(i, (1 << 8)) if(last[i]) v.pb(i);
	sort(all(v), comp);
	fr(i, v.size()) pos_in_v[v[i]] = i;

    frm(i, v.size()){
		winner[v[i]] = false;
		fr(j, 8){
			if(pos_in_v[((1 << j) ^ v[i])] > i && !winner[((1 << j) ^ v[i])])
				winner[v[i]] = true;
		}
	}

	frr(i, m){
		int op, a;
		cin >> op >> a;
		if(op == 1) {
			add(a);
			last[a] = el.size();
			el.pb(a);
		}
		else{
			if(last[el[a]] == a){
				if(winner[el[a]]) cout << "Grammy\n";
				else cout << "Alice\n";
			}
			else cout << "Grammy\n";
		}
	}
}