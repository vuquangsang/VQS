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

const int N = 1e5 + 2;
int n, a[N], K;
void input()
{
    cin >> n >> K;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    ll pre[N];
    void slv()
    {
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];

        ll ans = 0, l = 0, r = 0;
        fr(i, 1, n) {
            if(pre[i] < K) continue;
            int id = upper_bound(pre + 1, pre + n + 1, pre[i] - K) - pre - 1;
            int lim =  max(1ll*0, 1ll*id - 50);
            frd(x, id, lim) {
                if(maxi(ans, (pre[i] - pre[x])/(i - x))) {
                    l = x;
                    r = i;
                }
            }
        }
        cout << ans << " " << l << " " << r;
    }
}
namespace sub2
{

    int pre[N];

    struct line
    {
        ll a, b, pos;
        line () {
            a = 0, b = inf;
        }
        line (ll _a, ll _b) {
            a = _a;
            b = _b;
        }
        ll operator()(ll x) {
            return a*x + b;
        }
    };

    const int MAX = 1e6 +2;
    line st[4*MAX];
    void upd(int id, int l, int r, line val)
    {
        if(l == r) {
            if(st[id](l) > val(l)) {
                st[id] = val;
            }
            return;
        }
        int mid = (r + l) >> 1;
        if(st[id].a < val.a) swap(st[id], val);
        if(st[id](mid) > val(mid)) {
            swap(st[id], val);
            upd(id << 1, l, mid, val);
        }
        else upd(id << 1 | 1, mid + 1, r, val);
    }

    ll get(int id, int l, int r, ll x)
    {
        if(l == r) return st[id](x);
        int mid = (r + l) >> 1;
        if(x < mid ){

            return min(st[id](x), get(id << 1, l, mid, x));
        }
        else return min(st[id](x), get(id << 1 | 1, mid + 1, r, x));
    }
    bool check(int i, ll A)
    {
        return pre[i] - A*i > get(1, 0, 1e6, A);
    }
    void slv()
    {
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];
        int ans = 0;
        int ret = 0;
        upd(1, 0, 1e6, line(0, 0));
        fr(i, 1, n) {
            int l = K/i, r = 1e9, mid, pos = 0;
            while(l <= r) {
                mid = (r + l) >> 1;
                if(check(i, mid)) {
                    pos = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            if(maxi(ans, pos)) ret = i;
            upd(1, 0, 1e6, line(-i, pre[i]));
        }
        cout << ans - 1;
    }
}

namespace sub3
{
    ll pre[N], pos[N];

    ll val[N];
    bool check(int A)
    {
        fr(i, 1, n) val[i] = pre[i] - 1ll*A*i;
        fr(i, 1, n) mini(val[i], val[i - 1]);

        fr(i, 1, n) {
            if(pos[i] != -1 && pre[i] - 1ll*A*i >= val[pos[i]]) {
                return 1;
            }
        }
        return 0;
    }
    void slv()
    {
        memset(pos, -1, sizeof pos);
        fr(i, 1, n) pre[i] = pre[i - 1] + a[i];
        fr(i, 1, n) {
            if(pre[i] < K) continue;
            pos[i] = upper_bound(pre + 1, pre + n + 1, pre[i] - K) - pre - 1;
        }
        int l = 1, r = 1e9, mid, ans = 0;
        while(l <= r) {
            mid = (r + l) >> 1;
            if(check(mid)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
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
        sub3::slv();

    }
}


