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

struct node{ll x,y,id;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n, q;
pll a[MF];
node qr[MF];
void input()
{
    cin >> n >> q; fr(i, 1, n) cin >> a[i].fi, a[i].se = i;
    fr(i, 1, q) {
        cin >> qr[i].x >> qr[i].y;
        qr[i].id = i;
    }
}
namespace sub1
{

    ll L[MF], R[MF], t[MF], leave[MF], lim, LQ[MF], RQ[MF], ans[MF];
    vector<ll> v;
    void compression()
    {
        fr(i, 1, n) v.pb(i);
        fr(i, 1, n) v.pb(a[i].fi) ;
        fr(i, 1, q) v.pb(qr[i].y);
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        fr(i, 1, n) a[i].fi = lower_bound(all(v), a[i].fi) - v.begin() + 1;
        fr(i, 1, q) qr[i].y = lower_bound(all(v), qr[i].y) - v.begin() + 1;
        lim = v.size();
    }
    void build(ll id, ll l, ll r)
    {
        if(l == r) {
            t[id] = a[l].fi;
            leave[l] = id;
            return ;
        }
        int m = (r + l) >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
    void upd(ll i, ll val)
    {
        ll id = leave[i];
        maxi(t[id], val);
        while(id) {
            id = id >> 1;
            t[id] = max(t[id << 1], t[id << 1 | 1]);
        }
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
    void bLR()
    {
        fr(i, 1, n) {
            L[i] = get(1, 1, lim, 1, a[i].fi - 1) + 1;
            upd(a[i].fi, L[i]);
        }
        fr(i, 1, 4*lim) t[i] = 0;
        frd(i, n, 1) {
            R[i] = get(1, 1, lim, a[i].fi + 1, lim) + 1;
            upd(a[i].fi, R[i]);
        }
        fr(i, 1, 4*lim) t[i] = 0;
    }
    bool cmp(node a, node b)
    {
        return a.x < b.x;
    }
    bool cmp1(pll a, pll b) {return a.fi < b.fi;}
    bool isGood[MF];
    ll cnt[MF];
    void slv()
    {
        compression();
        build(1, 1, n);
        bLR();
        ll mx = 0 ;
        fr(i,1,n) maxi(mx,L[i]+R[i]-1) ;
        fr(i,1,n) if(L[i] + R[i] - 1 == mx) cnt[L[i]]++ ;
        fr(i,1,n) if( (L[i] + R[i] - 1 != mx) || (cnt[L[i]] > 1) ) isGood[i] = 1 ;
        sort(qr + 1, qr + q + 1, cmp);
        sort(alla(a, n), cmp1);
        int j = 1;
        fr(i, 1, q) {
            while(j <= n && a[j].fi < qr[i].y) upd(a[j].se, L[a[j].se]), j++;
            LQ[i] = get(1, 1, lim, 1, qr[i].x - 1);
        }
        fr(i, 1, 4*lim) t[i] = 0;
        frd(i, q, 1) {
            while(j >= 1 && a[j].fi > qr[i].y) upd(a[j].se, R[a[j].se]), j--;
            RQ[i] = get(1, 1, lim, qr[i].x + 1, n);
        }
        fr(i, 1, q) maxi(ans[qr[i].id], LQ[i] + RQ[i] + 1 );
        fr(i,1,q) maxi(ans[qr[i].id],isGood[qr[i].x] ? mx : mx - 1) ;
        fr(i, 1, q) cout << ans[i] << el;
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
}



