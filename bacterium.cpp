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

const int N = 3e5 + 2;
int n;
struct bar
{
    int x, y;
};
bar a[N];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i].x >> a[i].y;
}
namespace sub1
{

    int pos[N];
    void slv()
    {
        sort(a + 1, a + n + 1, [](bar a, bar b){return a.x < b.x;} );
//        cout << el; fr(i, 1, n){
//            cout << a[i].x << " " << a[i].y << el;
//        } cout << el;
        int res = 0, tmp = 0;
        fr(i, 1, n) {
            int p = a[i].y;
            double sum = 0;
            int d = 0;
            fr(j, 1, n) {
                if(a[j].y < p) continue;
                sum += a[j].x;
                d++;
                double val = sum / d;
                if(val <= p) {
                    if(maxi(res, d)) tmp = i;
                }
                else break;
            }
        }
        cout << a[tmp].x << " " << a[tmp].y << el;
        cout << res;
    }
}
namespace sub2
{
    const int MAX = 1e5 + 2;
    typedef pair<ll, int> pii;
    pii st[4*MAX];

    pii MER(pii a, pii b)
    {
        pii res;
        res.fi = a.fi + b.fi;
        res.se = a.se + b.se;
        return res;
    }
    void upd(int id, int l, int r, int i, int val)
    {
        if(i > r || i < l) return;
        if(l == r) {
            st[id] = MER(st[id], {val, 1});
            return;
        }
        int mid = (r + l) >> 1;
        upd(id << 1, l, mid, i, val);
        upd(id << 1 | 1, mid + 1, r, i, val);
        st[id] = MER(st[id << 1], st[id << 1 | 1]);
    }
    pii get(int id, int l, int r, int u, int v)
    {
        if(r < u || v < l) return {0, 0};
        if(u <= l && r <= v) return st[id];
        int mid = (r + l) >> 1;
        return MER(get(id << 1, l, mid, u, v) ,get(id << 1 | 1, mid + 1, r, u, v) );
    }
    int check(int x, int lim)
    {
        double val = get(1, 1, 1e5, 1, x).fi;
        int sl = get(1, 1, 1e5, 1, x).se;
        if(!sl) return 1;

        int slx = get(1, 1, 1e5, x, x).se;
        double valx = x;
        val -= valx * slx;
        sl -= slx;
        fr(i, 1, slx) {
            double value = (val + valx * i) / (sl + i);
            if(value <= lim) return 1;
        }
        if(get(1, 1, 1e5, 1, x - 1).se == 0) return -1;
        return 0;
    }
    int calc(int lim)
    {
        int l = 1, r = 1e5, mid, ans = 0;
        if(get(1, 1, 1e5, 1, 1e5).se == 0) return 0;
        while(l <= r) {
            mid = (r + l) >> 1;
            if(check(mid, lim) == 1) {
                double val = get(1, 1, 1e5, 1, mid).fi;
                int sl = get(1, 1, 1e5, 1, mid).se;
                if(!sl) return 1;

                int slx = get(1, 1, 1e5, mid, mid).se;
                double valx = mid;
                val -= valx * slx;
                sl -= slx;
                fr(i, 1, slx) {
                    double value = (val + valx * i) / (sl + i);
                    if(value <= lim) ans = sl + i;
                    else break;
                }
                l = mid + 1;
            }
            else if(check(mid, lim) == -1) return 0;
            else r = mid - 1;
        }

        return ans;
    }
    bool cmp(bar a, bar b)
    {
        if(a.y == b.y) return a.x < b.x;
        return a.y > b.y;
    }
    void slv()
    {
        sort(a + 1, a + n + 1, cmp);

//        fr(i, 1, n) cout << a[i].x << " " << a[i].y << el;
        int ans = 0, pos;
        fr(i, 1, n) {
            upd(1, 1, 1e5, a[i].x, a[i].x);
            maxi(ans, calc(a[i].y));
        }
//        cout << check(8, 6); return;
        cout << ans;
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
        sub2::slv();
    //    sub2::slv();
    }
}


