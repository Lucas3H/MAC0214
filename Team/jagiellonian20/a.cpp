#include <bits/stdc++.h>

using namespace std;

/// Magic constants, optimized to answer prime counting queries for n=10^12 but can be tweaked

const int MAXV = 20000010;

const int MAXP = 7;
const int MAXN = 50;
const int MAXM = 2 * 3 * 7 * 5 * 11 * 13 * 17; /// Product of the first MAXP primes

constexpr auto fast_div = [](const long long& a, const int& b) ->long long {return double(a) / b + 1e-9;};

vector<int> primes;
vector<int> lp(MAXV, 0);
int prod[MAXP], pi[MAXV], dp[MAXN][MAXM];

void sieve(){
	for (int i=2; i < MAXV; i++) {
	    pi[i] = pi[i - 1] + (lp[i] == 0);
	    if (lp[i] == 0) {
	        lp[i] = i;
	        primes.push_back (i);
	    }
	    for (int j=0; j<(int)primes.size() && primes[j] <= lp[i] && i*primes[j] < MAXV; ++j)
	        lp[i * primes[j]] = primes[j];
	}
}

void gen(){
    int i, j;
    assert(MAXN >= MAXP);

    sieve();
    for (prod[0] = primes[0], i = 1; i < MAXP; i++)
        prod[i] = prod[i - 1] * primes[i];

    for (i = 0; i < MAXM; i++) dp[0][i] = i;
    for (i = 1; i < MAXN; i++)
        for (j = 1; j < MAXM; j++)
            dp[i][j] = dp[i - 1][j] - dp[i - 1][fast_div(j, primes[i - 1])];
}

uint64_t phi(long long m, int n){
    if (!n) return m;
    if (n < MAXN && m < MAXM) return dp[n][m];
    if (n < MAXP) return dp[n][m % prod[n - 1]] + fast_div(m, prod[n - 1]) * dp[n][prod[n - 1]];

    long long p = primes[n - 1];
    if (m < MAXV && p * p >= m) return pi[m] - n + 1;
    if (p * p * p < m || m >= MAXV) return phi(m, n - 1) - phi(fast_div(m, p), n - 1);

    int lim = pi[(int)sqrt(0.5 + m)];
    uint64_t res = pi[m] - (lim + n - 2) * (lim - n + 1) / 2;
    for (int i = n; i < lim; i++)
        res += pi[fast_div(m, primes[i])];

    return res;
}

uint64_t lehmer(long long n){
    if (n < MAXV) return pi[n];

    int s = sqrt(0.5 + n), c = cbrt(0.5 + n);
    uint64_t res = phi(n, pi[c]) + pi[c] - 1;
    for (int i = pi[c]; i < pi[s]; i++)
        res -= lehmer(fast_div(n, primes[i])) - i;

    return res;
}

int main(){
    gen();
    long long t;
    cin >> t;

    while(t--){
    	long long n;
    	cin >> n;
    	uint64_t primes = lehmer(n) - lehmer(n/2);
    	//cout <<  lehmer(n) << " " << lehmer(n/2) << endl;
    	cout << n - (n - primes - 1)/2 << endl;
    }

    return 0;
}
