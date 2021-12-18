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

ll dp[31][31][31][401];
string s;
ll tot, n;
char a, b, c;

signed main(){
	fastio;
	cin >> s >> tot;

	n = s.size();

	dp[0][0][0][0] = 1;

	ll ans = 0;
	fr(mov, min(tot + 1, (ll)301)){
		fr(lastA, n + 1){
			fr(lastB, n + 1){
				fr(lastC, n + 1){
					int davez = max(lastA, max(lastB, lastC)) + 1;
					if(davez == n + 1) {
						//cout << lastA << " " << lastB << " " << lastC << " " << mov << ": " << dp[lastA][lastB][lastC][mov] << endl;
						ans += dp[lastA][lastB][lastC][mov];
						continue; 
					}

					int curA, curB, curC;
					if(s[davez - 1] == 'K'){
						curB = lastB, curC = lastC;
						for(int j = davez; j >= lastA + 1; j--){
							if(j == lastB) curB++;
							if(j == lastC) curC++;
							dp[j][curB][curC][mov + davez - j] += dp[lastA][lastB][lastC][mov];
						}
					}
					else if(s[davez - 1] == 'E'){
						curA = lastA, curC = lastC;
						for(int j = davez; j >= lastB + 1; j--){
							if(j == lastA) curA++;
							if(j == lastC) curC++;
							dp[curA][j][curC][mov + davez - j] += dp[lastA][lastB][lastC][mov];
						}
					}
					else{
						curA = lastA, curB = lastB;
						for(int j = davez; j >= lastC + 1; j--){
							if(j == lastA) curA++;
							if(j == lastB) curB++;
							dp[curA][curB][j][mov + davez - j] += dp[lastA][lastB][lastC][mov];
						}
					}
				}
			}
		}
	}
	cout << ans << endl;

}
