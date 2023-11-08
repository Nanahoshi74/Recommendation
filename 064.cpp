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
    unordered_set<ll> st;
    ll num = 0;
    rep(i,n){
        cin >> a[i];
        if(a[i] <= 399){
            st.insert(0);
        }
        else if(a[i] <= 799){
            st.insert(1);
        }
        else if(a[i] <= 1199){
            st.insert(2);
        }
        else if(a[i] <= 1599){
            st.insert(3);
        }
        else if(a[i] <= 1999){
            st.insert(4);
        }
        else if(a[i] <= 2399){
            st.insert(5);
        }
        else if(a[i] <= 2799){
            st.insert(6);
        }
        else if(a[i] <= 3199){
            st.insert(7);
        }
        else{
            num++;
        }
    }

    ll mi = si(st) == 0 ? 1 : si(st);

    cout << mi << " " << si(st) + num << endl;



    return 0;
}