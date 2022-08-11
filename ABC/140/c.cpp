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
    vector<int> b(n-1);
    REP(i,n-1) cin >> b[i];
    vector<int> a(n,-1);

    REP(i,n-1){
        a[i] = b[i];
    }
    int tmp = b[n-2];
    a[n-1] = b[n-2];
    REP(i,n-1){
        if(a[i] > a[i+1]){
            a[i+1] = min(b[i+1],a[i]);
        }
        else{
            a[i+1] = min(b[i],b[i+1]);
        }
        
    }
    a[n-1] = tmp;

    int sum = 0;
    REP(i,n){
        sum += a[i];
    }

    cout << sum << endl;

    return 0;
}