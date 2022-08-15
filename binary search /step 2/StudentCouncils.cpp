#include<bits/stdc++.h>

using namespace std;

#define ll long long int 

ll n,k;
vector<ll>a;

bool good(ll mid){

      ll slots=k*mid;
      for(auto c:a){
        slots -= min(mid,c);
      }
      return slots<=0;

}

int main(){
     
    cin>>k>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];

    ll l=-1,r=1;
    while(good(r))r*=2;

    while((r-l)>1){
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