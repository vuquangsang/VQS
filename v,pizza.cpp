#include <bits/stdc++.h>
using namespace std;

//#define   ll int
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
#define     BIT(msk, i) (msk&(1 << i))

const ll MN = 1e9+7;
const ll MF = 1e6+7;
const long long inf = 1e18+7;
const ll N = 1005;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll t,a,b;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template<class X, class Y>
    bool mini(X &x, const Y &y)  {
        if(x > y) {
            x = y;
            return 1;
        }
        else return 0;
    }
template<class X, class Y>
    bool maxi(X &x, const Y &y)
    {
        if(x < y) {
            x = y;
            return 1;
        }
        else return 0;
    }
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
node ar[MF];
ll n, B;

void input()
{
    cin >> n >> B;
    fr(i, 1, n) cin >> ar[i].t >> ar[i].a >> ar[i].b;
}
namespace sub1
{

    ll f[MF];
    bool cmp(node a, node b) {return a.t < b.t;}
    void slv()
    {
        sort(alla(ar, n), cmp);
        f[1] = ar[1].a - B;
        fr(i, 2, n) {
            ll ans = 0;
            fr(j, 1, i - 1) {
                ans = ans + ar[j].a - (ar[i].t - ar[j].t)*ar[j].b;
            }
            f[i] = ans + ar[i].a - B;
            fr(j, 1, i - 1) {
                ll value = 0 ;
                fr(k, j + 1, i) {
                    value = value + ar[k].a - ar[k].b*(ar[i].t - ar[k].t);
                }
                f[i] = max(f[i], f[j] + value - B);
            }
        }
   //     cout << f[1] << " " << f[2]; return;
        cout << f[n];
    }
}
namespace sub2
{
    ll f[MF], ka[MF], kb[MF], kt[MF], pre[MF];
    bool cmp(node a, node b) {return a.t < b.t;}
    ll slv()
    {
        sort(alla(ar, n), cmp);
        fr(i, 1, n) {
            ka[i] = ka[i - 1] + ar[i].a;
            kb[i] = kb[i - 1] + ar[i].b;
            kt[i] = kt[i - 1] + ar[i].t*ar[i].b;
        }
        f[1] = ar[1].a - B;
        pre[1] = f[1] - ka[1] - kt[1] - kb[1];
        fr(i, 2, n) {
            f[i] = ka[i - 1] - ar[i].t*kb[i - 1] + kt[i - 1] + ar[i].a - B;
            fr(j, 1, i - 1) {
                ll value = ka[i] - ka[j] - (kb[i] - kb[j])*ar[i].t + kt[i] - kt[j];
                f[i] = max(f[i], f[j] + value - B);

            }
        }
   //     cout << f[1] << " " << f[2]; return;
        return f[n];
    }
}
namespace sub3
{
    ll f[MF], ka[MF], kb[MF], kt[MF], pre[MF], lazy[MF];
    bool cmp(node a, node b) {return a.t < b.t;}
    struct point
    {
        ll sum, k, res;
    };
    point t[MF];
    point MERGE(point a, point b)
    {
        if(a.res > b.res) return a;
        return b;
    }
    void build(ll id, ll l, ll r, ll i)
    {
        if(i > r || i < l) return ;
        if(l == r) {
            t[id].sum = f[i] - ka[i] - kt[i];
            t[id].k = kb[i];
            t[id].res = t[id].sum + t[id].k;
            return ;
        }
        ll m = (r + l) >> 1;
        build(id << 1, l, m, i);
        build(id << 1 | 1, m + 1, r, i);
        t[id] = MERGE(t[id << 1], t[id << 1 | 1]);
    }
    void down(ll id, ll l, ll m, ll r)
    {
        if(lazy[id]) {
            ll x = lazy[id];
            t[id << 1].res = t[id << 1].sum + t[id << 1].k*x;
            t[id << 1 | 1].res = t[id << 1 | 1].sum + t[id << 1 | 1].k*x;
            lazy[id << 1] = lazy[id << 1 | 1] = x;
            lazy[id] = 0;
        }
    }
    void upd(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if(r < u || v < l) return ;
        if(u <= l && r <= v) {
            t[id].res = t[id].sum + t[id].k*val;
            lazy[id] = val;
            return;
        }
        ll m = (r + l) >> 1;
        down(id, l, m, r);
        upd(id << 1, l, m, u, v, val);
        upd(id << 1 | 1, m + 1, r, u, v, val);
        t[id] = MERGE(t[id << 1], t[id << 1 | 1]);
    }
    point get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return {-inf, -inf, -inf};
        if(u <= l && r <= v) return t[id];
        ll m = (r + l) >> 1;
        down(id, l, m, r);
        return MERGE(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
    ll slv()
    {
        sort(alla(ar, n), cmp);
        fr(i, 1, n) {
            ka[i] = ka[i - 1] + ar[i].a;
            kb[i] = kb[i - 1] + ar[i].b;
            kt[i] = kt[i - 1] + ar[i].t*ar[i].b;
        }
        f[1] = ar[1].a - B;
        build(1, 1, n, 1);
        upd(1, 1, n, 1, 1, ar[1].t).res;
        cout << get(1, 1, n, 1, 1).res; return;
        fr(i, 2, n) {
            upd(1, 1, n, 1, i - 1, ar[i].t);
            f[i] = ka[i - 1] - ar[i].t*kb[i - 1] + kt[i - 1] + ar[i].a - B;
      //      ll value = pre[i - 1] + ka[i] + lt[i] - kb[i];
            ll value = ka[i] + kt[i] - kb[i]*ar[i].t + get(1, 1, n, 1, i - 1).res;
            maxi(f[i], value - B);
            build(1, 1, n, i);
            upd(1, 1, n, 1, i, 1);
        }
   //     cout << f[1] << " " << f[2]; return;
        return f[n];
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
    ll mtt = 10;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        test();
        if(sub2::slv() != sub3::slv()) {
            cout << sub2::slv() << " " << sub3::slv() << el;
            return 0;
        } cout << el;
    //    sub2::slv();
    }
}
