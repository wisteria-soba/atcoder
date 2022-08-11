#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(ll i = n;i >= 0;--i)
#define FOR(i,m,n) for(ll i = m, i##_len=(n);i <i##_len; ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const int INF = 1e9;
const ll LLINF = 1e16;
 
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


int main(void)
{
    unsigned long long h,w;
    cin >> h >> w;

    if(min(h,w) == 1){
        cout << 1 << endl;
    }
    else if(h % 2 == 0){
        cout << (h / 2) * w << endl;
    }
    else if(w % 2 == 0){
        
        cout << (w / 2) * h << endl;
    }
    else {
        unsigned long long mw = w / 2 + 1;
        unsigned long long lw = w/2;
        cout << (mw + lw) * (h / 2) + mw << endl;
    }

    return 0;
}