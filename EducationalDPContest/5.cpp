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
        cin >> w[i];
        cin >> v[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(1e5+1, LLINF));
    REP(i,n){
        dp[i][0] = 0;
    }

    REP(i,n){
        REP(j,dp[i].size()){
            if(j - v[i] >= 0){
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
            else{
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    ll ans = 0;
    REPR(i, dp[n].size()-1)
    {
        if(dp[n][i] <= W){
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}