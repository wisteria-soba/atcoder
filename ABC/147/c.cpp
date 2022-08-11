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
    int cnt = 0;
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> xy(n);

    REP(i, n)
    {
        int a;
        cin >> a;
        REP(j,a){
            pair<int, int> d;
            cin >> d.first >> d.second;
            d.first--;
            xy[i].push_back(d);
        }
    }

    uint S = pow(2, n) - 1;
    for (uint T = S;; T = (T - 1) & S)
    {
        vector<int> tc(n,0);
        vector<int> fc(n,0);
        if (T == 0)
        {
            break;
        }
        int onenum = 0;
        int ic = 0;
        bool flag = false;

        for (uint i = 1; i <= S; i *= 2)
        {
            if(i&T){
                onenum++;
                REP(j, xy[ic].size())
                {
                    if(xy[ic][j].second == 1){
                        if ( T & (uint)pow(2, xy[ic][j].first) == 0)
                        {
                            flag = true;
                            break;
                        }
                    }
                    else{
                        if ( T & (uint)pow(2, xy[ic][j].first))
                        {
                            flag = true;
                            break;
                        }
                    }
                    if(flag){
                        break;
                    }
                }
            }
            ic++;
        }

        if(flag){
            continue;
        }

        cnt = max(cnt, onenum);

    }

    cout << cnt << endl;

    return 0;
}