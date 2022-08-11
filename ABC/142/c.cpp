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
    cin >> n;
    vector<pair<int,int>> a(n);
    REP(i,n){
        a[i].second = i;
        cin >> a[i].first;
    }

    sort(all(a));

    REP(i,n - 1){
        cout << a[i].second  + 1 << " ";
    }

    cout << a[n - 1].second + 1 << endl;

    return 0;
}