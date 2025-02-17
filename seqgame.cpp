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

const int N = 2e5 + 2;
int n, q;
void input()
{
    cin >> n >> q;
}
namespace sub1
{

    struct qr
    {
        int x, y, w;
    };
    qr Q[N];

    ll st[8*N], lz[8*N];

    void down(int id, int l, int mid, int r)
    {
        if(lz[id]) {
            ll val = lz[id];
            st[id << 1] += val;
            st[id << 1 | 1] += val;
            lz[id << 1] += val;
            lz[id << 1 | 1] += val;
            lz[id] = 0;
        }
    }
    void upd(int id, int l, int r, int u, int v, int val)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            st[id] += val;
            lz[id] += val;
            return;
        }
        int mid = (r + l) >> 1;
        down(id, l, mid, r);
        upd(id << 1, l, mid, u, v, val);
        upd(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }
    ll get(int id, int l, int r, int u, int v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (r + l) >> 1;
        down(id, l, mid, r);
        return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
    void slv()
    {
        fr(i, 1, q) {
            cin >> Q[i].x >> Q[i].y >> Q[i].w;
        }
        fr(i, 1, q) upd(1, 1, n, Q[i].x, Q[i].y, Q[i].w);

        ll ans = inf;
        for(int i = 1; i <= q; i++) {
            int x = Q[i].x, y = Q[i].y, w = Q[i].w;

            upd(1, 1, n, x, y, -w);
            mini(ans, get(1, 1, n, 1, n));
            upd(1, 1, n, x, y, w);
        }

        cout << ans;
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


