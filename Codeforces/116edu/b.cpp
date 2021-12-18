#include<bits/stdc++.h>

using namespace std;

long long n, k;

int main(){
	int t;
	cin >> t;


	while(t--){	
		cin >> n >> k;

		long long ok = 1, ans = 0;
		while(ok < n && ok < k){
			ok *= 2;
			ans++;
		}
		if(ok >= n){
			cout << ans << endl;
			continue;
		}

		n -= ok;
		ans += (n - 1)/k + 1;
		cout << ans << endl;
	}
}