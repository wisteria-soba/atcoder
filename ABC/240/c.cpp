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
    ll n, x;
    cin >> n >> x;
    vector<vector<bool>> visited(n + 1, vector<bool>(x + 1, false));
    visited[0][0] = true;
    for(ll i = 1; i < visited.size(); i++) {
        int a, b;
        cin >> a >> b;
        for(ll j = 0; j < visited[i].size();j++) {
            if(visited[i-1][j]){
                if(j + a <= x){
                    visited[i][j + a] = true;
                }
                if(j+b <= x){
                    visited[i][j + b] = true;
                }
                
            }
        }
    }
    if(visited[n][x]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}