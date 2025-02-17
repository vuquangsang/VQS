#include<bits/stdc++.h>
using namespace std ;

const int N = 2e5+5 ;
int n ;
long long  a[N] ;
void doc()
{
    cin>> n ;
    for(int i=1;i<=n;i++) cin >> a[i] ;
}
namespace sub1
{
    int f[N] ;
    void xuly()
    {
        for(int i=1;i<=n;i++)
        {
            f[i] = 1;
            for(int j=1;j<=i-1;j++)if(a[j]<a[i])f[i] = max(f[i],f[j]+1) ;
        }
        cout<<*max_element(f+1,f+n+1) ;
    }
}
namespace sub2
{
    int f[N] ;
    int bit[N] ;
    void up(int id , int val)
    {
        for(int i=id;i<=n;i+=i&-i)bit[i]=max(bit[i],val) ;
    }
    int get(int id)
    {
        int ans = 1 ;
        for(int i=id;i;i-=i&-i)ans=max(ans,bit[i]+1) ;
        return ans ;
    }
    void xuly()
    {
        vector<long long >V ;
        for(int i=1;i<=n;i++)V.push_back(a[i]) ;
        sort(V.begin(),V.end()) ;
        V.resize(unique(V.begin(),V.end())-V.begin()) ;
        for(int i=1;i<=n;i++)a[i]=upper_bound(V.begin(),V.end(),a[i])-V.begin() ;

        for(int i=1;i<=n;i++)
        {
            f[i] = get(a[i]-1) ;
            up(a[i],f[i]) ;
        }
        cout<<*max_element(f+1,f+n+1) ;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("LIS.INP","r",stdin);
    freopen("LIS.ANS","w",stdout);
    doc() ;
    sub1::xuly() ;
    // else sub2::xuly() ;
}
