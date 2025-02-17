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
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n;
node a[MF];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i].x >> a[i].y;
}
namespace sub1
{

    stack<ll> s;
    node pos[MF];
    ll f[MF];
    void slv()
    {
        sort(a +1,a  + n + 1, [](node a, node b) {
            if(a.x == b.x) return a.y < b.y;
            return a.x < b.x;
        });
        fr(i, 1, n) {
            while(!s.empty() && a[i].y >= a[s.top()].y) s.pop();
            s.push(i);
        }
        ll sz = s.size();
        fr(i, 1, sz) pos[i] = a[s.top()], s.pop();
        sort(pos + 1, pos + sz + 1, [](node a, node b){
                return a.x < b.x;
        } );
      //  fr(i, 1, n) cout << pos[i].x << " " << pos[i].y << el;
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        f[1] = pos[1].x * pos[1].y;
        fr(i, 2, sz) fr(j, 0, i - 1) {
            mini(f[i], f[j] + pos[j + 1].y*pos[i].x);
        }
        cout << f[sz];
    }
}
namespace sub2
{
    stack<ll> s;
    ll f[MF];
    node pos[MF];
    struct line
    {
        ll a, b;
        line() {
            a = 0, b = inf;
        }
        line(ll _a, ll _b) {
            a = _a;
            b = _b;
        }
        ll operator()(ll x)
        {
            return a*x + b;
        }
    } t[4*MF];
    void upd(ll id, ll l, ll r, line L)
    {
        if(l == r) {
            if(t[id](l) > L(l)) swap(t[id], L);
            return;
        }
        int m = (r + l) >> 1;
        if(t[id].a > L.a) swap(t[id], L);
        if(t[id](m) > L(m)) {
            swap(t[id], L);
            upd(id << 1 | 1, m + 1, r, L);
        }
        else upd(id << 1, l, m, L);
    }
    ll get(ll id, ll l, ll r, ll x)
    {
        if(l == r) return t[id](x);
        int  m = (r + l) >> 1;
        if(x <= m) return min(t[id](x), get(id << 1, l, m, x));
        else return min(t[id](x), get(id << 1 | 1, m + 1, r, x));
    }
    void slv()
    {
        sort(a +1,a  + n + 1, [](node a, node b) {
            if(a.x == b.x) return a.y < b.y;
            return a.x < b.x;
        });
        fr(i, 1, n) {
            while(!s.empty() && a[i].y >= a[s.top()].y) s.pop();
            s.push(i);
        }
        ll sz = s.size();
        fr(i, 1, sz) pos[i] = a[s.top()], s.pop();
        sort(pos + 1, pos + sz + 1, [](node a, node b){
                return a.x < b.x;
        } );
  //      fr(i, 1, sz) cout << pos[i].x << " " << pos[i].y << el;
        f[0] = 0;
        f[1] = a[1].x*a[1].y;
        upd(1, 1, 1e6, line(pos[2].y, f[1]));
        upd(1, 1, 1e6, line(pos[1].y, f[0]));
        fr(i, 2, sz) {
            f[i] = get(1, 1, 1e6, pos[i].x);
            upd(1, 1, 1e6, line(pos[i + 1].y, f[i]));
        }
        cout << f[sz];

    }
}
namespace sub3
{
    ll eval(ll x, line L)
    {
        return L.a*x + L.b;
    }
    bool bad(node a, node b, node c)
    {
        return (b.y - a.y)*(a.x -c.x) >= (a.x - b.x)*(c.y - a.y);
    }
    void slv()
    {
        sort(a +1,a  + n + 1, [](node a, node b) {
            if(a.x == b.x) return a.y < b.y;
            return a.x < b.x;
        });
        fr(i, 1, n) {
            while(!s.empty() && a[i].y >= a[s.top()].y) s.pop();
            s.push(i);
        }
        ll sz = s.size();
        fr(i, 1, sz) pos[i] = a[s.top()], s.pop();
        sort(pos + 1, pos + sz + 1, [](node a, node b){
                return a.x < b.x;
        } );
        vector<node> d;
        ll last = 0;
        fr(i, 1, sz) {
            line new_line = {pos[i].y, last};
            while(d.size() >= 2 && bad(d[]))
        }
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
        if(n <= 1000) sub1::slv();
        else sub3::slv();
    }
}



