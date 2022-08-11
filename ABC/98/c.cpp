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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> cntlw(n, 0);
    vector<ll> cntre(n, 0);
    
    if(s[0] == 'W'){
        cntlw[0] = 1;
    }

    FOR(i,1,n){
        if(s[i] == 'W'){
            cntlw[i] = cntlw[i-1] + 1;
        }
        else{
            cntlw[i] = cntlw[i - 1];
        }
    }

    if(s[n-1] == 'E'){
        cntre[n-1] = 1;
    }

    REPR(i,n-2){
        if(s[i] == 'E'){
            cntre[i] = cntre[i + 1] + 1;
        }
        else{
            cntre[i] = cntre[i + 1];
        }
    }

    ll minc = cntre[1];
    FOR(i, 1, n - 1)
    {
        ll cnt = cntlw[i - 1] + cntre[i + 1];
        if(minc >= cnt){
            minc = cnt;
        }
    }

    cout << min(minc,cntlw[n-2]) << endl;
    return 0;
}