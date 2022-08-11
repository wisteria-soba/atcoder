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
    ll n, k;
    ll mod = 1e9 + 7;
    cin >> n >> k;
    vector<vector<ll>> v(n, vector<ll>(k));
    REP(i,n){
        REP(j,k){
            cin >> v[i][j];
        }
    }
    vector<vector<ll>> cnt_table(n, vector<ll>(k,0));
    REP(i,k){
        cnt_table[n - 1][i] = k - i;
    }
    REPR(i,n-2){
        ll nmi = lower_bound(all(v[i + 1]), v[i][k-1]) - v[i + 1].begin();
        if (nmi < k){
            cnt_table[i][k-1] = cnt_table[i + 1][nmi];
        }
        else{
            cnt_table[i][k-1] = 0;
        }
        for (ll j = k-2; j >=  0; j--)
        {
            ll nmi = lower_bound(all(v[i + 1]), v[i][j]) - v[i + 1].begin();
            if (nmi < k){
                cnt_table[i][j] = (cnt_table[i][j + 1] + cnt_table[i + 1][nmi])%mod;
            }
            else{
                cnt_table[i][j] = 0;
            }
        }
    }
    cout << cnt_table[0][0] << endl;
    return 0;
}