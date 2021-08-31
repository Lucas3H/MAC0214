#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EL printf("\n")
#define pb push_back
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)

const int base = 10;
typedef deque<int> BigInt;

void Set(BigInt &a) {
    while (a.size() > 1 && a.front() == 0) a.pop_front();
}

void Print(BigInt a) {
    Set(a);
    printf("%d", (a.size() == 0) ? 0 : a.back());
    FORD(i,(int)a.size()-2,0) printf("%d", a[i]); EL;
}

BigInt Integer(string s) {
    BigInt ans;
    for(auto x: s) ans.pb(x - '0');
    Set(ans);
    return ans;
}

BigInt Integer(ll x) {
    string s = "";
    while (x > 0) s = char(x%10+'0') + s, x /= 10;
    return Integer(s);
}

BigInt Integer(int x) {
    return Integer((ll) x);
}

bool operator < (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    if (a.size() != b.size()) return (a.size() < b.size());
    FOR(i,(int)a.size()-1,0)
        if (a[i] != b[i]) return (a[i] < b[i]);
    return false;
}

bool operator > (BigInt a, BigInt b) {
    return (b < a);
}

bool operator == (BigInt a, BigInt b) {
    return (!(a < b) && !(b < a));
}

bool operator <= (BigInt a, BigInt b) {
    return (a < b || a == b);
}

bool operator >= (BigInt a, BigInt b) {
    return (b < a || b == a);
}

bool operator < (BigInt a, int b) {
    return (a < Integer(b));
}

bool operator > (BigInt a, int b) {
    return (a > Integer(b));
}

bool operator == (BigInt a, int b) {
    return (a == Integer(b));
}

bool operator >= (BigInt a, int b) {
    return (a >= Integer(b));
}

bool operator <= (BigInt a, int b) {
    return (a <= Integer(b));
}

BigInt operator + (BigInt a, BigInt b) {
    Set(a);
    Set(b);
    while(b.size() < a.size()) b.push_front(0);
    BigInt ans;
    int carry = 0;
    FOR(i,0,max(a.size(), b.size())-1) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        ans.pb(carry%base);
        carry /= base;
    }
    if (carry) ans.pb(carry);
    Set(ans);
    return ans;
}

BigInt operator + (BigInt a, int b) {
    return a + Integer(b);
}

BigInt operator - (BigInt a, BigInt b) {
    while(b.size() < a.size()) b.push_front(0);
    BigInt ans;
    int carry = 0;
    FORD(i,(int)a.size()-1,0) {
        carry += a[i] - (i < b.size() ? b[i] : 0);
        if (carry < 0) ans.push_front(carry+base), carry = -1;
        else ans.push_front(carry), carry = 0;
    }
    Set(ans);
    return ans;
}

BigInt operator - (BigInt a, int b) {
    return a - Integer(b);
}


BigInt inverse(BigInt v){
    BigInt inv;
    for(int i = (int)v.size() - 1; i >= 0; i--)
        inv.pb(v[i]);
    return inv;
}

int sum_digits(BigInt v){
    return (int)v.size();
}

vector<BigInt> ans;

void func(BigInt n, int digitos){
    if(digitos == 0) return;
    else if(digitos == 1){
        ans.pb(Integer(n[0]));
        return;
    }
    else if(digitos == 2){
        int f = n[0], N = n[0]*10 + n[1];
        if(N >= 11*f){
            ans.pb(Integer(11*f));
            ans.pb((n - 11*f));
        }
        else{
            if(f == 1){
                ans.pb(Integer(9));
                ans.pb(Integer(1));
            }
            else{
                ans.pb(Integer((f-1)*11));
                ans.pb(Integer(1));
                ans.pb((n - (f-1)*11 - 1));
            }
        }
        return;
    }
    BigInt left = n, right;
    for(int i = 0; i < digitos/2; i++) 
        right.push_front(left.back()), left.pop_back();
    int guarda;
    if(digitos%2 == 1) guarda = (left.back()), left.pop_back();
    BigInt left_inv = inverse(left);
    if(left_inv <= right){
        ans.pb(n - (right - left_inv));
        func(right - left_inv, digitos/2);
    }
    else{
        left.pb(guarda);
        left = left - 1;
        left_inv = inverse(left);
        if(digitos%2 == 1){
            guarda = left.back();
            left.pop_back();
            left_inv = inverse(left);
            left.pb(guarda);
        }
        for(auto x: left_inv) left.pb(x);
        ans.pb(left);
        n = n - left;
        func(n, sum_digits(n));
    }
}

string s;

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> s;
        BigInt n = Integer(s);
        ans.clear();
        func(n, (int)n.size());
        cout << ans.size() << endl;
        for(auto x: ans) {
            Print(x);
        }
    }
    return 0;
}