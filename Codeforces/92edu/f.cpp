#include<bits/stdc++.h>
using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = (int)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 200010
#define MOD 1000000007
#define INF 2000000000000000100

struct SEG{
	int nd[4 * MAXN], lz[4 * MAXN];
	SEG() {
		fr(i, 4 * MAXN) nd[i] = lz[i] = 0;
	}
	void push(int i, int l, int r){
		if(lz[i] != 0){
			nd[i] += lz[i];
			if(l < r) lz[2 * i] += lz[i], lz[2 * i + 1] += lz[i];
			lz[i] = 0;
		}
	}

	void update(int i, int l, int r, int ql, int qr, int val){
		push(i, l, r);
		if(ql <= l && r <= qr){
			lz[i] += val;
			push(i, l, r);
		}
		else if(ql > r || l > qr) return;
		else{
			int m = (l + r)/2;
			update(2 * i, l, m, ql, qr, val), update(2 * i + 1, m + 1, r, ql, qr, val);
			nd[i] = max(nd[2 * i], nd[2 * i + 1]);
		}
	}

	int query(int i, int l, int r, int ql, int qr){
		push(i, l, r);
		if(ql <= l && r <= qr) return nd[i];
		else if(ql > r || l > qr) return 0;
		else{
			int m = (l + r)/2;
			return max(query(2 * i, l, m, ql, qr), query(2 * i + 1, m + 1, r, ql, qr));
		}
	}
};

SEG s[2];

int bb(const vector<int> & v, int val){
	int l = -1, r = (int)v.size(), m;
	while(l < r - 1){
		m = (l + r)/2;
		if(v[m] < val) l = m;
		else r = m;
	}
	return l;
}

vector<int> v[2];
int n;

vector<array<int, 3>> intervals;


signed main(){
	fastio;
	cin >> n;
	intervals.resize(n);
	fr(i, n) {
		cin >> intervals[i][1] >> intervals[i][0] >> intervals[i][2];
		intervals[i][1] *= -1;
		intervals[i][2]--;
	}
	sort(all(intervals));

	int cur = 0;

	fr(i, n){
		int l = -intervals[i][1], r = intervals[i][0], c = intervals[i][2];
		int ans = 1;
		int davez = bb(v[1 - c], l);
		if(davez > -1) ans += max(s[1 - c].query(1, 0, n - 1, 0, davez), (int)v[c].size());
		else ans += (int)v[c].size();
		
		s[c].update(1, 0, n - 1, (int)v[c].size(), (int)v[c].size(), ans);
		cur = max(cur, ans);
		v[c].pb(r);
		
		//cout << l << " " << r << " " << c << " " << ans << endl;
		if(davez > -1) s[1 - c].update(1, 0, n - 1, 0, davez, 1);
	}

	cout << cur << endl;
}
