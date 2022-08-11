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
    ll mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i,n){
        cin >> a[i];
    }

    ll sum = 0;
    ll a_max = *max_element(all(a));
    int digit_max = log2(a_max);
    unsigned long long pow2 = 1;
    REP(i, digit_max + 1)
    {
        int one_cnt = 0;
        int zero_cnt = 0;
        REP(j, n)
        {
            if(pow2 & a[j]){
                one_cnt++;
            }
            else{
                zero_cnt++;
            }
        }
        sum += (pow2 % mod * one_cnt % mod * zero_cnt % mod) % mod;
        pow2<<= 1;
    }

    cout << sum % mod << endl;

    return 0;
}