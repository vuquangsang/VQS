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

const int N = 2e6 + 2;
int n, a[N], p;
void input()
{
    cin >> n >> p;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    ll st[4 * N];
    ll pre[N];
    void upd(int pos, ll val)
    {
        int l = 1, r = n, id = 1;
        while(l < r) {
            int mid = (r + l) >> 1;
            if(pos <= mid) id = id << 1, r = mid;
            else id = id << 1 | 1, l = mid + 1;
        }
        st[id] = val;
        while(id > 1) {
            id >>= 1;
            st[id] = min(st[id << 1], st[id << 1 | 1]);
        }
    }
    int walk(int id, int l, int r, int u, int v, ll val)
    {
        if(r < u || v < l  || st[id] > val) return -1;
        if(l == r) return l;
        int mid = (r + l) >> 1;
        int res = walk(id << 1, l, mid, u, v, val);
        if(res == -1) res = walk(id << 1 | 1, mid + 1, r, u, v, val);
        return res;
    }
    void slv()
    {
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];
        int res = -1;
        fr(i, 1, n ){
            upd(i, pre[i - 1]);
            int pos = walk(1, 1, n, 1, i, pre[i] - p);
            if(pos != -1) maxi(res, i - pos + 1);
        }
        cout << res;
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

    cerr << "\nTime" << " " << 0.001 * clock() << "s ";
    return 0;
}


