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
    int n;
    ll sum = 0;
    cin >> n;
    vector<int> a(n+1);
    REP(i,n+1){
        cin >> a[i];
        sum += a[i];
    }
    vector<int> b(n);
    REP(i,n) cin >> b[i];

    REP(i,n){
        if(a[i] < b[i]){
            a[i + 1] -= min(b[i] - a[i],a[i+1]);
        }
        a[i] -= min(a[i], b[i]);

    }

    ll rest = 0;
    REP(i, a.size()){
        rest += a[i];
    }

    cout << sum - rest << endl;

    return 0;
}