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
struct pll{ll fi,se;bool operator <(pll const&a) const {return fi < a.fi;}};
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

pll a[MF];
ll n;
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i].fi;
    fr(i, 1, n) cin >> a[i].se;
}
namespace sub1
{

    bool cmp(pll a, pll b) {return a.se + a.fi < b.fi + b.se;}
    bool cmp1(pll a, pll b) {return a.fi < b.fi;}
    bool cmp2(pll a, pll b) {return a.se < b.se;}
    ll cal()
    {
        priority_queue<pll> q;
        ll x = 0, res = 0, ans = 0;
        fr(i, 1, n) {
            if(x <= a[i].se) {
                x+=a[i].fi;
                ans++;
                q.push({a[i].fi, a[i].se});
            }
            else{
                    if(x - q.top().fi <= a[i].se && a[i].fi < q.top().fi) {
                        x-=q.top().fi; q.pop();
                        x+=a[i].fi;
                        q.push({a[i].fi, a[i].se});
                    }
            }
        }
        return ans;
    }
    void slv()
    {
        sort(alla(a, n), cmp);
        ll res = 0;
        maxi(res, cal());
        sort(alla(a, n), cmp1);
        maxi(res, cal());
        sort(alla(a, n), cmp2);
        maxi(res, cal());
        cout << res;
        // tham
    }
}
namespace sub2
{
    bool cmp(pll a, pll b) {return a.fi + a.se < b.fi + b.se;}
    priority_queue<ll> q;
    void slv()
    {
        sort(alla(a, n), cmp);
        ll x = 0;
        ll res = 0, ans = 0;
        fr(i, 1, n) {
            if(x <= a[i].se) {
                res++;
                q.push(a[i].se);
                x+=a[i].fi;
            }
            else{
                maxi(ans, res);
                if(!q.empty()) {
                    x-=q.top();
                    q.pop(); res--;
                }
            }
        }
        cout << ans;
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


