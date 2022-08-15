#include<bits/stdc++.h>

using namespace std;

#define ll long long int 
#define INF 1e18
ll n,k;
vector<ll>a;

bool good(ll mid){
  
  ll  l=0,count=1;
  
  for(int i=1;i<n;i++){
     if(a[i]-a[l]>=mid){
        count++;
        l=i;
     }
     
  }
  
  return count>=k;
}

int main(){
     
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];

    

    ll l=0,r=1e10;
    
    
    while((r-l )>1){
        ll mid=(l+r)/2;
        if(good(mid)){
            l=mid;
        }
        else{
           r=mid;
        }

    }
     cout<<l<<endl;
 
    
    return 0;
}