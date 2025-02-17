#include <bits/stdc++.h>
using namespace std;

#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     fr(i,a,b) for(int i=a;i<=b;i++)
#define     frd(i,a,b) for(int i=a;i>=b;i--)
const ll MN=1e9+7;
const ll MF=1e6+7;
const ll inf=1e18+7;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};

namespace sub
{

}

ll q , n,string s;
map<char,ll> mp;
void input()
{
    cin >> q;
}
void slv()
{
    while(q--) {
        cin >> n;
        cin >> s;
        s = ' ' + s;
        if (n < 2){
            cout << "NO" << el;
            continue ;
        }
        if(n == 2){
            if(s[1] == s[2] == '0'){
                cout << "YES" << el;
            }
            else{
                cout <<  "NO" << el;
            }
            continue ;
        }
        fr(i, 3, n){
            if(s[i] == '1') {
                mp[s[i]]--;
            }
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool qs=0;
    ll ntest=1;
    if(qs) cin>>ntest;
    fr(i,1,ntest){
        input();
        slv();
    }
}


