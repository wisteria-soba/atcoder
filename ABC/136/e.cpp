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

vector<int> divisor(int n)
{
    vector<int> divisor_list;
    for (int i = 1; i * i <= n; i++){
        if(n % i == 0){
            divisor_list.push_back(i);
            divisor_list.push_back(n / i);
        }
    }
    return divisor_list;
}

vector<int> mod_list(vector<int> a,int n)
{
    REP(i,a.size()){
        a[i] = a[i] % n;
    }
    return a;
}

int main(void)
{
    int n, k;
    int sum = 0;
    int ans = 1;
    cin >> n >> k;
    vector<int> a(n);
    REP(i,n){
        cin >> a[i];
        sum += a[i];
    }

    vector<int> div_l = divisor(sum);

    REP(i,div_l.size()){
        vector<int> mod_l = mod_list(a, div_l[i]);
        sort(all(mod_l));
        int mod_sum = 0;
        REP(j, mod_l.size()){
            mod_sum += mod_l[j];
        }
        int chcnt = mod_sum / div_l[i];
        int opecnt = 0;
        for (int j = mod_l.size() - 1; j >= mod_l.size() - chcnt; j--){
            opecnt += div_l[i] - mod_l[j];
        }
        if(opecnt <= k){
            chmax(ans, div_l[i]);
        }
    }
    cout << ans << endl;
    return 0;
}