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

struct node{ll h,a,b;};
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
ll n, pos[5];
void input()
{
    cin >> n;
    fr(i, 1, n) {
        cin >> pos[1] >> pos[2] >> pos[3];
        sort(alla(pos, 3));
        ar[i] = {pos[1], pos[2], pos[3]};
    }
}
namespace sub1
{

    ll f[MF];
    bool cmp(node a, node b) {return a.a < b.a;}
    bool cmp1(node a, node b) {return a.b < b.b;}
    bool cmp2(node a, node b) {return a.a + a.b < b.a + b.b;}
    void slv()
    {
        sort(alla(ar, n), cmp);
    //    cout << el;fr(i, 1, n) cout << ar[i].h << " " << ar[i].a << " " << ar[i].b << el;
        f[1] = ar[1].h;
        fr(i, 2, n) {
            f[i] = ar[i].h;
            fr(j, 1, i - 1) {
                if(ar[i].b >= ar[j].b){
                    maxi(f[i], f[j] + ar[i].h);
                }

            }
        }
        ll res = *max_element(alla(f, n));
        sort(alla(ar, n), cmp1);
        f[1] = ar[1].h;
        fr(i, 2, n) {
            f[i] = ar[i].h;
            fr(j, 1, i - 1) {
                if(ar[i].a >= ar[j].a){
                    maxi(f[i], f[j] + ar[i].h);
                }

            }
        }
        maxi(res, *max_element(alla(f, n)));
        sort(alla(ar, n), cmp2);
        f[1] = ar[1].h;
        fr(i, 2, n) {
            f[i] = ar[i].h;
            fr(j, 1, i - 1) {
                if(ar[i].a >= ar[j].a && ar[i].b >= ar[j].b){
                    maxi(f[i], f[j] + ar[i].h);
                }

            }
        }
        maxi(res, *max_element(alla(f, n)));
        cout << res;
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


