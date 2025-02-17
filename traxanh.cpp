#include <bits/stdc++.h>
using namespace std;

#define     TASK "subsubset"
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
#define     fr(i,a,b) for(int i=a;i<=b;i++)
#define     frd(i,a,b) for(int i=a;i>=b;i--)

const ll MN=1e9+7;
const ll MF=1e6+7;
const ll inf=1e18+7;
const ll N = 1005;
const ll H = 311;
const ll F = 1e5 + 3;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
//ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
ll sum(ll a, ll b) {return (a + b)%MN;}

ll f[2209][5605][2], n, K, a[MF];
void input()
{
    cin >> n >> K;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    const int MOD = 998244353;
    void add(ll &x, const ll &y)
    {
        x+=y;
        if(x >= MOD) x-=MOD;
    }
    void slv()
    {

        f[0][0][0] = 1;
        fr(i, 0, n - 1){
            fr(j, 0, K){
                fr(k, 0, 1){
                    if(f[i][j][k]){
                        add(f[i + 1][j][k], f[i][j][k]);
                        add(f[i + 1][j][1], f[i][j][k]);
                        if(j + a[i + 1] <= K) add(f[i + 1][j + a[i + 1]][k], f[i][j][k]);
                    }
                }
            }
        }
        ll res = 0;
        fr(j, 0, K){
            add(res, f[n][j][1]);
        }
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







