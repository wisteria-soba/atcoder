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

vector<ll> smallest_prime_factors(ll n)
{
    vector<ll> spf(n + 1);
    for (ll i = 0; i <= n; i++){
        spf[i] = i;
    }
    for (ll i = 2; i*i <= n; i++){
        if(spf[i] == i){
            for (ll j = i * i; j <= n; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
            
        }
    }
    return spf;
}

unordered_map<ll,ll> spf_factolization(ll x,vector<ll> &spf)
{
    unordered_map<ll,ll> ret;
    while(x != 1){
        ret[spf[x]]++;
        x /= spf[x];
    }
    return ret;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    ll gcd_all = a[0];
    REP(i, n){
        gcd_all = gcd(a[i], gcd_all);
    }
    unordered_map<ll,ll> fact_count;
    auto spf = smallest_prime_factors(1e6);
    REP(i,n){
        auto factors = spf_factolization(a[i], spf);
        for (auto itr = factors.begin(); itr != factors.end() ; itr++){
            fact_count[itr->first]++;
        }
    }
    for (auto itr = fact_count.begin(); itr != fact_count.end() ; itr++){
        if(itr->second >= 2){
            if(gcd_all == 1){
                cout << "setwise coprime" << endl;
            }
            else{
                cout << "not coprime" << endl;
            }
            return 0;
        }
    }
    cout << "pairwise coprime" << endl;

    return 0;
}