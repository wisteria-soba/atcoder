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
    ll n, k;
    cin >> n >> k;
    vector<ll> sunuke(n,0);
    vector<vector<ll>> wh(k);
    REP(i, k) { 
        int d;
        cin >> d;
        REP(j,d){
            int a;
            cin >> a;
            sunuke[a - 1]++;
        }
    }

    ll ans = 0;
    REP(i, n) {
        if(sunuke[i] == 0){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}