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
ll modinv(ll a, ll m) {ll b = m, u = 1, v = 0;while (b) {ll t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}
const int INF = 1e9;
const ll LLINF = 1e16;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll h,n;
    cin >> h >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    REP(i, n)
    {
        cin >> a[i] >> b[i];
    }
    vector<ll> bhtable( 2e4 + 1, LLINF);
    bhtable[0] = 0;
    REP(i, n)
    {
        for (int j = 0; j < h; j++)
        {
            chmin(bhtable[j + a[i]], bhtable[j] + b[i]);
        }
    }
    ll ans = LLINF;
    FOR(i, h, bhtable.size())
    {
        chmin(ans, bhtable[i]);
    }
    cout << ans << endl;
    return 0;
}
