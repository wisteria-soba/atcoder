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

const int MAXN = 17;
int n;
int d[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

int rec(int S, int v)
{
    if (dp[S][v] >= 0)
        return dp[S][v];
    if (S == (1 << n) - 1 && v == 0)
        return dp[S][v] = 0;
    int tmp = INF;
    REP(u, n)
    if (!(S >> u & 1)) tmp = min(tmp, rec(S | 1 << u, u) + d[v][u]);
    return dp[S][v] = tmp;
}

int main()
{
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> z(n);
    REP(i,n){
        cin >> x[i] >> y[i] >> z[i];
    }
    REP(i, n){
        REP(j,n){
            d[i][j] = abs(x[j] - x[i])+abs(y[j] - y[i])+ max(0ll, z[j] - z[i]);
        }
    }

    fill((int *)dp, (int *)(dp + (1 << MAXN)), -1);
    cout << rec(0, 0) << endl;
    return 0;
}