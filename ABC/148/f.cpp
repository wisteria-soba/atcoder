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

class vertex{
    public:
    vector<int> child;
    int parent = -1;
};

vector<int> tree_dis(vector<vertex> tree,int root){
    vector<int> dis(tree.size(),0);
    vector<int> color(tree.size(), 0);
    queue<int> s;
    s.push(root);
    while (!s.empty())
    {
        int v = s.front();
        s.pop();
        color[v]++;
        REP(i, tree[v].child.size())
        {
            if(color[tree[v].child[i] == 0]){
                s.push(tree[v].child[i]);
            }
        }

    }
}

int main(void)
{
    int n;
    int u,v;
    cin >> n >> u >> v;
    u--;
    v--;
    vector<vertex> tree(n);
    vector<int> dis_u(n);
    vector<int> dis_v(n);

    REP(i, n)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].child.push_back(b);
        tree[b].child.push_back(a);
    }

    /*
    queue<int> mks;
    mks.push(v);
    while(!mks.empty()){
        int sv = mks.front();
        mks.pop();
        REP(i,tree[sv].child.size()){
            int child_id = tree[sv].child[i];
            tree[child_id].parent = sv;
            auto e = remove(all(tree[child_id].child), sv);
            tree[child_id].child.erase(e, tree[child_id].child.end());
            mks.push(child_id);
        }
    }
    */

    



    return 0;
}