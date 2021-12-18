#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define ll long long

ll n, x;
ll ans = 0;
ll bin[501][501];
ll pwr[501][501];
ll dp[501][501];

int main(){
	bin[0][0] = 1;
	for(int i = 1; i < 501; i++){
		bin[i][0] = 1;
		for(int j = 1; j <= i; j++) bin[i][j] = (bin[i - 1][j] + bin[i - 1][j - 1]) % MOD;
	}

	pwr[0][0] = 1;
	for(int i = 1; i < 501; i++){
		pwr[i][0] = 1;
		for(int j = 1; j < 501; j++) pwr[i][j] = pwr[i][j - 1] * i % MOD;
	}

	cin >> n >> x;
	for(int j = 0; j <= x; j++) dp[0][j] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= x; j++){
			if(j <= i - 1) {
				dp[i][j] = pwr[j][i];
				continue;
			}

			for(int k = 0; k <= i; k++){
				dp[i][j] = (dp[i][j] + bin[i][k] * pwr[i - 1][k] % MOD * dp[i - k][j - (i - 1)]) % MOD;
			}
		}
	}
	cout << dp[n][x] << endl;
}