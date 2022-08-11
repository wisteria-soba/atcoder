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

char win(char c){
    if(c == 'r'){
        return 'p';
    }
    else if(c == 's'){
        return 'r';
    }
    else {
        return 's';
    }
}

char oth(char c1,char c2)
{
    string list = "rsp";

    REP(i,list.size()){
        if(c1 != list[i] && c2 != list[i]){
            return list[i];
        }
    }
    return 'r';
}

int main(void)
{
    int n, k;
    ll r, s, p;
    string t;
    string w;

    cin >> n >> k;
    cin >> r >> s >> p;
    cin >> t;

    w = t;

    REP(i,n){
        w[i] = win(t[i]);
    }

    vector<vector<char>> table(k);
    vector<vector<char>> orig(k);
    REP(i, k)
    {
        for (int j = 0; j + i< w.size();j+=k){
            table[i].push_back(w[i + j]);
            orig[i].push_back(w[i + j]);
        }
    }


    REP(i,k){
        for (int j = 0; j < table[i].size()-1;j++)
        {
            if(table[i][j] == table[i][j+1]){
                if(j == table[i].size()-2){
                    table[i][j + 1] = win(table[i][j]);
                }
                else{
                    table[i][j + 1] = oth(table[i][j + 2], table[i][j]);
                }
            }
        }
    }



    ll sum = 0;

    REP(i,table.size())
    {
        REP(j,table[i].size()){
            if(table[i][j] == 'r' && table[i][j] == orig[i][j]){
                sum += r;
            }
            else if(table[i][j] == 's' && table[i][j] == orig[i][j]){
                sum += s;
            }
            else if(table[i][j] == 'p' && table[i][j] == orig[i][j]){
                sum += p;
            }
        }
    }

    cout << sum << endl;

    return 0;
}