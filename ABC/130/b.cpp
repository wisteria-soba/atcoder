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
    vector<int> a(n + 1);
    a[0] = 0;
    FOR(i,1,n+1)
    {
        cin >> a[i];
    }

    vector<int> L(n + 2,0);
    vector<int> R(n + 2,0);

    for (int i = 0; i < L.size() - 1;i++){
        L[i + 1] = gcd(L[i], a[i]);
    }

    for (int i = n; i >= 1;i--){
        R[i] = gcd(R[i + 1], a[i]);
    }

    vector<int> M(n);
    for (int i = 1; i <= n;i++){
        M[i - 1] = gcd(L[i], R[i + 1]);
    }

    int ans = *max_element(all(M));
    cout << ans << endl;

    return 0;
}