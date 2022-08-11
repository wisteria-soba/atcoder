#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i = n;i >= 0;--i)
#define FOR(i,m,n) for(int i = m, i##_len=(n);i <i##_len; ++i)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int INF = 1e9;
const ll LLINF = 1e16;

int main(void)
{
    string s;
    cin >> s;
    vector<vector<ll>> dp(s.size()+1,vector<ll>(13,0));
    ll mod = 1e9 + 7;
    dp[0][0] = 1;
    FOR(i, 0, s.size())
    {
        if(s[i] == '?'){
            REP(j,10){
                REP(k,13){
                    dp[i + 1][(k * 10 + j)%13] += dp[i][k];
                }
            }
        }
        else{
            REP(j,13){
                dp[i + 1][(j * 10 + (s[i] - '0')) % 13] += dp[i][j];
            }
        }
        REP(j,13){
            dp[i + 1][j] %= mod;
        }
    }
    cout << dp[s.size()][5] << endl;

    return 0;
}