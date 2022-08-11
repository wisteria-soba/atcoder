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
ll modinv(ll a, ll m) {ll b = m, u = 1, v = 0;while (b) {ll t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}
const int INF = 1e9;
const ll LLINF = 1e16;

bool canCut(vector<double> a, double max_size,ll k) {
    ll sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i] > max_size){
            sum += ceil(a[i] / max_size)-1;
        }
    }

    if(sum <= k){
        return true;
    }
    else{
        return false;
    }
}

int main(void)
{
    ll n, k;
    cin >> n >> k;
    vector<double> a(n);
    ll max_a = 0;
    REP(i, n) { 
        cin >> a[i];
        if(max_a <= a[i]){
            max_a = a[i];
        }
    }
    double right = max_a;
    double left = 0.5;
    double middle;
    while(true) {
        middle = (right + left) / 2;
        if((ll)ceil(right) == (ll)ceil(left)){
            break;
        }
        if(canCut(a,middle,k)){
            right = middle;
        }
        else{
            left = middle;
        }
    }
    cout << (ll)ceil(middle) << endl;
    return 0;
}