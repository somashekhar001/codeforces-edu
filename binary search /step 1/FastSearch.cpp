#include<bits/stdc++.h>

using namespace std;
#define ll long long int
int main(){
    ll n,k;cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    
    cin>>k;
    sort(a.begin(),a.end());

    while(k--){
        ll c,d,ans;cin>>c>>d;
        ll l=-1,r=n;
        while(l+1<r){
            ll m=(l+r)/2 ;
            if(a[m]<c){
               l=m;
            }
            else{
                r=m;
            }
        }
        ans=r+1;
        l=-1,r=n;
        while(l+1<r){
            ll m=(l+r)/2 ;
            if(a[m]<=d){
               l=m;
            }
            else{
                r=m;
            }
        }
       
        ans=r+1-ans;
        cout<<ans<<" ";
    
    }
    cout<<endl;

    return 0;
}