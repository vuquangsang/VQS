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


ll n, q;
void input()
{
    cin >> n >> q;
}
namespace sub1
{
    ll t[MF], p[MF], s[MF];
    void down(ll id, ll l, ll m, ll r)
    {
        if(s[id]) {
            ll x = s[id];
            (t[id << 1]+=mod(m - l + 1, x))%=MN;
            (t[id << 1 | 1]+=mod(r - m, x))%MN;
            (s[id << 1]+=x)%=MN;
            (s[id << 1 | 1]+=x)%=MN;
            s[id] = 0;
        }
        if(p[id] != 1) {
            ll x = p[id];
            t[id << 1] = mod(t[id << 1], x);
            t[id << 1 | 1] = mod(t[id << 1 | 1], x);
            p[id << 1] = x;
            p[id << 1 | 1] = x;
            p[id] = 1;
        }
    }
    void upd1(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            t[id]+= mod((r - l + 1),val);
            s[id]+=val;
            s[id]%=MN;
            return  ;
        }
        int m = (r + l) >> 1;
        down(id, l, m, r);
        upd1(id << 1, l, m, u, v, val);
        upd1(id << 1 | 1, m + 1, r, u, v, val);
        t[id] = (t[id << 1] + t[id << 1 | 1])%MN;
    }
    void upd2(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            t[id] = mod(t[id], val);
            p[id] = mod(p[id], val);
            return;
        }
        int m = (r + l) >> 1;
        down(id, l, m, r);
        upd2(id << 1, l, m, u, v, val);
        upd2(id << 1 | 1, m + 1, r, u, v, val);
        t[id] = (t[id << 1] + t[id << 1 | 1])%MN;
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        down(id, l, m, r);
        return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
    }
    void slv()
    {
        fr(i, 1, 4*n) p[i] = 1;
        int l, r, w, k;
        while(q--){
            cin >> k >> l >> r;
            if(k == 1) {
                cin >> w;
                upd1(1, 1, n, l, r, w);
            }
            else if(k == 2) {
                cin >> w;
                upd2(1, 1, n, l, r, w);
            }
            else{
                cout << get(1, 1, n, l, r)%MN << el;
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



