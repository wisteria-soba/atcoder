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
    ll k;
    int n;
    cin >> n >> k;
    vector<int> a(n);
    vector<ll> cf(n,0);

    REP(i,n) {
        cin >> a[i];
    }

    cf[cf.size() - 1] = a[a.size() - 1];
    REPR(i, n - 1){
        cf[i] = cf[i + 1] + a[i];
    }

    return 0;
}