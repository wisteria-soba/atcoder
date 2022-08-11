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
    ll rc = 0;
    string s;
    cin >> s;
    string ma = "";
    string se = "";
    ll q;
    cin >> q;
    REP(i,q){
        ll t;
        cin >> t;
        if(t == 1){
            rc++;
        }
        else{
            ll f;
            string c;
            cin >> f >> c;
            if(f == 1){
                if(rc % 2 == 0){
                    se += c;
                }
                else{
                    ma += c;
                }
            }
            else{
                if(rc % 2 == 0){
                    ma += c;
                }
                else{
                    se += c;
                }
            }
        }
    }

    reverse(all(se));
    s = se + s + ma;

    if(rc % 2 == 1){
        reverse(all(s));
    }

    cout << s << endl;

    return 0;
}