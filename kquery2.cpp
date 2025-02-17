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
const ll BLOCK = 500;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int N = 3e4 + 2;
int n, a[N], q;
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
    cin >> q;
}
namespace sub1
{
    const int MAX = 1e4 + 5;
    int bit[BLOCK][MAX];
    int lim = 1e4;
    void upd(int id, int x, int v)
    {
        for(; x <= lim; x += x & -x) bit[id][x] += v;
    }
    int get(int id, int x)
    {
        int ans = 0;
        for(; x >= 1; x -= x & -x) ans += bit[id][x];
        return ans;
    }
    int get(int id, int l, int r)
    {
        return get(id, r) - get(id, l - 1);
    }
    void slv()
    {

        fr(i, 1, n) {
            int id = i / BLOCK;
            upd(id, a[i], 1);
        }

        int k, x, y, val;
        while(q--) {
            cin >> k >> x >> y;
            if(!k) {
                int id = x / BLOCK;
                upd(id, a[x], -1);
                upd(id, y, 1);
                a[x] = y;
            }
            else {
                cin >> val;
                int l = x / BLOCK, r = y / BLOCK, ans = 0;
                if(l == r) {
                    fr(i, x, y) if(a[i] > val) ans++;
                }
                else {
                    fr(id, l + 1, r - 1) ans += get(id, val + 1, lim);
                    fr(i, x, (l + 1) * BLOCK - 1) if(a[i] > val) ans++;
                    fr(i, r * BLOCK, y) if(a[i] > val) ans++;
                }
                cout << ans << el;
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


