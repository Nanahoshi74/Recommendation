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
ll getnum(ll x, ll y, ll H, ll W) { return (x * W + y);}

int main(){

    ll h,w;
    cin >> h >> w;

    vector<string> c(h);
    rep(i,h){
        cin >> c[i];
    }

    vector<vector<ll>> dist(h+1,vector<ll>(w+1,0));

    rrng(i,h-1,0){
        rrng(j,w-1,0){
            if(c[i][j] == '#') continue;
            else{
                dist[i][j] = max(dist[i+1][j],dist[i][j+1])+1;
            }
        }
    }

    cout << dist[0][0] << endl;

   
    return 0;
}