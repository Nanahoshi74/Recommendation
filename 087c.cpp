#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
//using mint = modint998244353;
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


int main(){

    ll n;
    cin >> n;
    vector<vector<ll>> a(2,vector<ll>(n));
    vector<vector<ll>> dp(2,vector<ll>(n));
    rep(i,2){
        rep(j,n){
            cin >> a[i][j];
            dp[i][j] = 0;
        }
    }
    dp[0][0] = a[0][0];
    rep(i,2){
        rep(j,n){
            if(i-1 >= 0 && j-1 >= 0){
                dp[i][j] = max(dp[i-1][j] + a[i][j],dp[i][j-1] + a[i][j]);
            }
            else if(i-1 >= 0){
                dp[i][j] = dp[i-1][j] + a[i][j];
            }
            else if(j-1 >= 0){
                dp[i][j] = dp[i][j-1] + a[i][j];
            }
        }
    }
    cout << dp[1][n-1] << endl;


    return 0;
}