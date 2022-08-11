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
    ll n, W;
    cin >> n >> W;
    vector<ll> w(n);
    vector<ll> v(n);

    REP(i,n){
        cin >> w[i] >> v[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0));

    FOR(i,0,n){
        FOR(j,0,W+1){
            if(j - w[i] >= 0){
                dp[i+1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            }
            else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    cout << dp[n][W] << endl;

    return 0;
}