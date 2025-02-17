#include <bits/stdc++.h>
using namespace std;

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

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(ll l,ll r) {return l+rd()%(r-l+1);}
void chay()
{

}
void booster()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}

struct init
{
    ll fi,se;
};

ll q,n;
string s;
void input()
{
    cin>>q;
}
void slv()
{
    while(q--){
        cin>>n;
        cin>>s;
        ll sz=s.size()-1;
        char tmp1='c',tmp2='c';
        fr(i,0,sz/2){
            if(s[i]!=s[sz-i]){
                tmp1=s[i];
                tmp2=s[sz-i];
                break;
            }
        }
        if(tmp1==tmp2){
            cout<<s<<el;
            continue;
        }
        if(tmp1>tmp2){
            if(n%2==0){
                string tmp=s;
                reverse(all(s));
                cout<<s;
                cout<<tmp<<el;
            }
            else{
                cout<<s<<el;
            }
        }
        else{
            if(n%2==0){
                cout<<s<<el;
            }
            else{
                string tmp=s;
                reverse(all(s));
                cout<<s;
                cout<<tmp<<el;
            }
        }
    }
}
void dif()
{
    ll mul=1;
    fr(i,1,mul){
        chay();
        ll tmp1=0;
        ll tmp2=0;
        if(tmp1!=tmp2){
            cout<<1;
            return;
        }
        else{
            cout<<1;
            return;
        }
    }
}
main()
{
    booster;
    bool qs=0;
    bool trollvn=0;
    if(trollvn) dif();
    ll ntest=1;
    if(qs) cin>>ntest;
    fr(i,1,ntest){
        input();
        slv();
    }
}


