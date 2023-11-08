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

    ll x,a,d,n;
    cin >> x >> a >> d >> n;

    ll la = a;

    ll ln = a + (n-1)*d;
    if(a > ln){
        swap(a,ln);
    }

    if(x < a){
        cout << abs(a-x) << endl;
        return 0;
    }
    else if(x > ln){
        cout << abs(ln-x) << endl;
        return 0;
    }
    else if(d == 0){
        cout << abs(a-x) << endl;
        return 0;
    }
    a = la;
    rep(i,abs(d)+1){
        ll lx = x + i;
        ll llx = x - i;
        ll v = -d+a;
        // if((lx + (-v)) % d == 0){
        //     cout << i << endl;
        //     return 0;
        // }
        if((mod(lx + (-v),d)) == 0){
            cout << i << endl;
            return 0;
        }
        // if((llx + (-v)) % d == 0){
        //     cout << i << endl;
        //     return 0; 
        // }
        if(mod(llx + (-v),d) == 0){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}