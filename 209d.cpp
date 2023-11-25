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

    ll n,q;
    cin >> n >> q;
    
    vector<vector<ll>> g(n);
    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> dist(n,-1);
    queue<ll> qe;
    qe.push(0);
    dist[0] = 0;
    while(!qe.empty()){
        ll v = qe.front();
        qe.pop();
        for(auto next_v : g[v]){
            if(dist[next_v] != -1){
                continue;
            }
            else{
                qe.push(next_v);
                dist[next_v] = dist[v] + 1;
            }
        }
    }

    rep(i,q){
        ll a,b;
        cin >> a >> b;
        a--,b--;
        if(abs(dist[a]-dist[b]) % 2 == 0){
            cout << "Town" << endl;
        }
        else{
            cout << "Road" << endl;
        }
    }

    return 0;
}