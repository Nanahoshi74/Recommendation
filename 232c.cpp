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

int main(){

    ll n,m;
    cin >> n >> m;

    // vector<vector<ll>> g1(m),g2(m);
    vector<ll> A(m),B(m),C(m),D(m);
    set<P> st;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        a--,b--;
        A[i] = a;
        B[i] = b;
        // g1[a].push_back(b);
        // g1[b].push_back(a);
    }
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        a--,b--;
        C[i] = a;
        D[i] = b;
        st.insert(P(a,b));
        st.insert(P(b,a));
        // g2[a].push_back(b);
        // g2[b].push_back(a);
    }

    vector<ll> path(n);
    rep(i,n) path[i] = i;

    do{
        map<ll,ll> mp;
        bool ok = true;
        rep(i,n){
            mp[i] = path[i];
        }
        rep(i,m){
            ll a = mp[A[i]];
            ll b = mp[B[i]];
            if(!st.count(P(a,b))){
                ok = false;
            }
        }
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(all(path)));

    cout << "No" << endl;

    return 0;
}