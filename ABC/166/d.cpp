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
    unordered_map<unsigned long long,bool> fac5;
    unordered_map<ll, ll> p;
    ll x;
    cin >> x;
    ll stt = pow(LLONG_MAX-x,1/5.0);
    REP(i, stt) { 
        fac5[pow(i, 5)] = true;
        p[pow(i, 5)] = i;
    }
    FOR(i,-1 * stt,stt){
        if(fac5[abs((ll)pow(i,5) + x)]){
            if(pow(i,5) + x < 0){
                 cout << -1*p[abs(pow(i,5)+x)] << " " << i << endl;
            }
            else{
                cout << p[abs(pow(i,5)+x)] << " " << i << endl;
            }
            return 0;
        }
    }

    return 0;
}