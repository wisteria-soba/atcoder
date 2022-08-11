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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> copt;
    vector<string> c = {"A","B","X","Y"};
    ll cnt_max = 0;
    REP(i, c.size())
    {
        REP(j,c.size()){
            copt.push_back(c[i]+c[j]);
        }
    }

    REP(i,copt.size()){
        ll cnt = 0;
        vector<bool> used_flag(n, false);
        REP(j,n-1){
            if(s.substr(j,2) == copt[i] && !used_flag[j] && !used_flag[j+1]){
                used_flag[j] = true;
                used_flag[j + 1] = true;
                cnt++;
            }
        }
        REP(j,copt.size()){
            ll cnt2 = 0;
            vector<bool> tmp = used_flag;
            if (i == j)
            {
                continue;
            }
            REP(k,n-1){
                if(s.substr(k,2) == copt[j] && !tmp[k] && !tmp[k+1]){
                    tmp[k] = true;
                    tmp[k + 1] = true;
                    cnt2++;
                }
            }
            chmax(cnt_max, cnt+cnt2);
        }
        
    }
    cout << cnt_max + (n - cnt_max * 2) << endl;

    return 0;
}