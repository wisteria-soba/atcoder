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
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    uint ss = s.size() - 1;
    ll sum = 0;
    unsigned long long end = pow(2, ss) - 1 ;
    for (uint i = 0; i <= end;i++){
        ll prev = -1;
        for (uint j = 0; j < ss; j++)
        {
            if(i & (1<<j)){
                string sub = s.substr(ss - j, j - prev);
                sum += stoll(sub);
                prev = j;
            }
        }
        string sub = s.substr(0, ss - prev);
        sum += stoll(sub);
    }
    cout << sum << endl;

    return 0;
}