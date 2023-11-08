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

    ll n,q;
    cin >> n >> q;
    vector<ll> x(q);
    vector<ll> ans(n+1);
    rep(i,q){
        cin >> x[i];
    }
    map<ll,ll> mp;
    rng(i,1,n+1){
        mp[i] = i;
        ans[i] = i;
    }

    rep(i,q){
        ll num = x[i];
        ll ind = mp[num];
        if(ind == n){
            ll u = ans[ind-1];
            swap(ans[ind],ans[ind-1]);
            mp[num] = ind-1;
            mp[u] = ind;
        }
        else{
            ll u = ans[ind+1];
            swap(ans[ind],ans[ind+1]);
            mp[num] = ind+1;
            mp[u] = ind;
        }
    }

    rng(i,1,n+1){
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}