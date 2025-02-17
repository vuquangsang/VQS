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

ll n;
string s;
void input()
{
    cin >> n >> s;
    s = ' ' + s;
}
namespace sub1
{

    ll a[MF], b[MF], c[MF];
    void slv()
    {
        fr(i, 1, n) {
            a[i] = a[i - 1];
            b[i] = b[i - 1];
            c[i] = c[i - 1];
            if(s[i] == 'a') a[i]++;
            if(s[i] == 'b') b[i]++;
            if(s[i] == 'c') c[i]++;
        }
        int res = 0;
        fr(i, 1, n) {
            frd(j, n, 1) {
                ll m1 = a[j] - a[i - 1];
                ll m2 = b[j] - b[i - 1];
                ll m3 = c[j] - c[i - 1];
                ll value = max({m1, m2, m3});
                if(value >= (j - i + 1)/2 + 1) {
                    maxi(res, j  - i + 1);
                    break;
                }
            }
        }
        cout << res;
    }
}
namespace sub2
{
    ll pre[MF], sa[MF], t[MF];
    pll c[MF];
    ll mi[MF];
    bool cmp(pll a, pll b)
    {
        if(a.se == b.se) return a.fi > b.fi; // de no khoi tru nhung so bang no hay vcl
        return a.se < b.se;
    }
    ll cal(char x)
    {
        fr(i, 1, n) {
            if(s[i] == x) sa[i] = 1;
            else sa[i] = -1;
        }
        pre[0] = 0;
        fr(i, 1, n) pre[i] = pre[i - 1] + sa[i];
        fr(i, 0, n) c[i] = {i, pre[i]};
        sort(c + 0, c + n + 1, cmp);
        mi[0] = c[0].fi;
        fr(i, 1, n) mi[i] = min(mi[i - 1], c[i].fi);
        ll res = 1;
        fr(i, 1, n) {
            maxi(res, c[i].fi - mi[i - 1]);
        }
        return res;
    }
    void slv()
    {
        ll m1 = cal('a');
        ll m2 = cal('b');
        ll m3 = cal('c');
        cout << max({m1, m2, m3});
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


