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

    vector<vector<ll>> a(3,vector<ll>(3));
    rep(i,3){
        rep(j,3){
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> grid(3,vector<ll>(2));
    rep(i,3){
        rep(j,2){
            grid[i][j] = INF;
        }
    }
    rep(i,3){
        rep(j,3){
            grid[i][0] = min(a[i][j],grid[i][0]);
        }
    }

    rep(j,3){
        rep(i,3){
            grid[j][1] = min(a[i][j],grid[j][1]);
        }
    }

    rep(i,3){
        ll p = grid[i][0];
        vector<ll> g(3);
        rep(j,3){
            g[j] = a[i][j]-p;
            if(g[j] > grid[j][1]){
                cout << "No" << endl;
                return 0;
            }
        }
        rep(k,3){
            if(k == i) continue;
            else{
                ll z = grid[k][0];
                rep(j,3){
                    if(z + g[j] < a[k][j]){
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }

    }

    cout << "Yes" << endl;

    return 0;
}