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

#define MAXN 410
#define MOD 1000000007


ll fastxp(ll n, ll e, ll p){
    ll ans = 1, pwr = n;
    while(e){
        if(e%2)  ans = ans * pwr % p;
        e /= 2;
        pwr = pwr * pwr % p;
    }
    return ans % p;
}

const int INF = 1e9+7; // it doesn't actually have to be infinity or a big number
int gauss_mod (vector < vector<int> > a, vector<int> & ans, int p) {
    int inv[p + 1];
    for(int i = 1; i < p; i++) inv[i] = fastxp(i, p - 2, p);

    for(auto & l: a) for(auto & y : l) y %= p;
    for(auto & y: ans) y %= p;

    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (a[sel][col] == 0)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                int c = a[i][col] * inv[a[row][col]] % p;
                for (int j=col; j<=m; ++j)
                    a[i][j] = (a[i][j] - a[row][j] * c % p + p) % p;

            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i){
        if (where[i] != -1)
            ans[i] = a[where[i]][m] * fastxp(a[where[i]][i], p - 2, p) % p;
        else
            ans[i] = INF;
    }
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum = (sum + ans[j] * a[i][j]) % p;
        if (sum != a[i][m])
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

map<pii, int> m;
pii mi[MAXN];
int n, a, r, t;
vector<int> ans;
int tot = 0;
vector<vector<int>> track;
	
void build(){
	cin >> n >> a >> r >> t;
	fr(j, t){
		int d, p;
		cin >> d >> p;
		ans.pb(d);

		vector<int> davez;
		fr(i, p){
			int x;
			cin >> x;
			davez.pb(x);
		}

		track.pb(davez);

		fr(i, p - 1){
			if(m[{min(davez[i], davez[i+1]), max(davez[i + 1], davez[i])}] == 0){
				mi[tot] = {min(davez[i], davez[i+1]), max(davez[i + 1], davez[i])};
				m[{min(davez[i], davez[i+1]), max(davez[i + 1], davez[i])}] = ++tot;
			}
		}
	}

	fr(j, t){
		vector<int> davez = track[j];
		track[j].assign(tot, 0);
		fr(i, davez.size() - 1){
			track[j][m[{min(davez[i], davez[i+1]), max(davez[i + 1], davez[i])}] - 1]++;
		}
		track[j].pb(ans[j]);
	}
}

vector<pii> adj[MAXN];

int dijkstra(){
	int dist[MAXN];
	mem(dist, -1);
	pq<pii> fila;
	fila.push({0, a});
	while(true){
		int davez = -1;
		while(fila.size()){
			pii p = fila.top();
			fila.pop();
			if(dist[p.s] == -1){
				dist[p.s] = -p.f;
				davez = p.s;
				break;
			}
		}
		if(davez == -1)break;
		for(auto x: adj[davez]){
			if(dist[x.f] == -1){
				fila.push({-dist[davez] - x.s, x.f});
			}
		}
	}
	return dist[r];
}

signed main(){
	fastio;
	build();

	if(gauss_mod(track, ans, 13) != 1) exit(1);

	fr(i, tot){
		adj[mi[i].f].pb({mi[i].s, ans[i]});
		adj[mi[i].s].pb({mi[i].f, ans[i]});
//		cout << mi[i].f << " " << mi[i].s << " " << ans[i] << endl;
	}

	cout << dijkstra() << endl;
}
