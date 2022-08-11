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

void create_lunlun(ll d,ll val,vector<ll> &digits)
{
    digits.push_back(val);
    if(d == 10){
        return;
    }
    FOR(i,-1,2){
        int add = (val % 10) + i;
        if (add >= 0 && add <= 9)
        {
            create_lunlun(d + 1, val * 10 + add, digits);
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll k;
    cin >> k;
    vector<ll> digits;
    FOR(i,1,10){
        create_lunlun(1, i, digits);
    }
    sort(all(digits));
    cout << digits[k - 1] << endl;
    return 0;
}