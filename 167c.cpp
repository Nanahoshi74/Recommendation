#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
//using mint = modint1000000007;
// using mint = modint;  /*このときmint::set_mod(mod)のようにしてmodを底にする*/
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
void chmin(ll& x,ll y){x = min(x,y);}
void chmax(ll& x,ll y){x = max(x,y);}
ll getnum(ll x, ll y, ll H, ll W) { (void) H; return (x * W + y);}
template<typename T>
void print(vector<T> &p){rep(i,si(p)) cout << p[i] << " "; cout << endl;}


int main(){

    ll n,m,x;
    cin >> n >> m >> x;
    vector<ll> c(n);
    vector<vector<ll>> a(n,vector<ll>(m));
    rep(i,n){
        cin >> c[i];
        rep(j,m){
            cin >> a[i][j];
        }
    }

    ll ans = INF;

    rep(i,1 << n){
        vector<ll> cnt(m,0);
        ll cost = 0;
        rep(j,n){
            if(i & (1 << j)){
                cost += c[j];
                rep(k,m){
                    cnt[k] += a[j][k];
                }
            }
        }
        bool ok = true;
        rep(j,m){
            if(cnt[j] < x){
                ok = false;
                break;
            }
        }
        if(ok){
            chmin(ans,cost);
        }
    }

    if(ans == INF){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }

    return 0;
}