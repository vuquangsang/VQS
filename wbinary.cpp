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

const ll MN = 1007050321;
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

string s;
bool a[MF];
ll q, n;
void input()
{
    cin >> s;
    fr(i, 0, s.size() - 1) a[i + 1] = s[i] - '0';
    n = s.size();
    cin >> q;
}
namespace sub1
{

    // t[id].suim : so tp ma nut k ql
    // t[id].sl : con lai bao nhieu chu so
    // id : nut la
    struct line
    {
        ll sum, sl;
    };
    line t[MF];
    ll findpos(ll p)
    {
        ll id = 1, l = 1, r = n,  m;
        while(l < r) {
            m = (r + l) >> 1;
            if(t[id << 1].sl < p) {
                l = m + 1;
                p = p - t[id << 1].sl;
                id = id << 1  | 1;
            }
            else{
                r = m;
                id = id << 1;
            }
        }
        return l;
    }
    ll Pow(ll a, ll n)
    {
        if(!n) return 1;
        ll res = Pow(a, n/2);
        res = mod(res, res);
        if(n&1) res=  res*a;
        return res;
    }
    line MERGE(line a, line b)
    {
        line res;
        res.sum = mod(a.sum,Pow(2, b.sl)) + b.sum;
        res.sum%=MN;
        res.sl = a.sl + b.sl;
        return res;
    }
    void build(ll id, ll l, ll r)
    {
        if(l == r) {
            t[id] = {a[l], 1};
            return;
        }
        int m = (r + l) >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        t[id] = MERGE(t[id << 1], t[id << 1 | 1]);
    }
    void upd(ll id, ll l, ll r, ll i)
    {
        if(i > r || i < l) return;
        if(l == r) {
            t[id].sum = t[id].sl = 0;
            return;
        }
        int m = (r + l) >> 1;
        upd(id << 1, l, m, i);
        upd(id << 1 | 1, m + 1, r, i);
        t[id] = MERGE(t[id << 1], t[id << 1 | 1]);

    }
    line get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return {0, 0};
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        return MERGE(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
    void slv()
    {
        build(1, 1, n);
        int k, x, y;
        while(q--) {
            cin >> k >> x;
            if(k) {
                int pos = findpos(x);
                upd(1, 1, n, pos);
            }
            else {
                cin >> y;
                x = findpos(x);
                y = findpos(y);
                cout << get(1, 1, n, x, y).sum << el;
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



