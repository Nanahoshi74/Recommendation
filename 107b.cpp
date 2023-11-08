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

ll h,w;
vector<string> s(1000);


int check(){
        rep(i,h){
        bool ok = false;
        rep(j,w){
            if(s[i][j] == '#'){
                ok = true;
            }
        }
        if(!ok){
            rng(j,i+1,h){
                swap(s[j-1],s[j]);
            }
            h--;
            return 1;
        }
    }

    rep(j,w){
        bool ok = false;
        rep(i,h){
            if(s[i][j] == '#'){
                ok = true;
            }
        }
        if(!ok){
            rep(i,h){
                s[i] = s[i].substr(0,j) + s[i].substr(j+1);
            }
            w--;
            return 1;
        }
    }
    return 0;
}

int main(){

    // ll h,w;
    cin >> h >> w;
    // vector<string> s(h);
    rep(i,h){
        cin >> s[i];
    }
    while(check());
    rep(i,h){
        cout << s[i] << endl;
    }
 
    return 0;
}