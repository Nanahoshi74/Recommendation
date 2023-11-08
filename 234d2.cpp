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

template<class VAL> struct RBST {
    VAL SUM_UNITY = 0;                              // to be set

    unsigned int randInt() {
        static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
        unsigned int tt = (tx ^ (tx << 11));
        tx = ty; ty = tz; tz = tw;
        return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
    }

    struct NODE {
        NODE *left, *right;
        VAL val;                        // the value of the node
        int size;                       // the size of the subtree 
        VAL sum;                        // the value-sum of the subtree

        NODE() : val(SUM_UNITY), size(1), sum(SUM_UNITY) {
            left = right = NULL;
        }

        NODE(VAL v) : val(v), size(1), sum(v) {
            left = right = NULL;
        }

        /* additional update */
        inline void update() {

        }

        /* additional lazy-propagation */
        inline void push() {

            /* ex: reverse */
            /*
            if (this->rev) {
            swap(this->left, this->right);
            if (this->left) this->left->rev ^= true;
            if (this->right) this->right->rev ^= true;
            this->rev = false;
            }
            */
        }
    };


    ///////////////////////
    // root
    ///////////////////////

    NODE* root;
    RBST() : root(NULL) { }
    RBST(NODE* node) : root(node) { }


    ///////////////////////
    // basic operations
    ///////////////////////

    /* size */
    inline int size(NODE *node) {
        return !node ? 0 : node->size;
    }
    inline int size() {
        return this->size(this->root);
    }

    /* sum */
    inline VAL sum(NODE *node) {
        return !node ? SUM_UNITY : node->sum;
    }
    inline VAL sum() {
        return this->sum(this->root);
    }

    /* update, push */
    inline NODE* update(NODE *node) {
        node->size = size(node->left) + size(node->right) + 1;
        node->sum = sum(node->left) + sum(node->right) + node->val;
        node->update();
        return node;
    }

    inline void push(NODE *node) {
        if (!node) return;
        node->push();
    }

    /* lower_bound */
    inline int lowerBound(NODE *node, VAL val) {
        push(node);
        if (!node) return 0;
        if (val <= node->val) return lowerBound(node->left, val);
        else return size(node->left) + lowerBound(node->right, val) + 1;
    }
    inline int lowerBound(VAL val) {
        return this->lowerBound(this->root, val);
    }

    /* upper_bound */
    inline int upperBound(NODE *node, VAL val) {
        push(node);
        if (!node) return 0;
        if (val >= node->val) return size(node->left) + upperBound(node->right, val) + 1;
        else return upperBound(node->left, val);
    }
    inline int upperBound(VAL val) {
        return this->upperBound(this->root, val);
    }

    /* count */
    inline int count(VAL val) {
        return upperBound(val) - lowerBound(val);
    }

    /* get --- k: 0-index */
    inline VAL get(NODE *node, int k) {
        push(node);
        if (!node) return -1;
        if (k == size(node->left)) return node->val;
        if (k < size(node->left)) return get(node->left, k);
        else return get(node->right, k - size(node->left) - 1);
    }
    inline VAL get(int k) {
        return get(this->root, k);
    }


    ///////////////////////
    // merge-split
    ///////////////////////

    NODE* merge(NODE *left, NODE *right) {
        push(left);
        push(right);
        if (!left || !right) {
            if (left) return left;
            else return right;
        }
        if (randInt() % (left->size + right->size) < left->size) {
            left->right = merge(left->right, right);
            return update(left);
        }
        else {
            right->left = merge(left, right->left);
            return update(right);
        }
    }
    void merge(RBST add) {
        this->root = this->merge(this->root, add.root);
    }
    pair<NODE*, NODE*> split(NODE* node, int k) { // [0, k), [k, n)
        push(node);
        if (!node) return make_pair(node, node);
        if (k <= size(node->left)) {
            pair<NODE*, NODE*> sub = split(node->left, k);
            node->left = sub.second;
            return make_pair(sub.first, update(node));
        }
        else {
            pair<NODE*, NODE*> sub = split(node->right, k - size(node->left) - 1);
            node->right = sub.first;
            return make_pair(update(node), sub.second);
        }
    }
    RBST split(int k) {
        pair<NODE*, NODE*> sub = split(this->root, k);
        this->root = sub.first;
        return RBST(sub.second);
    }


    ///////////////////////
    // insert-erase
    ///////////////////////

    void insert(const VAL val) {
        pair<NODE*, NODE*> sub = this->split(this->root, this->lowerBound(val));
        this->root = this->merge(this->merge(sub.first, new NODE(val)), sub.second);
    }

    void erase(const VAL val) {
        if (!this->count(val)) return;
        pair<NODE*, NODE*> sub = this->split(this->root, this->lowerBound(val));
        this->root = this->merge(sub.first, this->split(sub.second, 1).second);
    }


    ///////////////////////
    // debug
    ///////////////////////

    void print(NODE *node) {
        if (!node) return;
        push(node);
        print(node->left);
        cout << node->val << " ";
        print(node->right);
    }
    void print() {
        cout << "{";
        print(this->root);
        cout << "}" << endl;
    }
};

int main(){

    ll n,k;
    cin >> n >> k;
    vector<ll> p(n);
    RBST<ll> S;
    rep(i,n){
        cin >> p[i];
        p[i] *= -1;
    }
    rep(i,k){
        S.insert(p[i]);
    }
    cout << -S.get(k-1) << endl;
    rng(i,k,n){
        S.insert(p[i]);
        cout << -S.get(k-1) << endl;
    }


    return 0;
}