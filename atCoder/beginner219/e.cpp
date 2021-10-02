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

int casa;
int m[4][4];
int pr[4][4];
int vis = 0;

bool inside(int a, int b){
	return (0 <=a && a <= 3) && (0 <= b && b <= 3); 
}

void dfs(int a, int b){
	if(pr[a][b] || m[a][b] == 0) return;
	pr[a][b] = 1;
	vis++;
	if(inside(a, b-1)) dfs(a, b-1);
	if(inside(a, b+1)) dfs(a, b+1);
	if(inside(a-1, b)) dfs(a-1, b);
	if(inside(a+1, b)) dfs(a+1, b);
}

bool fora(int a, int b){
	if(pr[a][b] || m[a][b] == 1) return 0;
	pr[a][b] = 1;
	ll ret = 0;
	if(inside(a, b-1)) ret += fora(a, b-1);
	else ret += 1;
	if(inside(a, b+1)) ret += fora(a, b+1);
	else ret += 1;
	if(inside(a-1, b)) ret += fora(a-1, b);
	else ret += 1;
	if(inside(a+1, b)) ret += fora(a+1, b);
	else ret += 1;
	return ret > 0;
}


signed main(){
	fastio;
	int tot = 0;
	fr(i, 4) fr(j, 4){
		casa*=2;
		int x;
		cin >> x;
		casa += x;
	}	

	int ans = 0;
	fr(mask, (1 << 16)){	
		if((mask & casa) != casa) continue;

		int tot = 0;
		fr(i, 4) fr(j, 4) pr[i][j] = m[i][j] = 0;
		fr(i, 16) if((mask & (1 << i)) > 0) m[i/4][i%4] = 1, tot++;

		int ok = 1;
		fr(i, 3){
			fr(j, 3){
				if(m[i][j] == 1 && m[i+1][j+1] == 1 && m[i+1][j] == 0 && m[i][j+1] == 0) ok = 0;
				if(m[i][j] == 0 && m[i+1][j+1] == 0 && m[i+1][j] == 1 && m[i][j+1] == 1) ok = 0;
			}
		}

		fr(i, 4){
			fr(j, 4){
				if(m[i][j] == 0 && pr[i][j] == 0){
					if(!fora(i, j)) ok = 0;
				}
			}
		} 



		if(!ok) continue;


		fr(i, 4) fr(j, 4) pr[i][j] = 0;
		vis = 0;
		int deu = 0;
		fr(i, 4) {
			fr(j, 4) {
				if(m[i][j]){
					dfs(i, j);
					deu = 1;
					break;
				}
			}
			if(deu) break;
		}	

		if(vis == tot) {
			ans++;
			// int aux = mask;
			// fr(i, 4) {
			// 	fr(j, 4){
			// 		cout << aux%2 << " ";
			// 		aux /= 2;
			// 	}
			// 	cout << endl;
			// }
			// cout << endl;
			// aux = casa;	
			// fr(i, 4) {
			// 	fr(j, 4){
			// 		cout << aux%2 << " ";
			// 		aux /= 2;
			// 	}
			// 	cout << endl;
			// }
			// cout << endl;	
		}
	}
	cout<< ans << endl;
}
