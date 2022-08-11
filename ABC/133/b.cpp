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
    int n,d;
    cin >> n >> d;
    vector<vector<int>> p(n,vector<int>(d));

    REP(i,n){
        REP(j,d){
            cin >> p[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n - 1;i++){
        for (int j = i + 1; j < n;j++){
            int sum = 0;
            REP(k,d){
                sum += pow(p[i][k] - p[j][k], 2);
            }
            if(pow(floor(sqrt(sum)),2) == sum){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}