#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i = n;i >= 0;--i)
#define FOR(i,m,n) for(int i = m, i##_len=(n);i <i##_len; ++i)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int INF = 1e9;
const ll LLINF = 1e16;

int main(void)
{
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    int cntrl = 0;
    int cntlr = 0;
    int ml = 0;
    int mr = 0;
    int sum = 0;

    if (s[0] == 'L')
    {
        ml++;
    }
    if (s[n - 1] == 'R')
    {
        mr++;
    }

    REP(i, n - 1)
    {
        if (s[i] == 'R' && s[i + 1] == 'R')
        {
            sum++;
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        if (s[i] == 'L' && s[i - 1] == 'L')
        {
            sum++;
        }
    }

    REP(i, n - 1)
    {
        string tmp = s.substr(i, 2);
        if (tmp == "LR")
        {
            cntlr++;
        }
        else if (tmp == "RL")
        {
            cntrl++;
        }
    }

    int p2 = min(cntrl, cntlr);
    int p1 = 0;

    if (k <= p2)
    {
        p2 = k;
    }
    else if (cntlr > cntrl && ml + mr > 0)
    {
        p1++;
    }
    else if (cntlr < cntrl && ml + mr < 2)
    {
        p1++;
    }
    cout << sum + p2 * 2 + p1 << endl;
    return 0;
}