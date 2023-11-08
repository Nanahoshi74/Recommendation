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
ll inttoc(ll x){return x + '0';}

bool isvalid(int x, int y, int H, int W) {
    if(0 <= x && x < H && 0 <= y && y < W) {return true;}
    else {return false;}
}


int main(){

    ll h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h){
        cin >> s[i];
    }
    vector<vector<char>> ans(h,vector<char>(w));
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '.'){
                ll p = 0;
                if(isvalid(i,j-1,h,w)){
                    if(s[i][j-1] == '#'){
                        p++;
                    }
                }
                if(isvalid(i-1,j-1,h,w)){
                    if(s[i-1][j-1] == '#'){
                        p++;
                    }
                }
                if(isvalid(i-1,j,h,w)){
                    if(s[i-1][j] == '#'){
                        p++;
                    }
                }
                if(isvalid(i-1,j+1,h,w)){
                    if(s[i-1][j+1] == '#'){
                        p++;
                    }
                }
                if(isvalid(i,j+1,h,w)){
                    if(s[i][j+1] == '#'){
                        p++;
                    }
                }
                if(isvalid(i+1,j+1,h,w)){
                    if(s[i+1][j+1] == '#'){
                        p++;
                    }
                }
                if(isvalid(i+1,j,h,w)){
                    if(s[i+1][j] == '#'){
                        p++;
                    }
                }
                if(isvalid(i+1,j-1,h,w)){
                    if(s[i+1][j-1] == '#'){
                        p++;
                    }
                }
                char c = p + '0';
                ans[i][j] = c;
            }
            else{
                ans[i][j] = '#';
            }
        }
    }
    rep(i,h){
        rep(j,w){
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}