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
#define INF 1000000000000000100

namespace FFT {
	using cd = complex<double>;

    #define PI acos(-1)
    void fft(vector<cd> &a, int logN, int sign) {
        for (int i = 0; i < a.size(); i++) {
            int mask = 0;
            for (int j = 0; j < logN; j++) {
                if (i >> j & 1) mask |= (1 << logN - j - 1);
            }
            if (i < mask) swap(a[i], a[mask]);
        }
 
        for (int k = 1; k < a.size(); k <<= 1) {
            cd wDelta = polar(1.0, PI * sign / k);
            cd w(1, 0);
            for (int i = 0; i < k; i++, w *= wDelta) {
                for (int j = i; j < a.size(); j += k * 2) {
                    cd foo = a[j];
                    cd bar = w * a[j + k];
                    a[j] = foo + bar;
                    a[j + k] = foo - bar;
                }
            }
        }
    }
 
    vector<int> multiply(vector<int> &a, vector<int> &b) {
        int sz = a.size() + b.size() - 1;
        int logN = 0;
        while ((1 << logN) < sz) logN++;

        vector<cd> aa(1 << logN, 0), bb(1 << logN, 0);

        for (int i = 0; i < a.size(); i++) aa[i] = a[i];
        for (int i = 0; i < b.size(); i++) bb[i] = b[i];

        fft(aa, logN, 1);
        fft(bb, logN, 1);

        for (int i = 0; i < aa.size(); i++) {
            aa[i] *= bb[i];
        }

        fft(aa, logN, -1);
        vector<int> res(sz);
        for (int i = 0; i < sz; i++) {
            res[i] = (int)(aa[i].real() / (1 << logN) + 0.5);
        }
        return res;
    }
};

int n, x, y;
vector<int> a, b;

int solve(int l){
	int ans = -1;
	for(int i = 1; i * i <= l; i++){
		if(l%i == 0){
			int d = i - y;
			if(d > 0 && a[x + d]) ans = max(ans, i);
			d = l/i - y;
			if(d > 0 && x + d < a.size() && a[x + d]) ans = max(ans, l/i);
		}
	}
	return ans;
}


signed main(){
	fastio;
	a.resize(200001, 0), b.resize(200001, 0);
	cin >> n >> x >> y;
	fr(i, n + 1){
		int m;
		cin >> m;
		a[m] = 1;
		b[x - m] = 1;
	}

	a = FFT::multiply(a, b);
	// fr(i, 30) cout << a[i] << " ";
	// cout << endl;
	// db;
	int q;
	cin >> q;
	while(q--){
		int m;
		cin >> m;
		int aux = solve(m/2);
		if(aux == -1) cout << -1 << " ";
		else cout << 2*aux << " ";
	}
	cout << endl;
}
