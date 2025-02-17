#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) log2(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     MASK(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(ll i=a;i<=b;i++)
#define     frd(i,a,b) for(ll i=a;i>=b;i--)

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

struct node{ll x,y,w;};
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
ll lcm(ll a, ll b) {return a/__gcd(a, b)*b;}

ll n, m;
node a[MF];
void input()
{
    cin >> n >> m;
    fr(i, 1, n - 1) cin >> a[i].x >> a[i].y >> a[i].w;
}
namespace sub1
{

    bool cmp(node a, node b) {return a.w < b.w;}
    vector<ll> vi;
    ll val[MF];
    ll f[MF];
    ll goc(ll x)
    {
        while(f[x] > 0) {
            x = f[x];
        }
        return x;
    }
    void hn(ll r1, ll r2)
    {
        ll tmp = f[r1] + f[r2];
        if(abs(f[r1]) >= abs(f[r2])) {
            f[r1] = tmp;
            f[r2] = r1;
        }
        else{
            f[r2] = tmp;
            f[r1] = r2;
        }
    }
    void slv()
    {
        sort(alla(a, n - 1), cmp);
        fr(i, 1, n) f[i] = -1;
        ll res = 0;
        fr(i, 1, n - 1) {
            ll u = a[i].x;
            ll v = a[i].y;
            ll w = a[i].w;
            ll r1 = goc(u);
            ll r2 = goc(v);
            ll m1 = abs(f[r1]) ;
            ll m2 = abs(f[r2]);
            res = res + (m1 + m2)*(m1 + m2 - 1)/2 - m1*(m1 - 1)/2 - m2*(m2 - 1)/2;
            hn(r1, r2);
            val[w] = res;
            vi.pb(w);
        }
        sort(all(vi));
        ll tmp = -1;
        if(vi.size()) tmp = *vi.begin();
        ll x;
        fr(i, 1, m) {

            cin >> x;
            if(vi.size() == 0) {
                cout << 0 << " ";
                continue;
            }
            if(x < tmp) {
                cout << 0 << " " ;
                continue;
            }
            auto it = lower_bound(all(vi), x) ;

            ll ind = it - vi.begin();
            if(*it != x) ind--;
            cout << val[vi[ind]] << " " ;
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


