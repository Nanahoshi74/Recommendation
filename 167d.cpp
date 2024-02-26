#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
//using mint = modint1000000007;
// using mint = modint;  /*このときmint::set_mod(mod)のようにしてmodを底にする*/
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i = a; i <= (ll)(b); i++)
#define rng(i,a,b) for(ll i = a; i < (ll)(b); i++)
#define rrng(i,a,b) for(ll i = a; i >= (ll)(b); i--)
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define si(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define ret(x) { cout<<(x)<<endl;}
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
ll ceilLL(ll x , ll y){return (x+y-1)/y;}


int main(){

    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<vector<ll>> g(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
        g[i].push_back(a[i]);
    }

    ll z = -1;

    vector<bool> seen(n, false);
    auto dfs = [&](auto dfs, ll v) -> void{
        if(seen[v]){
            z = v;
            return;
        }
        seen[v] = true;
        for(auto next_v : g[v]){
            dfs(dfs, next_v);
        }
    };

    dfs(dfs, 0);
    // cout << z << endl;
    seen.assign(n, false);
    ll cycle_size = 0;

    auto cnt_roop_size = [&](auto cnt_roop_size, ll v) -> void{
        if(seen[v]){
            return;
        }
        cycle_size++;
        seen[v] = true;
        for(auto next_v : g[v]){
            cnt_roop_size(cnt_roop_size, next_v);
        }
    };

    if(z != -1) cnt_roop_size(cnt_roop_size, z);
    // cout << cycle_size << endl;

    auto bfs = [&](ll s) -> vector<ll>{
        vector<ll> distance(n, -1);
        queue<ll> q;
        distance[s] = 0;
        q.push(s);
        while(!q.empty()){
            ll v = q.front();
            q.pop();
            for(auto next_v : g[v]){
                if(distance[next_v] != -1){
                    continue;
                }
                distance[next_v] = distance[v] + 1;
                q.push(next_v);
            }
        }
        return distance;
    };
    vector<ll> dist = bfs(0); 
    // print(dist);

    // cout << z << endl;
    // cout << cycle_size << endl;

    if(z != -1){
        if(k < dist[z]){
            rep(i,si(dist)){
            if(dist[i] == k){
                cout << i + 1 << endl;
                return 0;
            }
        }
        }
        k -= dist[z];
        k %= cycle_size;
        // cout << k << endl;
        // cout << z << endl;
        vector<ll> dist2 = bfs(z);
        // print(dist2);
        rep(i,si(dist2)){
            if(dist2[i] == k){
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    else{
        rep(i,si(dist)){
            if(dist[i] == k){
                cout << i + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}