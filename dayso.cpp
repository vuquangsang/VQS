/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     Mask(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     REP(i, a, b) for(int i = (a), _b = (b); i < _b; i++)

const ll MN = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int MAX = 2e5 + 2;
int n, MOD, q, a[MAX];
void input()
{
    cin >> n >> MOD >> q;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    struct mer
    {
        ll val;
        bool ok;
    };
    const int MAX = 1e6 + 2;
    mer t[MAX];
    ll lazy[MAX];
    mer MERGE(mer a, mer b)
    {
        if(a.val == -inf && a.ok == 0) return b;
        swap(a, b);
        if(a.val == -inf && a.ok == 0) return b;
        if(a.ok && b.ok && a.val == b.val) {
            return {a.val, 1};
        }
        return {a.val, 0};
    }
    void build(ll id, ll l, ll r)
    {
        if(l == r) {
            t[id] = {a[l], 1};
            return;
        }
        int m = (r + l) >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        t[id] = MERGE(t[id << 1], t[id << 1 | 1]);
    }
    void down(ll id)
    {

        if(lazy[id]) {
            ll val = lazy[id];
            (t[id << 1].val+=val)%=MOD;
            (t[id << 1 | 1].val+=val)%=MOD;

            (lazy[id << 1]+=val)%=MOD;
            (lazy[id << 1 | 1]+=val)%=MOD;
            lazy[id] = 0;
        }
    }
    void upd(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            (t[id].val+=val)%=MOD;
//            cout << MOD << el;
//            cout << u << " " << v << " " << t[id].val << " " << t[id].ok << el;
            (lazy[id]+=val)%=MOD;
            return;
        }
        int m = (r + l) >> 1;
        down(id);
        upd(id << 1, l, m, u, v, val);
        upd(id << 1 | 1, m + 1, r, u, v, val);
        t[id] = MERGE(t[id << 1], t[id << 1 | 1]);
    }
    mer get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return {-inf, 0};
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        down(id);
        return MERGE(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
    void slv()
    {
        int k, l, r, c;
        build(1, 1, n);
//        upd(1, 1, n, 2, 2, 1);
        mer tmp = get(1, 1, n, 1, 4);
//        cout << tmp.val << " " << tmp.ok; return;
        while(q--) {
            cin >> k >> l >> r;
            if(k == 1){
                cin >> c;
                upd(1, 1, n, l, r, c);
            }
            else {
                bool ok = get(1, 1, n, l, r).ok;
                cout << !ok << el;
            }
        }
    }
}
namespace sub2
{
    void slv()
    {

    }
}

main()
{
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    bool qs = 0;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}


