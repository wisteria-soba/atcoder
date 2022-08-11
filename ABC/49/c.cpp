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
    string s;
    cin >> s;

    string t = "";
    vector<string> component;
    component.push_back("dream");
    component.push_back("dreamer");
    component.push_back("erase");
    component.push_back("eraser");

    for (int i = s.size() - 1; i >= 0;){
        bool flag = false;
        REP(j,component.size()){

            if ( (int)(i - component[j].size() + 1) < 0)
            {
                continue;
            }

            if(s.substr(i-component[j].size() + 1,component[j].size()) == component[j]){
                flag = true;
                i -= component[j].size();
                t = component[j] + t;
                break;
            }
        }
        if(!flag){
            break;
        }
    }

    if (s == t)
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }


    return 0;
}