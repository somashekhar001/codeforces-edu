#include<bits/stdc++.h>

using namespace std;

#define ll long long int
int main(){
    ll n,k;cin>>n>>k;
    vector<ll>a(n);
    vector<ll>b(n-1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    for(int i=1;i<n;i++){
        b[i-1]=a[i]-a[i-1];
    }
    ll x=0, ans=0,l=0;
    for(ll r=0;r<n-1;r++){
      x+=b[r];
      while(x>k){
        x-=b[l];
       l++;
      }
      ans+=l;
    }
    cout<<ans<<endl;
    return 0;
}