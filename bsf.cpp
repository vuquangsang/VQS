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

struct node{ll h,w;};
struct bg{ll id,ts;};
struct pll{ll h,f,c;};
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

node a[MF];
pll p[MF];
ll n, m;
void input()
{
    cin >> n >> m;
    fr(i, 1, n) cin >> a[i].h >> a[i].w;
    fr(i, 1, m) cin >> p[i].h >> p[i].f >> p[i].c;
}
namespace sub1
{

    bool cmp(node a, node b) {return a.h < b.h;}
    bool cmp1(pll a, pll b) {return a.h < b.h;}
    ll f[N][N];
    void slv()
    {
        sort(alla(a, n), cmp);
        sort(alla(p, m), cmp1);
        memset(f, 0x3f, sizeof(f));
   //     cout << el; fr(i, 1, n) cout << a[i].h <<  " " << a[i].w << el; cout << el;
   //     fr(i, 1, m) cout << p[i].h << " " << p[i].f << " " << p[i].c << el; cout << el;
        f[0][0] = 0;
        fr(i, 1, m) f[i][0] = 0;
        fr(i, 1, m) {
            fr(j, 1, n) {
                if(a[j].h > p[i].h) break;
                f[i][j] = f[i - 1][j];
                ll ans = 0;
                frd(k, j, 1) {
                    ans+=a[k].w;
                    mini(f[i][j], f[i - 1][k - 1] + ans*p[i].c + p[i].f);
                }
            }
        }
        cout << f[m][n]; return;
        fr(i, 1, m) {
            fr(j, 1, m) {
                cout << f[i][j] << " ";
            } cout << el;
        }

    }
}
namespace sub2
{
    ll f[N][N][2];
    bool cmp(node a, node b) {return a.h < b.h;}
    bool cmp1(pll a, pll b) {return a.h < b.h;}
    void slv()
    {
        sort(alla(a, n), cmp);
        sort(alla(p, m), cmp1);
        memset(f, 0x3f, sizeof(f));
        fr(i, 0, m) f[0][i][0] = 0;
        fr(i, 1, n) {
            fr(j, 1, m) {
                f[i][j][0] = min(f[i][j - 1][0], f[i][j - 1][1]);
                if(a[i].h <= p[j].h) {
                    f[i][j][1] = min(f[i - 1][j][0] + p[j].f, f[i - 1][j][1]) + a[i].w*p[j].c;
                }
            }
        }
        cout << min(f[n][m][0], f[n][m][1]);
    }
}

main()
{
    #define TASK ""4
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


