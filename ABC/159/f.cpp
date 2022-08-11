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



const int MOD = 998244353;

// 入力
int n, A;
int a[3001];
// DPテーブル
int dp[3001][3001];
int rdp[3001][3001];

int main() {
    cin >> n >> A;
    for (int i = 0; i < n; ++i) cin >> a[i];

    memset(dp, 0, sizeof(dp));   // 一旦すべて 0 に
    dp[0][0] = 1;                // dp[0][0] だけ 1 に

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= A; ++j) {
            (dp[i+1][j] += dp[i][j]) %= MOD;
            if (j >= a[i]) (dp[i+1][j] += dp[i][j-a[i]]) %= MOD;
        }
    }

    vector<ll> ra(n);
    REP(i, n)
    {
        ra[i] = a[n - 1 - i];
    }

    memset(rdp, 0, sizeof(rdp));   // 一旦すべて 0 に
    rdp[0][0] = 1;                // dp[0][0] だけ 1 に

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= A; ++j) {
            (rdp[i+1][j] += rdp[i][j]) %= MOD;
            if (j >= ra[i]) (rdp[i+1][j] += rdp[i][j-ra[i]]) %= MOD;
        }
    }

    ll ans = 0;
    ll allc = dp[n][A];
    FOR(i,0,n+1){
        FOR(j,i,n+1){
            ans = (ans + (allc - dp[i][A] - rdp[n - j][A]))%MOD;
        }
    }

    cout << ans - allc * 2 << endl;
}
