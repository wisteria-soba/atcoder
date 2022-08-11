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

bool pairCompare(const pair<int,int>& firstElof, const pair<int,int>& secondElof)
{
    return firstElof.second < secondElof.second;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cut(m);
    REP(i,m)
    {
        cin >> cut[i].first >> cut[i].second;
    }
    sort(all(cut),pairCompare);

    vector<pair<int, int>> cut_range;
    cut_range.push_back(cut[0]);

    FOR(i,1,m)
    {
        auto itr = upper_bound(all(cut_range),pair<int,int>(INF,cut[i].first),pairCompare);
        if( itr == cut_range.end()){
            cut_range.push_back(cut[i]);
        }
        else{
            itr->first = max(itr->first,cut[i].first);
        }
    }

    cout << cut_range.size() << endl;

    return 0;
}