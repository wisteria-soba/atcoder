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
    int h,w;
    int n;
    cin >> h >> w;
    cin >> n;

    vector<vector<int>> grid(h,vector<int>(w));
    vector<int> a;
    REP(i,n){
        int tmp;
        cin >> tmp;
        REP(j,tmp){
            a.push_back(i + 1);
        }
    }

    int cnt = 0;
    REP(i, h)
    {
        if(i % 2 == 0){
            REP(j,w){
                grid[i][j] = a[cnt];
                cnt++;
            }
        }
        else{
            REPR(j,w-1){
                grid[i][j] = a[cnt];
                cnt++;
            }
        }
    }

    REP(i,h){
        REP(j,w-1){
            cout << grid[i][j] << " ";
        }
        cout << grid[i][w-1] << endl;
    }

    return 0;
}