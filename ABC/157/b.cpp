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
    vector<vector<int>> a(3, vector<int>(3, 0));
    vector<vector<bool>> hit(3, vector<bool>(3, false));
    REP(i, 3)
    {
        REP(j,3){
            cin >> a[i][j];
        }
    }
    int n;
    cin >> n;
    vector<int> b(n);
    REP(i,n){
        cin >> b[i];
        REP(j,3){
            REP(k,3){
                if(a[j][k] == b[i]){
                    hit[j][k] = true;
                }
            }
        }
    }

    bool ans = false;
    
    REP(i,3){
        bool flag = true;
        REP(j, 3)
        {
            if(!hit[i][j]){
                flag = false;
            }
        }
        if(flag){
            ans = true;
        }
    }

    REP(i,3){
        bool flag = true;
        REP(j, 3)
        {
            if(!hit[j][i]){
                flag = false;
            }
        }
        if(flag){
            ans = true;
        }
    }

    bool flag = true;
    REP(i, 3)
    {
        if(!hit[i][i]){
            flag = false;
        }
    }
    if(flag){
        ans = true;
    }

    flag = true;
    REP(i, 3)
    {
        if(!hit[i][2 - i]){
            flag = false;
        }
    }
    if(flag){
        ans = true;
    }

    if(ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}