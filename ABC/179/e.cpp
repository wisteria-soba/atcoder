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
    ll n, x, m;
    cin >> n >> x >> m;
    vector<bool> appeared(m, false);
    vector<ll> a;
    ll lcnt = 1;
    ll lsum = 0;
    ll lnum = -1;
    a.push_back(x);
    REP(i, n-1)
    {
        ll last = a[a.size() - 1];
        ll next = last * last % m;
        if(appeared[next]){
            lnum = next;
            a.push_back(next);
            break;
        }
        appeared[next] = true;
        a.push_back(next);
    }
    if(lnum != -1){
        ll lsidx = 0;
        while(a[lsidx] != lnum){
            lsidx++;
        }
        lsum = lnum;
        for (int i = lsidx + 1; a[i] != lnum; i++)
        {
            lcnt++;
            lsum += a[i];
        }
        ll ans = 0;

        REP(i,lsidx){
            ans += a[i];
        }
        ans += lsum * ((n - lsidx) / lcnt);
        FOR(i, lsidx, lsidx + (n - lsidx) % lcnt)
        {
            ans += a[i];
        }
        cout << ans << endl;
    }
    else{
        ll ans = 0;
        REP(i,a.size()){
            ans += a[i];
        }
        cout << ans << endl;
    }

    return 0;
}