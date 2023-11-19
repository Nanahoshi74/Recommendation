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
ll ceil(ll x , ll y){return (x+y-1)/y;}

bool isvalid(ll y,ll x,ll h,ll w){
    if(y >= 0 && x >= 0 && y < h && x < w){
        return true;
    }
    return false;
}

int main(){

    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];
    }

    vector<ll> dy = {-1,-1,0,1,1,1,0,-1};
    vector<ll> dx = {0,1,1,1,0,-1,-1,-1};

    rep(i,n){
        rep(j,n){
            if(s[i][j] == '#'){
                rep(k,8){
                    ll sharp_cnt = 1;
                    ll dot_cnt = 0;
                    bool ok = true;
                    rng(d,1,6){
                        ll ly = i + dy[k] * d;
                        ll lx = j + dx[k] * d;
                        if(isvalid(ly,lx,n,n)){
                            if(s[ly][lx] == '#'){
                                sharp_cnt++;
                            }
                            else{
                                dot_cnt++;
                            }
                        }
                        else{
                            ok = false;
                            break;
                        }
                    }
                    if(ok && dot_cnt <= 2 && sharp_cnt >= 4){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}