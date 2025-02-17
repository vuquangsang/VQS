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

const ll sm = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

int n, m, k;
void input()
{
    cin >> n >> m >> k;

}
namespace sub1
{

    struct matrix
    {
        vector<vector<int>> a = vector<vector<int>> (n, vector<int>(n));
        matrix operator * (const matrix& other )  {
            matrix product;
            vector<vector<ll>> tmp(n, vector<ll> (n));
            REP(i, 0, n) REP(j, 0, n) REP(k, 0, n) {
                tmp[i][k] = (tmp[i][k] + 1ll * a[i][j] * other.a[j][k]) % sm;
            }
            REP(i, 0, n) REP(j, 0, n) product.a[i][j] = tmp[i][j] % sm;
            return product;
        }

        matrix ex_pow(matrix a, ll n)
        {
            matrix product;
            REP(i, 0, n) product.a[i][i] = 1;
            while(n > 0) {
                while(n % 2) {
                    product = product * a;
                }
                a = a * a;
                n /= 2;
            }
            return product;
        }
    } mt;
    void slv()
    {
        int x, y;
        matrix single;
        fr(i, 1, m) {
            cin >> x >> y;
            single.a[x - 1][y - 1] = 1;
        }
        matrix total = mt.ex_pow(single, k);
        int ans = 0;
        REP(i, 0, n) REP(j, 0, n) {
            ans = (ans + total.a[i][j]) % sm;
        }
        cout << ans;
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


