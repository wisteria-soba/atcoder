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

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a);
    REP(i, a) cin >> p[i];
    vector<ll> q(b);
    REP(i, b) cin >> q[i];
    vector<ll> r(c);
    REP(i, c) cin >> r[i];

    sort(all(p), greater<int>());
    sort(all(q), greater<int>());
    sort(all(r),greater<int>());

    vector<ll> merged;
    ll i = 0, j = 0;
    while (i < x || j < y){
        if(i < x && j < y){
            if (p[i] > q[j])
            {
                merged.push_back(p[i]);
                i++;
            }
            else{
                merged.push_back(q[j]);
                j++;
            }
        }
        else if( i >= x ){
            merged.push_back(q[j]);
            j++;
        }
        else{
            merged.push_back(p[i]);
            i++;
        }
    }

    REP(i,r.size()){
        if(i >= merged.size()){
            break;
        }
        if(r[i] > merged[x+y-1-i]){
            merged[x+y-1-i] = r[i];
        }
    }

    ll sum = 0;
    REP(i,merged.size()){
        sum += merged[i];
    }
    cout << sum << endl;
    return 0;
}