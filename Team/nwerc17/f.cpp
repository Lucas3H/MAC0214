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

const int N = 10000000;
int lp[N+1];
vector<int> pr;

void sieve(){
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; j++)
            lp[i * pr[j]] = pr[j];
    }
}

vector<pair<int, int>> decompose(int n){
    vector<pair<int, int>> ret;
    while(n > 1){
        pair<int, int> p = {lp[n], 0};
        while(lp[n] == p.first){
            p.second++;
            n /= p.first;
        }
        ret.push_back(p);
    }
    return ret;
}

vector<int> p[N];

int n;
int a[MAXN], l[MAXN], r[MAXN], ans[MAXN];
vector<pii> d[MAXN];

void build_l_r(int i){
	r[i] = n, l[i] = -1;
	for(auto x: d[i]){
		auto it = lower_bound(all(p[x.f]), i+1);
		if(it != p[x.f].end()){
			r[i] = min(r[i], *it);
		}

		auto it1 = lower_bound(all(p[x.f]), i);
		if(it1 != p[x.f].begin()){
			it1--;
			l[i] = max(l[i], *it1);
		}
	}
	l[i]++, r[i]--;
}

void read(){
	sieve();
	cin >> n;
	fr(i, n) {
		cin >> a[i];
		d[i] = decompose(a[i]);
		for(auto x: d[i]) p[x.f].pb(i);
	}
	fr(i, n) build_l_r(i);
}

void solve(int L, int R, int par){
	if(L > R)return;
	int il = L, ir = R, nxt = -1;
	while(il <= ir){
		if(l[il] <= L && R <= r[il]){
			nxt = il;
			break;
		}
		if(l[ir] <= L && R <= r[ir]){
			nxt = ir;
			break;
		}
		il++, ir--;
	}

	if(nxt == -1){
		cout << "impossible" << endl;
		exit (0);
	}

	//	cout << L << ' ' << R << " " << nxt << endl;
	ans[nxt] = par;
	solve(L, nxt - 1, nxt);
	solve(nxt + 1, R, nxt);
}

signed main(){
	fastio;
	read();
//fr(i, n) cout << l[i] << ' ' << r[i] << endl;

	solve(0, n-1, -1);
	fr(i, n) cout << ans[i] + 1 << ' ';
	cout << endl;
}
