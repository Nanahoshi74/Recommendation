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
    vector<P> pa(n);
    rep(i,n){
        cin >> pa[i].first >> pa[i].second;
    }

    sort(all(pa));

    vector<P> ans;

    ll left = pa[0].first, right = pa[0].second;
    if(n == 1){
        ans.emplace_back(left,right);
    }

    rng(i,1,n){
        if(pa[i].first > right){
            ans.emplace_back(left,right);
            if(i == n-1){
                ans.emplace_back(pa[i].first,pa[i].second);
            }
            else{
                left = pa[i].first;
                right = pa[i].second;
            }
        }
        else{
            right = max(right,pa[i].second);
            if(i == n-1){
                ans.emplace_back(left,right);
            }
        }
    }

    rep(i,si(ans)){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}