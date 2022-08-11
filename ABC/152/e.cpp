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

unordered_map<ll,ll> prime_factorization(ll n)
{
    unordered_map<ll, ll> prime_fact;
    for (int i = 2; i * i <= n; i++)
    {
        while( n % i == 0){
            prime_fact[i]++;
            n /= i;
        }
    }
    if(n != 1){
        prime_fact[n]++;
    }

    return prime_fact;
}

int main(void)
{
    ll n;
    ll mod = 1e9 + 7;
    cin >> n;
    vector<ll> a(n);
    REP(i,n){
        cin >> a[i];
    }

    vector<unordered_map<ll, ll>> prime_factlist(n);
    REP(i,n){
        prime_factlist[i] = prime_factorization(a[i]);
    }

    unordered_map<ll,ll> lcm_fact = prime_factlist[0];
    FOR(i,1,n){
        for (auto itr = prime_factlist[i].begin(); itr != prime_factlist[i].end();itr++){
            if(lcm_fact[itr->first] < itr->second){
                lcm_fact[itr->first] = itr->second;
            }
        }
    }

    ll lcm = 1;
    for (auto itr = lcm_fact.begin(); itr != lcm_fact.end(); itr++)
    {
        REP(i,itr->second){
            lcm = (lcm * itr->first)%mod;
        }
    }

    ll sum = 0;
    REP(i, n)
    {
        sum  = (sum + lcm * modinv(a[i],mod))%mod;
    }

    cout << sum << endl;

    return 0;
}