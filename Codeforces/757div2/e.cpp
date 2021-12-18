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

#define MAXN 100010
#define MOD 1000000007
#define INF 2000000000000000100

template<typename Item>
struct node {
	Item key;
	int p, sz;
	node * l, * r,  * par;
	
	void updateSize(){
		sz = 1;
		if(l != nullptr) sz += l->sz;
		if(r != nullptr) sz += r->sz;
	}

	node() : key({0, 0}), sz(0), l(nullptr), r(nullptr), par(nullptr) {} ;
	node(Item c, int pri, node * L, node * R, node * P) : \
		key(c), p(pri), sz(1), l(L), r(R), par(P) {};
	~node(){
		if(l != nullptr) delete l;
		if(r != nullptr) delete r;
	}
};
template<typename Item>
typedef node<Item> * pNode;

void merge (pNode & t, pNode l, pNode r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    t->updateSize();
}

void split (pNode t, pNode & l, pNode & r, int key) {
    if (!t)
        return void( l = r = 0 );
    if (key <= t->key)
        split (t->l, l, t->l, key),  r = t;
    else
        split (t->r, t->r, r, key),  l = t;
    t->updateSize();
}

void insert (pNode & t, pNode it) {
    if (t == nullptr) t = it;
    else if (it->prio > t->prio) 
    	split (t, it->key, it->l, it->r),  t = it;
    else 
    	insert (t->key <= it->key ? t->r : t->l, it);
}

void erase (pNode & t, int key) {
    if (t->key == key) {
        pNode th = t;
        merge (t, t->l, t->r);
        delete th;
    }
    else
        erase (key < t->key ? t->l : t->r, key);
}

pNode unite (pNode l, pNode r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    pNode lt, rt;
    split (r, l->key, lt, rt);
    l->l = unite(l->l, lt);
    l->r = unite(l->r, rt);
    return l;
}




// Search for the Node in the k-th position
pNode search(pNode a, int k){
	if(a == nullptr) return nullptr;
	if(a->l == nullptr){
		if(k == 1) return a;
		else return search(a->r, k - 1);
	}
	else{
		if(a->l->sz >= k) return search(a->l, k);
		else if(a->l->sz + 1 == k) return a;
		else return search(a->r, k - a->l->sz - 1);	
	}
}

// Get the position of node a
int order(pNode a){
	if(!a) return -1;
	int pos = 1;
	if(!a->l) pos += a->l->sz;

	while(a->par != nullptr){
		if(a == a->par->r){
			pos++;
			if(a->par->l != nullptr) pos += a->par->l->sz;
		}
		a = a->par;
	}
	return pos;
}