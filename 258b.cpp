#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
//using mint = modint998244353;
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

    ll n;
    cin >> n;
    // vector<vector<ll>> grid(n,vector<ll>(n));
    // rep(i,n){
    //     rep(j,n){
    //         cin >> grid[i][j];
    //     }
    // }
    vector<string> t(n);
    rep(i,n){
        cin >> t[i];
    }

    vector<ll> dx = {1,1,0,-1,-1,-1,0,1};
    vector<ll> dy = {0,-1,-1,-1,0,1,1,1}; 

    ll ans = -1;

    rep(i,n){
        rep(j,n){
            ll li = i,lj = j;
            rep(k,8){
                string s;
                rng(u,0,n){
                    // ll lx = (li + dx[k] * u) % n;
                    // ll ly = (lj + dy[k] * u) % n;
                    ll lx = mod(li + dx[k] * u,n);
                    ll ly = mod(lj + dy[k] * u,n);
                    s += t[lx][ly];
                }
                // cout << s << endl;
                ans = max(ans,stoll(s));
            }
        }
    }

    cout << ans << endl;

    return 0;
}