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
    unsigned long long a,b;
    cin >> a >> b;

    a--;
    unsigned long long a_size = max(0,(int)log2(a) + 1);
    unsigned long long b_size = max(0,(int)log2(b) + 1);
    unsigned long long ansbit_size = max(a_size, b_size);

    vector<ll> abit(ansbit_size,0);
    vector<ll> bbit(ansbit_size,0);

    for (unsigned long long i = 0,pow2 = 1; i < a_size;i++){

        if(i == 0){
            abit[i] = (a / 2 + a % 2) % 2;
        }
        else if(a & pow2){
            if(a%2 == 0){
                abit[i] = 1;
            }
        }
        pow2 *= 2;
    }
    for (unsigned long long i = 0,pow2 = 1; i < b_size;i++){

        if(i == 0){
            bbit[i] = (b / 2 + b % 2) % 2;
        }
        else if(b & pow2){
            if(b%2 == 0){
                bbit[i] = 1;
            }
        }
        pow2 *= 2;
    }
    vector<ll> ansbit(ansbit_size);
    REP(i,ansbit_size){
        ansbit[i] = bbit[i] + abit[i];
    }

    unsigned long long ans = 0;
    for (unsigned long long i = 0, pow2 = 1; i < ansbit.size();i++){
        ans += (ansbit[i] % 2) * pow2;
        pow2 *= 2;
    }

    cout << ans << endl;

    return 0;
}