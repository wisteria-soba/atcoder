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
    int n,m;
    cin >> n >> m;
    vector<int> s(m);
    vector<int> c(m);
    REP(i,m){
        cin >> s[i] >> c[i];
    }

    bool exist = true;

    REP(i,m-1){
        FOR(j,i+1,m){
            if(s[i] == s[j] && c[i] != c[j]){
                exist = false;
            }

        }
    }

    if(!exist){
        cout << -1 << endl;
        return 0;
    }

    int zdigit = n + 1;
    int nz = n + 1;
    REP(i, m)
    {
        if(c[i] == 0 && s[i] < zdigit){
            zdigit = s[i];
        }
        else if(c[i] != 0 && s[i] < nz){
            nz = s[i];
        }
    }

    if(zdigit < nz && !(zdigit == n && nz == n+1)){
        cout << -1 << endl;
        return 0;
    }

    if(n == 1 && zdigit == 1 || m == 0 && n == 1){
        cout << 0 << endl;
        return 0;
    }

    vector<int> ans(n,0);
    REP(i,m){
        ans[s[i] - 1] = c[i];
    }
    ans[0] = max(ans[0], 1);
    REP(i,n){
        cout << ans[i];
    }
    cout << endl;

    return 0;
}