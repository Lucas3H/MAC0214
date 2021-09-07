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

struct FFT{
	using cd = complex<long double>;
	const long double PI = acos(-1);

	void fft(deque<cd> & a, bool invert) {
	    ll n = a.size();
	    if (n == 1)
	        return;

	    deque<cd> a0(n / 2), a1(n / 2);
	    for (ll i = 0; 2 * i < n; i++) {
	        a0[i] = a[2*i];
	        a1[i] = a[2*i+1];
	    }
	    fft(a0, invert);
	    fft(a1, invert);

	    long double ang = 2 * PI / n * (invert ? -1 : 1);
	    cd w(1), wn(cos(ang), sin(ang));
	    for (ll i = 0; 2 * i < n; i++) {
	        a[i] = a0[i] + w * a1[i];
	        a[i + n/2] = a0[i] - w * a1[i];
	        if (invert) {
	            a[i] /= 2;
	            a[i + n/2] /= 2;
	        }
	        w *= wn;
	    }
	}

	deque<ll> multiply(deque<ll> const a, deque<ll> const b) {
	    deque<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	    ll n = 1;
	    while (n < a.size() + b.size()) 
	        n <<= 1;
	    fa.resize(n);
	    fb.resize(n);

	    fft(fa, false);
	    fft(fb, false);
	    for (ll i = 0; i < n; i++)
	        fa[i] *= fb[i];
	    fft(fa, true);

	    deque<ll> result(n);
	    for (ll i = 0; i < n; i++)
	        result[i] = round(fa[i].real());
	    return result;
	}
};


signed main(){
	fastio;
	deque<ll> a, b;
	a.pb((ll)1);
	a.pb((ll)957256277);
	b.pb((ll)1);
	b.pb((ll)31169670);
	b.pb((ll)644145137);

	
	for(auto x: a) cout << (ll)x << " ";
	cout << endl;

	for(auto x: b) cout << (ll)x << " ";
	cout << endl;

	FFT f;
	a = f.multiply(a, b);
	for(auto x: a) cout << (ll)x % MOD << " ";
	cout << endl;
}