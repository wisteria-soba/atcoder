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


unordered_map<ll,ll> calc_factors(ll n)
{
    unordered_map<ll, ll> factors;
    for (ll i = 2; i * i <= n; i++)
    {
        while(n%i==0){
            factors[i]++;
            n /= i;
        }
    }

    if(n != 1){
        factors[n]++;
    }
    return factors;
}

int main(void)
{
    ll n;
    cin >> n;

    unordered_map<ll, ll> factors_of_factrial;
    FOR(i,2,n+1){
        unordered_map<ll,ll> factors = calc_factors(i);
        for (auto itr = factors.begin(); itr != factors.end();itr++){
            factors_of_factrial[itr->first] += itr->second;
        }
    }

    ll ans = 1;
    ll mod = 1e9 + 7;

    for (auto itr = factors_of_factrial.begin(); itr != factors_of_factrial.end();itr++){
        ans = (ans * (itr->second + 1) % mod) % mod;
    }

    cout << ans << endl;

    return 0;
}