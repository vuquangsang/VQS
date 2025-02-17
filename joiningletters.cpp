/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll int
#define     fi first
#define     se second
#define     Mask(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     REP(i, a, b) for(int i = (a), _b = (b); i < _b; i++)
#define     BIT(msk, i) (msk&(1 << i))

const int MF = 15*1e4;

string s;
int n;
void input()
{
    s = ' ' + s;
    n = s.size() - 1;
}
namespace sub1
{

    int f[MF][5];
    void slv()
    {
        fr(i, 1, n) fr(j, 1, 4) f[i][j] = 0;
        fr(i, 1, n) {
            if(s[i] == 'I') f[i][1] = 1;
        }
        ll ans = 0;
        fr(i, 2, n) {
            ans+=f[i - 2][1];
            if(s[i] == 'C') f[i][2] = ans;
        }
        ans = 0;
        fr(i, 2, n) {
            ans+=f[i - 2][2];
            if(s[i] == 'P') f[i][3] = ans;
        }
        ans = 0;
        fr(i, 2, n){
            ans+=f[i - 2][3];
            if(s[i] == 'C') f[i][4] = ans;
        }
        ll res = 0;
        fr(i, 1, n) res+=f[i][4];
        cout << res << el;
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
    #define TASK "joiningletters"
   // #define TASK "task"
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
    while(cin >> s){
        if(s[0] == '$') return 0;
        input();
        sub1::slv();
    //    sub2::slv();
    }
}



