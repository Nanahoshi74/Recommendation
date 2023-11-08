#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
//using mint = modint998244353;
using mint = modint1000000007;
// using mint;  /*このときmint::set_mod(mod)のようにしてmodを底にする*/
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = a; i <= (int)(b); i++)
#define rng(i,a,b) for(int i = a; i < (int)(b); i++)
#define rrng(i,a,b) for(int i = a; i >= (int)(b); i--)
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define si(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ret(x) { cout<<(x)<<endl;}
typedef long long ll;
using namespace std;
using P = pair<ll,ll>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
ll mul(ll a, ll b) { if (a == 0) return 0; if (LINF / a < b) return LINF; return min(LINF, a * b); }
ll mod(ll x, ll y){return (x % y + y) % y;}
char itoc(int x){return x + '0';}
int ctoi(char c){return c - '0';}

int main(){

    string s;
    cin >> s;
    mint ans = 0;

    ll n = si(s);
    string t = "chokudai";
    ll t_len = si(t);

    vector<vector<mint>> dp(n+100,vector<mint>(t_len,0));

    if(s[0] == 'c'){
        dp[0][0] = 1;
    }
    else{
        dp[0][0] = 0;
    }

    rng(i,1,n){
        rep(j,t_len){
            if(s[i] == t[j]){
                if(j-1 >= 0) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j] + 1;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    cout << dp[n-1][7].val() << endl;

    return 0;
}