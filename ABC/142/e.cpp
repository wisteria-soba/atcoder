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

int main(void)
{
    ll n;
    int m;
    cin >> n >> m;
    unsigned int s = 0;
    unsigned int smax = pow(2, n) - 1;
    vector<ll> table(smax + 1, LLINF);
    unsigned int ableobpne = 0;
    vector<int> a(m);
    vector<unsigned int> b(m);
    vector<unsigned int> c(m);

    REP(i,m){
        cin >> a[i];
        cin >> b[i];
        REP(j,b[i]){
            unsigned int tmp;
            cin >> tmp;
            c[i] |= (1 << (tmp - 1));
        }
        ableobpne |= c[i];
    }

    if (ableobpne != smax)
    {
        cout << -1 << endl;
        return 0;
    }

    table[0] = 0;
    REP(i, m)
    {
        for (int j = smax; j >= 0; j--)
        {
            if (j | b[i] <= smax)
            {
                unsigned int tmp = j | c[i];
                if (table[j] != LLINF)
                {
                    chmin(table[j | c[i]], table[j] + a[i]);
                }
            }
        }
    }
    cout << table[smax] << endl;
    return 0;
}