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
ll n, a[N], q;
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    const int block = 500;
    ll sum[block];
    void slv()
    {
        fr(i, 1, n) {
            int id = i / block;
            sum[id] += a[i];
        }
        int x, y, k;
        while(q--) {
            cin >> k >> x >> y;
            if(k == 1) {
                int pos = x / block;
                sum[pos] += y - a[x];
                a[x] = y;
            }
            else {
                int l = x / block, r = y / block;
                ll ans = 0 ;
                if(l == r) {
                    fr(i, x, y) ans += a[i];
                }
                else {
                    fr(i, l + 1, r - 1) ans += sum[i];
                    fr(i, x, (l + 1) * block - 1) ans += a[i];
                    fr(i, r * block, y) ans += a[i];

                }
                cout << ans << el;
            }
        }
    }
}
namespace sub2
{
    ll st[4*N];
    void upd(int id, int l, int r, int i, int val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            st[id] += val;
            return;
        }
        int mid = (r + l) >> 1;
        upd(id << 1, l, mid,i, val);
        upd(id << 1 | 1, mid + 1, r, i, val);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }
    ll get(int id, int l, int r, int u, int v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (r + l) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
    void slv()
    {
        fr(i, 1, n) upd(1, 1, n, i, a[i]);
        int x, y, k;
        while(q--) {
            cin >> k >> x >> y;
            if(k == 1) {
                upd(1, 1, n, x, y - a[x]);
                a[x] = y;
            }
            else {
                cout << get(1, 1, n, x, y) << el;
            }
        }
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


