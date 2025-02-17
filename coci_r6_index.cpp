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

const ll sm = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int N = 2e5 + 5;

struct qr
{
    int l, r, id;
    bool operator <(qr const&a ) const
    {
        if(l/BLOCK != a.l/BLOCK) return l/BLOCK < a.l/BLOCK;
        return r < a.r;
    }
};
int n, q;
int p[N];
qr Q[N];
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> p[i];
    fr(i, 1, q) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
    }
}
namespace sub1
{
    ll st[4*N], res[N];
    int bit[N];

    int lim = 2e5 + 2;
//    void upd(int pos, ll      val)
//    {
//        int id = 1, l = 1, r = lim;
//        while(l < r) {
//            int mid = (r + l) >> 1;
//            if(pos <= mid) id = id << 1, r = mid;
//            else id = id << 1 | 1, l = mid + 1;
//        }
//
//        st[id] += val;
//        while(id > 1) {
//            id >>= 1;
//            st[id] = st[id << 1] + st[id << 1 | 1];
//        }
//    }
//    ll get(int id, int l, int r, int u, int v)
//    {
//        if(r < u || v < l) return 0;
//        if(u <= l & r <= v) return st[id];
//        int mid = (r + l) >> 1;
//        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
//    }
    void upd(int x, int v)
    {
        for(; x <= lim; x += x&-x) bit[x] += v;
    }
    int get(int x)
    {
        ll res = 0;
        for(; x >= 1; x -= x&-x) res += bit[x];
        return res;
    }
    int get(int l, int r)
    {
        return get(r) - get(l - 1);
    }
    void add(int x) {
        upd(p[x], 1);
    }
    void del(int x) {
        upd(p[x], -1);
    }
    bool check(int x)
    {
//        return get(1, 1, lim, x, lim) >= x;
        return get(x, lim) >= x;
    }
    void slv()
    {
        sort(alla(Q, q));
        int l = Q[1].l, r = Q[1].r;
//        fr(i, 1, n) cout << p[i] << " "; cout << el;
        fr(i, l, r) add(i);
//        cout << el; fr(i, 1, q) {
//            cout << Q[i].l << " " << Q[i].r << el;
//        } cout << el;
//        cout << get(5, lim); return;
        fr(i, 1, q) {
            while(r < Q[i].r) add(++r);
            while(l > Q[i].l) add(--l);
            while(r > Q[i].r) del(r--);
            while(l < Q[i].l) del(l++);

            int low = 1, high = r - l + 1, mid, ans = 0;
            while(low <= high) {
                mid = (low + high) >> 1;
                if(check(mid)) {
                    ans = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            res[Q[i].id] = ans;
        }
        fr(i, 1, q) cout << res[i] << el;
    }
}
namespace sub2
{
    int cnt[N];
    bool check(int val, int x, int y)
    {
        int d = 0;
        fr(i, x, y) {
            if(p[i] >= val) d++;
        }
        return d >= val;
    }
    void slv()
    {
        fr(id, 1, q) {
            int x = Q[id].l, y = Q[id].r;
            int l = 1, r = y - x + 1, mid, ans = 0;
            while(l <= r) {
                mid = (r + l) >> 1;
                if(check(mid, x, y)) {
                    ans = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            cout << ans << el;
        }
    }
}
namespace sub3
{

    void slv()
    {

    }
}
main()
{
    #define TASK "task"
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


