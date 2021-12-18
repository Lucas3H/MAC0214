#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

#define MAXN 1000010
#define MOD 1000000007
#define INF 2000000000000000100


vector<pii> p[MAXN];

void sieve(){
	for(int i = 2; i < MAXN; i++){
		if(p[i].size() == 0){
			for(int j = i; j < MAXN; j += i) p[j].pb({i, 0});
		}
	}
}

map<int, int> sum, minimo;
map<int, deque<int>> last;

set<pii> cur; 
int a[MAXN];
char b[MAXN];

void insert_last(int prime, int pos, int val, deque<int> & l){
	if(pos < minimo[prime]){
		minimo[prime]--;
		l.push_front(val);
	}
	else if(pos >= minimo[prime] + (int)l.size()){
		l.push_back(val);
	}
	else l[pos - minimo[prime]] = val;
}

int get_last(int prime, int pos, deque<int> & l){
	if(pos >= minimo[prime] + (int)l.size()) {
		return 0;
	}
	if(pos < minimo[prime]) {
		return 0;
	}
	return l[pos - minimo[prime]];
}

void update_prime(int prime, int e, int pos){
	deque<int> * aux = (&last[prime]);
	cur.erase({get_last(prime, sum[prime] + 1, *aux), prime});
	int op = 1;
	if(b[pos] == '/') op = -1;
	insert_last(prime, sum[prime], pos, *aux);
	fr(i, e){
		sum[prime] += op;
		insert_last(prime, sum[prime], pos, *aux);
	}
	if(get_last(prime, sum[prime] + 1, *aux))
		cur.insert({get_last(prime, sum[prime] + 1, *aux), prime});
	//cout << prime << " " << sum[prime] << endl;
}

int n;

int process(int pos, int davez){
	int e = 0;
	if(p[davez].size()){
		if(p[davez][0].s == 0){
			int aux = davez;
	
			for(auto & x: p[davez]){
				x.s = 0;
				while(aux % x.f == 0){
					x.s++;
					aux /= x.f;
				}
			}
		}
	}
	
	for(auto & x: p[davez]){
		update_prime(x.f, x.s, pos);
	}

	//dbg(sum[2]);
	//if(cur.size())dbg((*(cur.begin())).f);
	if(cur.size() == 0) return n - pos + 1;
	else return (*(cur.begin())).f - pos;
}

signed main(){
	fastio;
	sieve();

	cin >> n;
	//frr(i, MAXN - 1) if(p[i].size() == 1) last[i][0] = n + 1;
	
	frr(i, n) cin >> a[i];
	frr(i, n) cin >> b[i];
	
	ll ans = 0;
	for(int i = n; i >= 1; i--){
		ans += (ll)process(i, a[i]);
		//dbg(ans);
	}
	cout << ans << endl;
}
