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
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> c(10, vector<ll>(10));
    vector<vector<ll>> a(h, vector<ll>(w));
    REP(i, 10)
    {
        REP(j,10){
            cin >> c[i][j];
        }
    }

    REP(i,h){
        REP(j,w){
            cin >> a[i][j];
        }
    }

    

    REP(k,10){
        REP(i,10){
            REP(j,10){
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    ll sum = 0;
    REP(i,h){
        REP(j,w){
            if(a[i][j] != -1){
                sum += c[a[i][j]][1];
            }
        }
    }

    cout << sum << endl;

    return 0;
}