#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = (int)n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;

#define mem(v, k) memset(v, k, sizeof(v));
#define db cout << "Debug" << endl;
#define all(x) begin(x), end(x)
#define dbg(x)  cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define myrand(a, b) uniform_int_distribution<int>(a, b)(rng)

#define mp make_pair
#define pq priority_queue

#define MAXN 600010
#define MOD 1000000007
#define INF 2000000000000000100

string s;
int xa, xb, ya, yb, n;
int ans[MAXN];

signed main(){
	fastio;
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'A') xa++;
		if(s[i] == 'B') xb++;
	}
	for(int i = n; i < 2 * n; i++) {
		if(s[i] == 'A') ya++;
		if(s[i] == 'B') yb++;
	}

	int v = 0;
	fr(i, n + 1){
		if(xa - i < 0) continue;
		if(yb - i < 0) continue;
		if(n + i - xa - yb - xb < 0) continue;
		if(n + i - xa - yb - ya < 0) continue;
		if(xb + xa + yb + ya - n - i < 0) continue;
		v = i;
		break;
	}

	//cout << xa << " " << xb << " " << ya << " " << yb << endl;

	int s1 = v, s2 = xa - v, s6 = yb - v;
	int s3 = xb + xa + yb + ya - n - v, s4 = n + v - xa - yb - ya, s5 = n + v - xa - yb - xb;

	//cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << s6 << endl;

	for(int i = 0; i < n; i++){
		if(s[i] == 'A'){
			if(s1){
				s1--;
				ans[i] = 1;
			}
			else{
				s2--;
				ans[i] = 2;
			}
		}
		else if(s[i] == 'B'){
			if(s3){
				s3--;
				ans[i] = 3;
			}
			else{
				s4--;
				ans[i] = 4;
			}
		}
		else{
			if(s5){
				s5--;
				ans[i] = 5;
			}
			else{
				s6--;
				ans[i] = 6;
			}
		}
	}

	s1 = v, s2 = xa - v, s6 = yb - v;
	s3 = xb + xa + yb + ya - n - v, s4 = n + v - xa - yb - ya, s5 = n + v - xa - yb - xb;
	for(int i = n; i < 2 * n; i++){
		if(s[i] == 'A'){
			if(s3){
				s3--;
				ans[i] = 3;
			}
			else{
				s5--;
				ans[i] = 5;
			}
		}
		else if(s[i] == 'B'){
			if(s1){
				s1--;
				ans[i] = 1;
			}
			else{
				s6--;
				ans[i] = 6;
			}
		}
		else{
			if(s2){
				s2--;
				ans[i] = 2;
			}
			else{
				s4--;
				ans[i] = 4;
			}
		}
	}

	s1 = v, s2 = xa - v, s6 = yb - v;
	s3 = xb + xa + yb + ya - n - v, s4 = n + v - xa - yb - ya, s5 = n + v - xa - yb - xb;
	for(int i = 2 * n; i < 3 * n; i++){
		if(s[i] == 'A'){
			if(s4){
				s4--;
				ans[i] = 4;
			}
			else{
				s6--;
				ans[i] = 6;
			}
		}
		else if(s[i] == 'B'){
			if(s2){
				s2--;
				ans[i] = 2;
			}
			else{
				s5--;
				ans[i] = 5;
			}
		}
		else{
			if(s1){
				s1--;
				ans[i] = 1;
			}
			else{
				s3--;
				ans[i] = 3;
			}
		}
	}
	fr(i, 3 * n) cout << ans[i];
	cout << endl;
}
