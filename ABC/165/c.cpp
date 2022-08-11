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

ll search_ms_sub(vector<ll> A,vector<ll> &a,vector<ll> &b,vector<ll> &c,vector<ll> &d,ll n,ll m)
{
    if(A.size() == n){
        ll score = 0;
        REP(i, a.size())
        {
            if(A[b[i]-1] - A[a[i]-1] == c[i]){
                score += d[i];
            }
        }
        return score;
    }
    ll max_score = 0;
    for (ll i = A[A.size() - 1]; i <= m; i++)
    {
        vector<ll> tmp = A;
        tmp.push_back(i);
        chmax(max_score,search_ms_sub(tmp, a, b, c, d,n,m));
    }
    return max_score;
}

ll search_ms(vector<ll> &a,vector<ll> &b,vector<ll> &c,vector<ll> &d,ll n,ll m)
{
    ll max_score = 0;
    for (ll i = 1; i <= m; i++)
    {
        vector<ll> tmp;
        tmp.push_back(i);
        chmax(max_score,search_ms_sub(tmp, a, b, c, d,n,m));
    }
    return max_score;
}


int main(void)
{
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(q);
    vector<ll> b(q);
    vector<ll> c(q);
    vector<ll> d(q);
    REP(i,q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    cout << search_ms(a, b, c, d, n, m) << endl;
    return 0;
}