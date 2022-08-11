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


int main(void)
{
    int n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> cnt;
    REP(i, n)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll ans = 0;
    for (auto itr = cnt.begin(); itr != cnt.end();itr++){
        ans += itr->second*(itr->second-1)/2;
    }

    REP(i,n){
        ll tmp = ans - cnt[a[i]] * (cnt[a[i]] - 1) / 2;
        ll dcnt = cnt[a[i]] - 1;
        cout << tmp + dcnt * (dcnt - 1) / 2 << endl;
    }

    return 0;
}