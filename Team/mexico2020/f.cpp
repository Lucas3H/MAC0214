#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int n, m, ub, ans;

int mapa[30];

vi sentido;
vii cantos;

bool testa(int id, int pc){
	int x = cantos[id].fst;
	int y = cantos[id].snd;

	if (sentido[id] == 1)
		x -= pc - 1;

	if (y + pc > m) return false; // não cabe
	if (x + pc > n) return false;
	if (x < 0) return false;

	int msk = 0;
	fr(i, pc)
		msk |= 1<<i; //000011111

	msk = msk<<y;	

	for (int i = x; i < x + pc; i++)
		if (mapa[i] & msk) return false;

	return true;
}

pii altera(int id, int pc){
	int x = cantos[id].fst;
	int y = cantos[id].snd;

	if (sentido[id] == 1)
		x -= pc - 1;

	int msk = 0;
	fr(i, pc)
		msk |= 1<<i; //000011111

	msk = msk<<y;	

	for (int i = x; i < x + pc; i++)
		mapa[i] ^= msk;

	return {x, y};
}


void backtrack(int mask){
	int p = 2;
	while ((p <= ub) and (mask & (1<<p)))
		p++;

	ans = max(ans, p - 1);

	if (ans == ub){
		cout<< "dp[" <<n << "][" << m << "] = " << ans<<";" <<endl;
		if(m != n) cout<< "dp[" <<m << "][" << n << "] = " << ans<<";" <<endl;
		exit(0);
	}

	for (int i = 2; i <= ub; i++)
		if (!(mask & (1<<i))){
			for (int j = 0; j < cantos.size(); j++)
				if (testa(j, i)){
				
					int x, y;
					tie(x, y) = altera(j, i);
				
					cantos.pb({x, y + i});
					sentido.pb(0);
					
					cantos.pb({x + i - 1, y + i});
					sentido.pb(1);
					
					cantos.pb({x + i, y});
					sentido.pb(0);

					backtrack(mask | (1<<i));

					cantos.pop_back();cantos.pop_back();cantos.pop_back();
					sentido.pop_back();sentido.pop_back();sentido.pop_back();
				
					altera(j, i);
				}
		}
}



signed main(int argc, char ** argv){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	n = atoi(argv[1]);
	m = atoi(argv[2]);

	if (n == 30 and m == 30){

		cout<< "dp[" <<n << "][" << m << "] = " << 13<<";" <<endl;
		return 0;
	}

	ub = 1;

	int sum = 1;
	while ((ub + 1) * (ub + 1) + sum <= n * m){
		ub++; 
		sum += ub * ub ;
	}

	// dbg(ub);
	cantos.pb({0, 0});
	sentido.pb(0);

	if (ub >= 11)
	 	backtrack(7<<1);
	else if(ub >= 10)
		backtrack(3<<1);
	else
		backtrack(2);

	cout<< "dp[" <<n << "][" << m << "] = " << ans<< ";" << endl;
	if(m != n) cout<< "dp[" <<m << "][" << n << "] = " << ans<<";" << endl;
}	