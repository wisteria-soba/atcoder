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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int answ = 0;
    int anss = 0;
    for (int aw = 0; aw <= f; aw += 100 * a)
    {
        for (int bw = 0; aw + bw <= f; bw += 100*b){
            for (int cw = 0; cw <= (aw + bw)/100 * e;cw += c){
                for (int dw = 0;cw + dw <= (aw + bw)/100 * e;dw += d){
                    if(cw + dw + aw + bw == 0 || cw + dw + aw + bw > f){
                        continue;
                    }
                    if((cw + dw) * (answ + anss) >= (anss) * (cw + dw + aw + bw)){
                        answ = aw + bw;
                        anss = cw + dw;
                    }
                }
            }
        }
    }

    cout << answ + anss << " " << anss << endl;

    return 0;
}