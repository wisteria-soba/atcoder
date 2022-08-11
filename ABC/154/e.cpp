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

ll comb(ll n,ll k)
{
    ll nume = 1;
    ll deno = 1;
    REP(i,k){
        nume *= n - i;
        deno *= (i + 1);
    }
    return nume / deno;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s;
    ll k;
    cin >> s;
    cin >> k;
    vector<ll> snum(s.size());
    REP(i, s.size())
    {
        snum[i] = s[i] - '0';
    }
    ll n = s.size();
    vector<vector<ll>> cnt(s.size(), vector<ll>(k+1,0));
    cnt[n - 1][1] = snum[n - 1];
    REPR(i, s.size() - 2)
    {
        if(snum[i]>0){
            cnt[i][1] = snum[i] + 9 * (n - i - 1);
        }
        else{
            cnt[i][1] = cnt[i + 1][1];
        }
    }
    REPR(i, s.size() - 2)
    {
        FOR(j,2,k+1){
            if(snum[i] >= 2){
                cnt[i][j] += (snum[i]-1) * comb(n - i - 1, j - 1) * pow(9, j - 1);
            }
            if(snum[i] > 0){
                cnt[i][j] += comb(n - i - 1, j) * pow(9, j);
                cnt[i][j] += cnt[i + 1][j - 1];
            }
            else{
                cnt[i][j] += cnt[i + 1][j];
            }
        }
    }
    cout << cnt[0][k] << endl;
    return 0;
}