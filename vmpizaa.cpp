
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
    ll f[MF], ka[MF], kb[MF], kt[MF];
    pll pre[MF];
    bool cmp(node a, node b) {return a.t < b.t;}
    struct line
    {
        ll a, b;
        line() {
            a = 0, b = -inf;
        }
        line(ll _a, ll _b)
        {
            a = _a;
            b = _b;
        }
        ll operator () (ll x)
        {
            return a*x + b;
        }
    } t[MF];
    void upd(ll id, ll l, ll r, line val)
    {
        if(l == r) {
            if(val(l) > t[id](l)) t[id] = val;
            return ;
        }
        int m = (r + l) >> 1;
        if(t[id].a > val.a) swap(t[id], val);
        if(t[id](m) < val(m)) {
            swap(t[id], val);
            upd(id << 1, l, m, val);
        }
        else upd(id << 1 | 1, m + 1, r, val);
    }
    ll get(ll id, ll l, ll r, ll x)
    {
        if(l == r) return t[id](x);
        ll m = (r + l) >> 1;
        if(x <= m) return max(t[id](x), get(id << 1, l, m, x));
        else return max(t[id](x), get(id << 1 | 1, m + 1, r, x));
    }
    void slv()
    {
        sort(alla(ar, n), cmp);
        fr(i, 1, n) {
            ka[i] = ka[i - 1] + ar[i].a;
            kb[i] = kb[i - 1] + ar[i].b;
            kt[i] = kt[i - 1] + ar[i].t*ar[i].b;
        }
        f[1] = ar[1].a - B;
        upd(1, 1, 1e5, line(kb[1], f[1] - ka[1] - kt[1]));
        fr(i, 2, n) {
            f[i] = ka[i - 1] - ar[i].t*kb[i - 1] + kt[i - 1] + ar[i].a - B;
            maxi(f[i], get(1, 1, 1e5, ar[i].t) - B + ka[i] - kb[i]*ar[i].t + kt[i]);

       /*     fr(j, 1, i - 1) {
                maxi(f[i], pre[j].fi + pre[j].se*ar[i].t + ka[i] + kt[i] - kb[i]*ar[i].t - B);
            }
            pre[i] = {f[i] - ka[i] - kt[i], kb[i]}; */
            upd(1, 1, 1e5, line(kb[i], f[i] - ka[i] - kt[i]));
        }
        cout << f[n];
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

