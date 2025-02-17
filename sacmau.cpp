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


string a, b;
map<string,ll> mp;
map<ll,string> m;
void input()
{
    cin >> a >> b;
    mp["Red"] = 1;
    m[1] = "Red";
    mp["Orange"] = 2;
    m[2] = "Orange";
    mp["Yellow"] = 3;
    m[3] = "Yellow";
    mp["Green"] = -2;
    m[-2] = "Green";
    mp["Blue"] = -1;
    m[-1] = "Blue";
    mp["Purple"] = 0;
    m[0] = "Purple";
}
namespace sub1
{

    void slv()
    {
        ll value = abs(mp[a] - mp[b]);
        if(!value) cout << "Same";
        else if(value == 1 || value == 5) cout << "Adjacent";
        else if(value == 2 || value == 4){
            if(value == 2){
                cout << m[(mp[a] + mp[b])/2];
            }
            else {
                if(mp[a] == 1 && mp[b] == 5){
                    cout << m[6];
                }
                if(mp[a] == 2 && mp[b] == 6){
                    cout << m[1];
                }
            }
        }
        else cout << "Complementary";

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
    freopen("color.inp", "r", stdin);
    freopen("color.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool qs = 0;
    ll ntest = 1;
    if(qs) cin >> ntest;
    fr(i, 1, ntest){
        input();
        sub1::slv();
    }
}
