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


struct dataa
{
    ll u, id;
};
dataa a[MF], x[MF];
ll n, m;
bool cmp(dataa a, dataa b) {return a.u < b.u;}
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i].u , a[i].id = i;
    cin >> m;
    fr(i, 1, m) cin >> x[i].u , x[i].id = i;
    sort(alla(a, n), cmp);
    sort(alla(x, m), cmp);
}
namespace sub1
{

    ll f[4*N][4*N], r[MF];
    void slv()
    {
        fr(i, 0, n) fr(j, 0, m) f[i][j] = inf;
        f[0][0] = 0;
        fr(i, 1, n) f[i][i] = f[i - 1][i - 1] + abs(a[i].u - x[i].u);
        fr(i, 1, n) cout << f[i][i] << " "; return ;
        fr(i, 1, n) fr(j, 1, i - 1) {
            f[i][j] = min(abs(a[i].u - x[j].u) + f[i - 1][j - 1], abs(a[i].u - x[j].u) + f[i - 1][j]);
        }
        cout << f[n][m] << el;
        ll i = n, j = m;
        while(i && j) {
            r[a[i].id] = x[j].id;
            if(f[i][j] == f[i - 1][j - 1] + abs(a[i].u - x[j].u)) {
                i--;j --;
            }
            else i--;
        }
        fr(i, 1, n) cout << r[i] << " ";
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


