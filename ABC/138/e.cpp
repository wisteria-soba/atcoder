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
    string s,t;
    cin >> s;
    cin >> t;

    vector<int> sc(26,0);
    vector<int> tc(26,0);
    vector<vector<int>> sp(26);

    REP(i,s.size()){
        sc[s[i] - 'a']++;
        sp[s[i] - 'a'].push_back(i);
        sp[s[i] - 'a'].push_back(i + s.size());
    }
    REP(i,sp.size()) sort(all(sp[i]));

    REP(i,t.size()){
        tc[t[i] - 'a']++;
    }

    REP(i,tc.size()){
        if(tc[i] > 0 && sc[i] == 0){
            cout << -1 << endl;
            return 0;
        }
    }

    ll ans = 0;
    int pre = -1;
    REP(i,t.size()){
        char crt = t[i];
        int crt_i = crt - 'a';
        auto itr = upper_bound(all(sp[crt_i]),pre);
        int mp =  *itr;
        ans += mp - pre;
        pre = (mp >= s.size())?mp-s.size():mp;
    }

    cout << ans << endl;

    return 0;
}