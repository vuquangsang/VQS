/* Vu Quang Sang from Le Khiet High School for Gifted */
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

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n, a[MF], f[MF], s[MF];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    vector<ll> v;
    ll dep[MF], lim;
    struct line
    {
        ll a, b;
        line()
        {
            a = 0;
            b = -inf;
        }
        line(ll _a, ll _b)
        {
            a = _a;
            b = _b;
        }
        ll operator ()(ll x)
        {
            return a*x + b;
        }
    };

    line t[MF];
    void upd(ll id, ll l, ll r, line L)
    {
        if(l == r) {
            if(t[id](dep[l]) < L(dep[l])) swap(t[id], L);
            return ;
        }
        int m = (r + l) >> 1;
        if(t[id].a > L.a) swap(t[id], L);
        if(t[id](dep[m]) < L(dep[m])) {
            swap(t[id], L);
            upd(id << 1, l, m, L);
        }    else upd(id << 1 | 1, m + 1, r, L);
    }
    ll get(ll id, ll l, ll r, ll x)
    {
        if(l == r) return t[id](dep[l]);
        int mid = (r + l) >> 1;
        if(x <= mid) return max(t[id](dep[x]), get(id << 1, l, mid, x));
        else return max(t[id](dep[x]), get(id << 1 | 1, mid + 1, r, x));
    }
    void Comp()
    {
        fr(i, 0, n) v.pb(s[i]);
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        fr(i, 0, v.size() - 1) dep[i + 1] = v[i];
        lim = v.size();
    }
    void view()
    {
        fr(i, 1, n) cout << s[i] << " "; cout << el;
        fr(i, 1, n) cout << f[i] << " "; cout << el;
        for(int x : v) cout << x << " " ; cout << el;
    }
    void slv()
    {
        fr(i, 1, n) {
            s[i] = s[i - 1] + a[i];
            f[i] = f[i - 1] + i*a[i];
        }
        Comp();
        bool debug = 1;
        if(debug) view();
        ll ans = 0, l = -1, r = -1;
        fr(i, 0, n) {
            int pos = lower_bound(all(v), s[i]) - v.begin() + 1;
            if(debug) cout << pos << el;
            ll sum = f[i] + get(1, 1, lim, pos);
            if(maxi(ans, sum)) r = i;
            upd(1, 1, lim, line(-i, 1ll*i*s[i] - f[i]));
        }
        cout << ans << el;
        for(l = r; l >= 1; l--) {
            ll sum = (f[r] - f[l - 1]) - 1ll*(l - 1)*(s[r] - s[l - 1]);
            if(sum == ans) break;
        }
        cout << l << " " << r;
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



