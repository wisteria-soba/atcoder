#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i = n;i >= 0;--i)
#define FOR(i,m,n) for(int i = m, i##_len=(n);i <i##_len; ++i)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int INF = 1e9;
const ll LLINF = 1e16;

int main(void)
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll lcm = c * d / gcd(c, d);
    ll ac = 0, ad = 0, acd = 0;

    ac = b / c - a / c + ((a % c == 0) ? 1 : 0);
    ad = b / d - a / d + ((a % d == 0) ? 1 : 0);
    acd = b/lcm - a/lcm + ((a % lcm == 0) ? 1 : 0);
    ll ans = b - a - (ac + ad - acd) + 1;

    cout << ans << endl;
    return 0;
}