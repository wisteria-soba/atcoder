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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    vector<ll> b(m);
    REP(i, m) cin >> b[i];
    reverse(all(a));
    vector<ll> ab;
    ab = a;
    ab.insert(ab.end(), all(b));
    ll timeSum = 0;
    ll maxNum = 0;
    ll right = n;
    ll left;
    for (left = n - 1; left >= 0; left--)
    {
        if(timeSum + ab[left] <= k){
            timeSum += ab[left];
            chmax(maxNum, right - left);
        }
        else{
            break;
        }
    }
    left++;
    for (; left < n + 1; left++)
    {
        while (right < n + m && timeSum + ab[right] <= k)
        {
            timeSum += ab[right];
            right++;
        }
        chmax(maxNum, right - left);
        if(left == right){
            right++;
        }
        else{
            timeSum -= ab[left];
        }
    }
    cout << maxNum << endl;
    return 0;
}