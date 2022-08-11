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
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> gusuc(n, 0);
    REP(i, n)
    {
        cin >> a[i];
        b[i] = a[i] / 2;

        ll pow2 = 2;
        while (b[i] % pow2 == 0){
            gusuc[i]++;
            pow2 *= 2;
        }
    }



    bool flag = true;
    REP(i,n){
        if(gusuc[i] != gusuc[0]){
            flag = false;
            break;
        }
    }

    if(flag){
        // ll pow2 = pow(2, gusuc[0]);
        // REP(i, n)
        // {
        //     b[i] /= pow2;
        // }
        ll lcm = b[0];

        FOR(i,1,b.size()){
            lcm = lcm * (b[i] / gcd(lcm, b[i]));
        }

        ll cnt = 0;
        ll kisu = 1;
        //lcm *= pow2;

        while (kisu  <= m / lcm)
        {
            cnt++;
            kisu += 2;
        }
        cout << cnt << endl;
    }
    else{
        cout << 0 << endl;
    }


    return 0;
}