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
    vector<ll> a(n);

    vector<P> pa;
    map<ll,ll> mp;

    rep(i,n){
        cin >> a[i];
        mp[a[i]]++;
    }

    ll ans = 1;
    ll cnt = 0;

    while(!mp.empty()){
        ll len = mp.rbegin() -> first;
        ll num = mp.rbegin() -> second;
        mp.erase(len);
        ll prev_ans = ans;
        if(num >= 4){
            ans = max(ans,len*len);
            cnt += 2;
        }
        if(num >= 2){
            cnt++;
            ans = max(ans,prev_ans*len);
        }
        if(cnt >= 2){
            cout << ans << endl;
            return 0;
        }
    }

    if(cnt < 2) cout << 0 << endl;
    else cout << ans << endl;




    return 0;
}