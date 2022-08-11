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

int cnt753(ll n,ll num,vector<bool> is753)
{
    if (num > n)
    {
        return 0;
    }
    vector<ll> el = {7, 5, 3};
    bool ok = true;
    REP(i,is753.size()){
        if(!is753[i]){
            ok = false;
            break;
        }
    }
    ll ans = 0;
    REP(i, el.size())
    {
        ll tmp = num * 10 + el[i];
        vector<bool> tmp2 = is753;
        tmp2[i] = true;
        ans += cnt753(n, tmp,tmp2);
    }
    if (ok)
    {
        ans++;
    }
    return ans;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<bool> unti(3, false);
    cout << cnt753(n, 0,unti) << endl;
    return 0;
}