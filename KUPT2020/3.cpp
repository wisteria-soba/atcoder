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
    ll size = 12;
    ll gatyagatya = 100000000;
    vector<int> pt;
    REP(i,26){
        pt.push_back(i);
    }
    REP(m, gatyagatya)
    {
        vector<vector<bool>> used_table(26, vector<bool>(26, false));
        vector<vector<int>> grid(size + 2, vector<int>(size + 2, -1));
        REP(i, size)
        {
            REP(j, size)
            {
                int y = i + 1;
                int x = j + 1;
                next_permutation(all(pt));
                REP(d,26)
                {
                    char c = pt[d];
                    bool put = true;
                    FOR(u, -1, 1)
                    {
                        FOR(v, -1, 1)
                        {
                            if (u * v == 0 && grid[y + u][x + v] != -1)
                            {
                                if (used_table[grid[y + u][x + v]][c])
                                {
                                    put = false;
                                }
                            }
                        }
                    }
                    if (put)
                    {
                        grid[y][x] = c;
                        FOR(u, -1, 1)
                        {
                            FOR(v, -1, 1)
                            {
                                if (u * v == 0 && grid[y + u][x + v] != -1)
                                {
                                    used_table[grid[y + u][x + v]][c] = true;
                                    used_table[c][grid[y + u][x + v]] = true;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
        bool kitakore = true;
        REP(i, size)
        {
            REP(j, size)
            {
                if (grid[i+1][j+1] == -1)
                {
                    kitakore = false;
                    break;
                }
            }
        }
        if (kitakore)
        {
            cout << size << endl;
            REP(i, size)
            {
                REP(j, size)
                {
                    cout << (char)('a' + grid[i + 1][j + 1]);
                }
                cout << endl;
            }
            break;
        }
    }

    return 0;
}