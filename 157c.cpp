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

    ll n,m;
    cin >> n >> m;
    vector<ll> s(m),c(m);
    rep(i,m){
        cin >> s[i] >> c[i];
    }
    set<ll> st;
    if(n == 1){
        rep(i,10){
            bool ok = true;
            rep(j,m){
                if(s[j] == 1){
                    if(c[j] != i){
                        ok = false;
                    }
                }
            }
            if(ok){
                st.insert(i);
            }
        }
    }
    else if(n == 2){
        rng(i,1,10){
            rep(j,10){
                bool ok = true;
                rep(k,m){
                    if(s[k] == 1){
                        if(c[k] != i){
                            ok = false;
                        }
                    }
                    else if(s[k] == 2){
                        if(c[k] != j){
                            ok = false;
                        }
                    }
                }
                if(ok){
                    st.insert(10 * i + j);
                }
            }
        }
    }
    else{
        rng(i,1,10){
            rep(j,10){
                rep(k,10){
                    bool ok = true;
                    rep(u,m){
                        if(s[u] == 1){
                            if(c[u] != i){
                                ok = false;
                            }
                        }
                        else if(s[u] == 2){
                            if(c[u] != j){
                                ok = false;
                            }
                        }
                        else{
                            if(c[u] != k){
                                ok = false;
                            }
                        }
                    }
                    if(ok){
                        st.insert(100 * i + 10 * j + k);
                    }
                }
            }
        }
    }
    
    if(si(st) == 0){
        cout << -1 << endl;
    }
    else{
        cout << *st.begin() << endl;
    }

    return 0;
}