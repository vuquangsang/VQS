#include <bits/stdc++.h>
using namespace std;

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
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
ll sum(ll a, ll b) {return (a + b)%MN;}

ll n, m;
ll c[MF], d[MF];
void input()
{
    cin >> n >> m;
    fr(i, 1, n) cin >> c[i];
    fr(i, 1, n) cin >> d[i];
}
namespace sub1
{
    ll f[2210][5606];
    void slv()
    {
        fr(i, 0, n + 1){
            fr(j, 0, m + 1){
                f[i][j] = 0;
            }
        }
        ll res = 0;
        fr(i, 1, n){
            fr(j,  1, m){
                if(j >= c[i]){
                    f[i][j] = max(f[i - 1][j] , f[i - 1][j - c[i]] + d[i]);
                }
                else{
                    f[i][j] = f[i - 1][j];
                }
            }
        }
        fr(i, 1, n){
            fr(j, 1, m){
                res = max(res, f[i][j]);
            }
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("knapsack.inp", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    bool qs = 0;
    ll ntest = 1;
    if(qs) cin >> ntest;
    fr(i, 1, ntest){
        input();
        sub1::slv();
    }
}







