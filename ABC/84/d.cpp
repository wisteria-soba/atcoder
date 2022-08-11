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

vector<bool> create_prime_table(ll n)
{
    vector<bool> is_prime(n+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (ll i = 0; i*i <= n; i++)
    {
        if(is_prime[i]){
            for (ll j = i*i; j < n; j+=i)
            {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n = 1e5;
    vector<bool> is_prime = create_prime_table(n);
    vector<bool> like2017(n + 1, false);
    REP(i,is_prime.size()){
        if(is_prime[i] && is_prime[(i+1)/2]){
            like2017[i] = true;
        }
    }
    vector<ll> csum(n + 1, 0);
    FOR(i,1,csum.size()){
        csum[i] = csum[i - 1];
        if(like2017[i]){
            csum[i]++;
        }
    }
    ll q;
    cin >> q;
    vector<ll> l(q);
    vector<ll> r(q);
    REP(i,q){
        cin >> l[i] >> r[i];
    }
    REP(i,q){
        cout << csum[r[i]] - csum[l[i] - 1] << endl;
    }
    return 0;
}