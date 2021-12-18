#include<bits/stdc++.h>

using namespace std;

long long val[30], a[30];
long long ans;
long long n, k;

int main(){
	long long t;
	cin >> t;

	while(t--){
		cin >> n >> k;
		ans = 0;
		for(long long i = 0; i< n; i++){
			cin >> a[i];
			if(i){
				long long aux = 1;
				for(long long j = a[i - 1]; j < a[i]; j++) aux *= 10;
				val[i] = aux - 1;
			}
		} 
		
		k++;
		long long p = 1;
		for(long long i = 1; i < n; i++){
			if(k >= val[i]){
				ans += val[i] * p;
				k -= val[i];
			}
			else{
				ans += k * p;
				k = 0;
			}

			p *= (val[i] + 1);
		}
		if(k > 0) ans += k * p;
		cout << ans << endl;
	}	
}