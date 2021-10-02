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

struct SuffixArray {
    string s;
    int length = 1, n;
    vector<int> ret, id, lcp, nx;
    SuffixArray(string ss) {
        s = ss, n = s.size();
        id.resize(n), nx.resize(n), ret.resize(n), lcp.resize(n);
        if(n == 1) return;
        for (int i = 0; i < n; i++) ret[i] = i;
        for (int i = 0; i < n; i++) id[i] = s[i];

        while (length < n) {
            auto comp = [&](int a, int b) {
                if (id[a] != id[b]) return id[a] < id[b];
                int l = -1, r = -1;
                if (a + length < n)l = id[a + length];
                if (b + length < n)r = id[b + length];
                return l < r;
            };
            sort(ret.begin(), ret.end(), comp);
            nx[ret[0]] = 0;
            for (int i = 1; i < n; i++) {
                nx[ret[i]] = nx[ret[i - 1]] + comp(ret[i - 1], ret[i]);
            }
            id = nx;
            length <<= 1;
        }
        for (int i = 0; i < n; i++) {
            int nx = id[i], idx = i;
            if (nx + 1 == n) continue;
            nx = ret[nx + 1];

            if (i && lcp[id[i - 1]]) {
                lcp[id[i]] = lcp[id[i - 1]] - 1;
                nx += lcp[id[i]], idx += lcp[id[i]];
            }
            while (nx < n && i < n && s[idx] == s[nx]) 
                lcp[id[i]]++, nx++, idx++;
        }
    }
};

int dp[MAXN];

signed main(){
	fastio;
	int t;
	cin >> t;

	while(t--){
		string s;
		int n;
		cin >> n >> s;
		SuffixArray sa(s);
		fr(i, n) {
			int ini = sa.id[i] - 1;
			dp[i] = n - i;
			int minimo = MOD;
			
			while(ini >= 0){
				minimo = min(minimo, sa.lcp[ini]);
				if(sa.ret[ini] <= i)
					dp[i] = max(dp[i], dp[sa.ret[ini]] + n - i - minimo);
				ini--;
			} 
		}
		// fr(i, n) cout << dp[i] << " ";
		// cout << endl;
		int ans = 0;
		fr(i, n) ans = max(ans, dp[i]);
		cout << ans << endl;
		// fr(i, n) cout << sa.ret[i] << " ";
		// cout << endl;
		// fr(i, n) cout << sa.lcp[i] << " ";
		// cout << endl;
		// fr(i, n) cout << sa.nx[i] << " ";
		// cout << endl;
		// fr(i, n) cout << sa.id[i] << " ";
		// cout << endl;
	}
}
