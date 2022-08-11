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

vector<pair<int,int>> kinbo4(int ch,int cw)
{
    vector<pair<int,int>> list(4);
    list[0] = pair<int, int>(ch, cw + 1);
    list[1] = pair<int, int>(ch, cw - 1);
    list[2] = pair<int, int>(ch + 1, cw);
    list[3] = pair<int, int>(ch - 1, cw);
    return list;
}

int main(void)
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h + 2, vector<char>(w + 2, '#'));

    FOR(i,1,h+1){
        FOR(j,1,w+1){
            cin >> s[i][j];
        }
    }

    // FOR(i,0,h+2){
    //     FOR(j,0,w+2){
    //         cout << s[i][j];
    //     }
    //     cout << endl;
    // }

    //vector<vector<int>> maxdis(h + 2, vector<int>(w + 2, 0));

    int amax = 0;

    FOR(i,1,h+1){
        FOR(j,1,w+1){
            if(s[i][j] == '#'){
                continue;
            }
            queue<pair<int, int>> ta;
            ta.push(pair<int, int>(i, j));
            vector<vector<int>> dis(h + 2, vector<int>(w + 2, 0));
            vector<vector<int>> color(h + 2, vector<int>(w + 2, 0));
            color[i][j]++;
            while (!ta.empty())
            {
                pair<int, int> v = ta.front();
                int ch = v.first;
                int cw = v.second;
                ta.pop();
                vector<pair<int, int>> kin4 = kinbo4(ch, cw);
                REP(k,kin4.size()){
                    int nh = kin4[k].first;
                    int nw = kin4[k].second;
                    if(s[nh][nw] == '.' && color[nh][nw] == 0){
                        color[nh][nw] = 1;
                        dis[nh][nw] = dis[ch][cw] + 1;
                        ta.push(kin4[k]);
                    }
                }
            }

            //int amax = 0;
            FOR(k,1,h+1){
                FOR(m,1,w+1){
                    if(dis[k][m] > amax){
                        amax = dis[k][m];
                    }
                }
            }

            //maxdis[i][j] = amax;
        }
    }

    cout << amax << endl;

    return 0;
}