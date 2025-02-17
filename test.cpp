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

#define TASK "task"
ll rd(ll l, ll r)
{
    return l + 1LL*rand()*rand()%(r - l + 1);
}
void input()
{
    ofstream cout(TASK".INP");
    ll n = rd(5, 10);
    cout << n << el;
    fr(i, 1, n) cout << rd(5, 10) << " ";

    cout.close();
}
namespace sub1
{


    void slv()
    {

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
    srand(time(0));
    int mtt = 10;
    fr(i, 1, mtt){
        input();
        system(TASK"_trau.exe");
        system(TASK".exe");
        if(system("fc " TASK ".OUT " TASK".ANS") != 0) {
            cout << "Test" << " " << i << " " << "WA";
            return 0;
        }
        cout << "Test" << " " << i << " " << "AC" << "\n";
    }
}

