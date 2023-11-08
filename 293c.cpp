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
char itoc(int x){return x + '0';}

ll h,w;
ll ans = 0;

void dfs(ll i,ll j,set<ll> &st,vector<vector<ll>> a){
    if(st.count(a[i][j])){
        return;
    }
    else{
        st.insert(a[i][j]);
    }
    if(i == h-1 && j == w-1) ans++;
    if(i != h-1){
        dfs(i+1,j,st,a);
    }
    if(j != w-1){
        dfs(i,j+1,st,a);
    }
    st.erase(a[i][j]);
}

int main(){

    cin >> h >> w;
    vector<vector<ll>> a(h,vector<ll>(w));

    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    set<ll> st;
    dfs(0,0,st,a);

    cout << ans << endl;
    
    return 0;
}