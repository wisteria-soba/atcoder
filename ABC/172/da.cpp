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

vector<ll> create_prime_list(ll n)
{
    vector<bool> is_prime(n + 1,true);
    is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++)
    {
        if(is_prime[i]){
            for (ll j = i * i; j <= n; j+=i){
                is_prime[j] = false;
            }
                }
    }
    vector<ll> prmie_lsit;
    for (ll i = 2; i <= n;i++){
        if(is_prime[i]){
            prmie_lsit.push_back(i);
        }
    }
    return prmie_lsit;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    ll ans = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll y = n / i;
        ans += y * (y + 1) * i / 2;
    }

    cout << ans << endl;
    return 0;
}