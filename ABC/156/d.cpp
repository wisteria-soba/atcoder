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

ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return N * RepeatSquaring(N, P-1, M);
}

ll mod_conv(ll n,ll r,ll mod)
{
    ll nume = 1;
    ll deno = 1;

    FOR(i,0,r){
        nume = (nume  * (n - i)) % mod;
        deno = (deno * (1 + i)) % mod;
    }

    return (nume * modinv(deno,mod))%mod;
}

int main(void)
{
    ll n;
    ll mod = 1e9 + 7;
    cin >> n;
    ll all = RepeatSquaring(2, n, mod) - 1;
    ll a, b;
    cin >> a >> b;

    ll ans = all - mod_conv(n, a,mod);
    ans = (ans < 0) ? ans + mod : ans;

    ans = ans - mod_conv(n, b, mod);
    ans = (ans < 0) ? ans + mod : ans;
    

    if(n <= 2){
        cout << '0' << endl;
    }
    else{
        cout << ans  % mod<< endl;
    }

    return 0;
}