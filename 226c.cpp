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
    vector<ll> t(n);
    vector<vector<ll>> g(n);
    rep(i,n){
        ll k;
        cin >> t[i] >> k;
        ll a;
        rep(j,k){
            cin >> a;
            a--;
            g[i].push_back(a);
        }
    }

    vector<bool> seen(n,false);
    vector<ll> ans;
    auto dfs = [&](auto dfs,ll v) -> void{
        seen[v] = true;
        for(auto next_v : g[v]){
            if(seen[next_v]){
                continue;
            }
            else{
                dfs(dfs,next_v);
            }
        }
        ans.push_back(v);
    };
    dfs(dfs,n-1);
    ll u = ans[si(ans)-1];
    ans.pop_back();
    reverse(all(ans));
    ans.push_back(u);

    ll time = 0;
    rep(i,si(ans)){
        time += t[ans[i]];
    }

    cout << time << endl;

    return 0;
}