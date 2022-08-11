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
    pair<ll, ll> ta;
    pair<ll, ll> tb;
    ll t, v;
    cin >> ta.first >> ta.second >> tb.first >> tb.second >> t >> v;
    ll n;
    cin >> n;
    vector<pair<ll, ll>> girls(n);
    REP(i,n){
        cin >> girls[i].first >> girls[i].second;
    }

    ll cost = t * v;
    REP(i,n){
        if(sqrt(pow(girls[i].first - ta.first,2)+pow(girls[i].second-ta.second,2))
        +sqrt(pow(girls[i].first-tb.first,2)+pow(girls[i].second-tb.second,2))
        <= cost){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}