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
    ll h, w;
    cin >> h >> w;
    ll ch, cw;
    ll dh, dw;
    cin >> ch >> cw;
    cin >> dh >> dw;
    vector<vector<char>> s(h + 4, vector<char>(w + 4, '#'));
    FOR(i, 2, h+2)
    {
        FOR(j, 2, w+2)
        {
            cin >> s[i][j];
        }
    }
    ll color_cnt = -1;
    vector<vector<ll>> color(h + 4, vector<ll>(w + 4, -1));
    vector<vector<pair<ll,ll>>> ggraph;
    FOR(i, 2, h+2)
    {
        FOR(j,2,w+2){
            if(s[i][j] == '.' && color[i][j] == -1){
                color[i][j] = ++color_cnt;
                ggraph.push_back({pair<ll,ll>(i,j)});
                queue<pair<ll, ll>> sg;
                sg.push(pair<ll, ll>(i, j));
                while (!sg.empty())
                {
                    pair<ll, ll> v = sg.front();
                    sg.pop();
                    FOR(y,-1,2){
                        FOR(x,-1,2){
                            if(x * y != 0){
                                continue;
                            }
                            if (s[v.first + y][v.second + x] == '.' && color[v.first + y][v.second + x] == -1)
                            {
                                color[v.first + y][v.second + x] = color_cnt;
                                ggraph[color_cnt].push_back(pair<ll, ll>(v.first + y, v.second + x));
                                sg.push(pair<ll, ll>(v.first + y, v.second + x));
                            }
                        }
                    }
                }
            }
        }
    }
    vector<vector<ll>> graph(ggraph.size());
    REP(i,ggraph.size()){
        vector<bool> visited(graph.size(), false);
        REP(j, ggraph[i].size())
        {
            FOR(y, -2, 3)
            {
                FOR(x, -2, 3)
                {
                    int u = color[ggraph[i][j].first + y][ggraph[i][j].second + x];

                    if (u != i && u!= -1 && !visited[u])
                    {
                        graph[i].push_back(u);
                        visited[u] = true;
                    }
                }
            }
        }
    }

    vector<ll> dist(graph.size(), -1);
    queue<ll> sg;
    dist[color[ch + 1][cw + 1]] = 0;
    sg.push(color[ch + 1][cw + 1]);
    while(!sg.empty()){
        int v = sg.front();
        sg.pop();
        REP(i, graph[v].size())
        {
            if(dist[graph[v][i]] == -1){
                dist[graph[v][i]] = dist[v] + 1;
                sg.push(graph[v][i]);
            }
        }
    }

    cout << dist[color[dh + 1][dw + 1]] << endl;

    return 0;
}