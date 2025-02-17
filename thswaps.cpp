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
const int BLOCK = 500;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int N = 250005;
int n, a[N], q;
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
    cin >> q;
}
//namespace sub1
//{
//    const int MAX = 5e4 + 2;
//    int lim = 5e4;
//    ll res = 0;
//
//    ll bit[505][MAX + 10];
//
//    void upd(int id, int x, int v)
//    {
//        for(; x <= lim; x += x & -x) bit[id][x] += v;
//    }
//    ll get(int id, int x)
//    {
//        int res = 0;
//        for(; x >= 1; x -= x & -x) res += bit[id][x];
//        return res;
//    }
//    ll get(int id, int l, int r)
//    {
//        return get(id, r) - get(id, l - 1);
//    }
//    ll calc(int pos)
//    {
//            int l = 1 / BLOCK, r = (pos - 1) / BLOCK;
//
//            ll ans = 0;
//            if(l == r) {
//                fr(i, 1, pos - 1) if(a[i] > a[pos]) ans++;
//            }
//            else {
//                fr(id, l + 1, r - 1) {
//                    ans += get(id, a[pos] + 1, lim);
//                }
//                fr(id, 1, (l + 1) * BLOCK - 1) if(a[id] > a[pos]) ans++;
//                fr(id, r * BLOCK, pos - 1) if(a[id] > a[pos]) ans++;
//            }
//
//            l = (pos + 1) / BLOCK, r = n / BLOCK;
//            if(l == r) {
//                fr(i, pos + 1, n) if(a[pos] > a[i]) ans++;
//            }
//            else{
//                fr(id, l + 1, r - 1) ans += get(id, 1, a[pos] - 1);
//                fr(id, pos + 1, (l + 1) * BLOCK - 1) if(a[pos] > a[id]) ans++;
//                fr(id, r * BLOCK, n) if(a[pos] > a[id]) ans++;
//            }
//
//            return ans;
//    }
//    void slv()
//    {
//
//        fr(i, 1, n) {
//            res += get(n / BLOCK + 1, a[i] + 1, lim), upd(n / BLOCK + 1, a[i], 1);
//            upd(i / BLOCK, a[i], 1);
//        }
//        int x, y;
//        while(q--) {
//            cin >> x >> y;
//
//            int id = x / BLOCK;
//
//            res = res - calc(x);
//            upd(id, a[x], -1);
//            upd(id, y, 1);
//            a[x] = y;
//            res += calc(x);
//            cout << res << el;
//        }
//    }
//}
//namespace sub2
//{
//    const int MAX = 5e4 + 2;
//    int lim = 5e4;
//    ll res = 0;
//
//    ll bit[MAX];
//
//    void upd(int x, int v)
//    {
//        for(; x <= lim; x += x & -x) bit[x] += v;
//    }
//    int get(int x)
//    {
//        int cnt = 0;
//        for(; x >= 1; x -= x & -x) cnt += bit[x];
//        return cnt;
//    }
//    int get(int l, int r)
//    {
//        return get(r) - get(l - 1);
//    }
//    void slv()
//    {
//
//        while(q--) {
//            int x, y;
//            cin >> x >> y;
//            a[x] = y;
//            int res = 0;
//            fr(i, 1, lim) bit[i] = 0;
//            fr(i, 1, n) {
//                res += get(a[i] + 1, lim);
//                upd(a[i], 1);
//            }
//            cout << res << el;
//        }
//    }
//}
namespace sub3
{
    const int MAX = 5e4 + 2;

    struct FW
    {
        ll bit[MAX];
        void upd(int x, int v)
        {
            for(; x >= 1; x -= x & -x) bit[x] += v;
        }
        ll get(int x)
        {
            int ans = 0;
            for(; x <= 5e4; x += x & -x) ans += bit[x];
            return ans;
        }
    } BIT[505];

    ll res = 0;
    void slv()
    {
        fr(i, 1, n) {
            res += BIT[n / BLOCK + 1].get(a[i] + 1), BIT[n / BLOCK + 1].upd(a[i], 1);

            BIT[i / BLOCK].upd(a[i], 1);
        }
        int x, val;
        while(q-- ){
            cin >> x >> val;
            int id = x / BLOCK;
            int l = id * BLOCK, r = min(n, (id + 1) * BLOCK - 1);

            fr(i, 0, id - 1) res = res + BIT[i].get(val + 1) - BIT[i].get(a[x] + 1);
            fr(i, id + 1, n / BLOCK) res = res - BIT[i].get(val) + BIT[i].get(a[x]);
            fr(i, l, x - 1) res += (a[i] > val) - (a[i] > a[x]);
            fr(i, x + 1, r) res += (val > a[i]) - (a[x] > a[i]);
            BIT[id].upd(a[x], -1), BIT[id].upd(val, 1);
            a[x] = val;
            cout << res << el;
        }
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
        sub3::slv();
    //    sub2::slv();
    }
}


