#include<bits/stdc++.h>

using namespace std;

#define ll long long int 
#define INF 1e18
ll n,k;
vector<ll>a;

bool good(ll mid){
    
  ll sum=0,count=1;
  
  for(auto c:a){
     sum+=c;
     if(c>mid)return 0;
     if(sum>mid){
        count++;
        sum=c;
     }
     if(count > k) return 0;
  }
  

  return 1;

}

int main(){
     
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];

    

    ll l=0,r=1;
    while(!good(r))r*=2;
    
    while((r-l )>1){
        ll mid=(l+r)/2;
        if(good(mid)){
            r=mid;
        }
        else{
           l=mid;
        }
    
     
    }
     cout<<r<<endl;
 
    
    return 0;
}