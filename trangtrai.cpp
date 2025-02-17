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

const int MAX = 1e5 + 2;
int n, q;
ll a[MAX], s = 0;
pll Q[MAX];
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> a[i], s+=a[i];
    fr(i, 1, q) cin >> Q[i].fi, Q[i].se = i;
}
namespace sub1
{

    ll dp[MAX][2];
    ll cal(ll x)
    {
        memset(dp, 0x3f, sizeof dp);
        dp[1][0] = a[1];
        dp[0][0] = dp[0][1] = 0;
        fr(i, 2, n) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
            if(a[i] - a[i - 1] <= x) dp[i][1] = min(dp[i - 2][0], dp[i - 2][1]) + max(a[i], a[i - 1]);
        }
        return min(dp[n][1], dp[n][0]);
    }
    void slv()
    {
        sort(a + 1, a + n + 1);
        ll x;
        fr(i, 1, q) {
            x = Q[i].fi;
            cout << cal(x) << el;
        }

    }
}
namespace sub2
{
    ll ans[MAX], pre_even[MAX], pre_odd[MAX], res = 0;
    struct eg
    {
        ll val, l, r;
    };
    eg f[MAX];
    vector<eg> tmp;
    ll goc(ll x)
    {
        while(f[x].val > 0) {
            x = f[x].val;
        }
        return x;
    }
    void hn(ll r1, ll r2, ll x, ll y)
    {
        ll sa = f[r1].r - f[r1].l + 1;
        ll sb = f[r2].r - f[r2].l + 1;
//        cout << f[r1].val << " " << f[r1].l << " " << f[r1].r << el;
//        cout << f[r2].val << " " << f[r2].l << " " << f[r2].r << el; cout << x << " " << y << el;
        if(sa == 1) {
            s-=a[f[r1].r];
        }
        if(sb == 1) {
            s-=a[f[r2].r];
        }
        if(sa > 1){
            if(f[r1].r&1){
                res = res - pre_odd[f[r1].r] + pre_odd[f[r1].l - 1];
            }
            else {
                res = res - pre_even[f[r1].r] + pre_even[f[r1].l - 1];
            }
        }
        if(sb > 1) {
            if(f[r2].r&1) {
                res = res - pre_odd[f[r2].r] + pre_odd[f[r2].l - 1];
            }
            else res = res - pre_even[f[r2].r] + pre_even[f[r2].l - 1];
        }
        ll tmp = f[r1].val + f[r2].val;
        x = min({x, f[r1].l, f[r2].l});
        y = max({y, f[r1].r, f[r2].r});
        if(y&1) res = res + pre_odd[y] - pre_odd[x - 1];
        else res = res + pre_even[y] - pre_even[x - 1];
        if(f[r2].val < f[r1].val) swap(r1, r2);
        f[r1] = {tmp, x, y};
        f[r2] = {r1, x, y};
    }
    void slv()
    {
        sort(a + 1, a + n + 1);
        fr(i, 1, n) {
            pre_even[i] = pre_even[i - 1];
            pre_odd[i] = pre_odd[i - 1];
            if(i&1) pre_odd[i]+=a[i];
            else pre_even[i]+=a[i];
        }
        sort(Q + 1, Q + q + 1, [](pll a, pll b){return a.fi < b.fi;});
        fr(i, 1, n) f[i] = {-1, i, i};
        fr(i, 2, n) {
            tmp.pb({a[i] - a[i - 1], i - 1, i});
        }
        sort(all(tmp), [](eg a, eg b){return a.val < b.val;});
        ll sz = tmp.size() - 1, time = 0;
        fr(i, 1, q) {
            ll d = Q[i].fi;
            ll id = Q[i].se;
            while(time <= sz && tmp[time].val <= d) {
                ll x = tmp[time].l;
                ll y = tmp[time].r;
                ll r1 = goc(x);
                ll r2 = goc(y);
                if(r1 != r2) hn(r1, r2, x, y);
                time++;
            }
//            cout << res << " " << s; return;
            ans[id] = res + s;
        }
        fr(i, 1, q) cout << ans[i] << el;
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
        sub2::slv();
    //    sub2::slv();
    }
}


