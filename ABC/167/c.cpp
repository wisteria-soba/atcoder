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
    ll n, m, x;
    cin >> n >> m >> x;
    vector<ll> c(n);
    ll ans = LLINF;
    vector<vector<ll>> a(n, vector<ll>(m));
    REP(i,n){
        cin >> c[i];
        REP(j,m){
            cin >> a[i][j];
        }
    }
    for(uint i = pow(2,n)-1; ; i--)
    {
        vector<ll> cnt(m, 0);
        ll cost = 0;
        REP(j, n)
        {
            if(i & (1 << j)){
                cost += c[j];
                REP(k, m)
                {
                    cnt[k] += a[j][k];
                }
            }
        }
        bool achieved = true;
        REP(j,m){
            if(cnt[j] < x){
                achieved = false;
                break;
            }
        }
        if(achieved){
            chmin(ans, cost);
        }
        if(i == 0)
        {
            break;
        }
    }
    if(ans == LLINF){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }

    return 0;
}