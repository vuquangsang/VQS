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

int n;
void input()
{
    cin >> n;
}
namespace sub1
{

    struct matrix
    {
        int a[2][2] = {{0, 0}, {0, 0}};

        matrix operator * (const matrix& other) const
        {
            matrix x;
            for(int i : {0, 1}) {
                for(int j : {0, 1}) {
                    for(int k : {0, 1}) {
                        x.a[i][k] = x.a[i][k] + 1ll * a[i][j] * other.a[j][k];
                        x.a[i][k] %= sm;
                    }
                }
            }
            return x;
        }
    };

    matrix ex_pow(matrix a, ll n)
    {
        matrix res;
        res.a[0][0] = res.a[1][1] = 1;
        while(n) {
            if(n & 1) {
                res = res * a;
            }
            n /= 2;
            a = a * a;
        }
        return res;
    }
    void slv()
    {
        if(n <= 1) {
            cout << 1;
            return;
        }
        matrix init;
        init.a[0][0] = 0;
        init.a[0][1] = init.a[1][0] = init.a[1][1] = 1;
        cout << ex_pow(init, n + 1).a[1][0];
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


