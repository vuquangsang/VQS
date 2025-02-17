/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

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

const ll MN = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}


const int MAX = 5e5 + 2;
ll n, a[MAX], q;
pll Q[MAX];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
    cin >> q;
}
namespace sub1
{


    void slv()
    {
        ll res = 0;
        int p, x;
        fr(t, 1, q) {
            p = Q[t].fi;
            x = Q[t].se;
            ll ans = -inf;
            int cur = a[p];
            a[p]+=x;
            fr(i, 1, n) {
                ll s = 0;
                for(int j = i; j <= n; j+=i) s+=a[j];
                maxi(ans, s);
            }
            a[p] = cur;
            res+=ans;
        }
        cout << res;
    }
}
namespace sub2
{
    ll f1[MAX], f2[MAX], sum_a[MAX];
    pll tmp[MAX];
    void slv()
    {
        memset(f1, -0x3f, sizeof f1);
        memset(f2, -0x3f, sizeof f2);
        fr(i, 1, n) for(int j = i; j <= n; j+=i) sum_a[i]+=a[j];
        fr(i, 1, n) for(int j = i; j <= n; j+=i) maxi(f1[j], sum_a[i]);

        fr(i, 1, n) tmp[i] = {sum_a[i], i};
        sort(alla(tmp, n), [](pll a, pll b){return a.fi > b.fi;});
        f2[1] = 0;
        fr(i, 1, n) {
            fr(j, 1, n) {
                if(i%tmp[j].se != 0) {
                    f2[i] = tmp[j].fi;
                    break;
                }
            }
        }
//        fr(i, 1, n) cout << sum_a[i] << " "; cout << el;
//        fr(i, 1, n) cout << f1[i] << " "; cout << el;
//        fr(i, 1, n) cout << f2[i] << " "; cout << el;
        ll ans = 0, p, x;
        fr(i, 1, q) {
            cin >> p >> x;
            ans+=max(f1[p] + x, f2[p]);
        //    cout << f1[p] + x << " " << f2[p] << el;
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
        sub2::slv();
    //    sub2::slv();
    }
}



