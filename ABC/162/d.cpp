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

char ncolor(char a,char b){
    if(a != 'R' && b != 'R'){
        return 'R';
    }
    else if(a != 'G' && b != 'G'){
        return 'G';
    }
    else{
        return 'B';
    }
}

ll conum(char col){
    if(col == 'R'){
        return 0;
    }
    else if(col == 'G'){
        return 1;
    }
    else{
        return 2;
    }
}

int main(void)
{
    ll n;
    string s;
    cin >> n;
    cin >> s;

    vector<vector<ll>> ccnt(3, vector<ll>(n, 0));

    REP(j,3){
        if(conum(s[0]) == j){
            ccnt[j][0] = 1;
        }
    }

    FOR(i,1,n){
        REP(j,3){
            if(conum(s[i]) == j){
                ccnt[j][i] = ccnt[j][i - 1] + 1;
            }
            else{
                ccnt[j][i] = ccnt[j][i - 1];
            }
        }
    }

    ll ans = 0;

    REP(i,n){
        FOR(j,i+1,n){
            if(s[i] != s[j]){
                char nco = ncolor(s[i], s[j]);
                ll nconum = conum(nco);
                ans += ccnt[nconum][n - 1] - ccnt[nconum][j];
                if(j + j - i < n){
                    if(s[i] != s[j + j - i] && s[j] != s[j + j -i]){
                        ans--;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}