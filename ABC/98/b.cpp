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

    ll max_cnt = 0;

    REP(i,n-1){
        ll cnt = 0;
        string tmp1 = s.substr(0, i + 1);
        string tmp2 = s.substr(i + 1);
        set<char> set1;
        set<char> set2;
        REP(j,tmp1.size()){
            set1.insert(tmp1[j]);
        }
        REP(j,tmp2.size()){
            set2.insert(tmp2[j]);
        }

        for (auto itr = set1.begin(); itr != set1.end();itr++){
            if(set2.find(*itr) != set2.end()){
                cnt++;
            }
        }

        if(max_cnt <= cnt){
            max_cnt = cnt;
        }
    }

    cout << max_cnt << endl;

    return 0;
}