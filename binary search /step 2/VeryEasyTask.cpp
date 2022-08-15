#include<bits/stdc++.h>

using namespace std;

#define ll long long int 

ll n,x,y;

bool good(ll mid){

    return (mid/x)+(mid/y) >= (n-1);
}

int main(){
     
    cin>>n>>x>>y;
    
    ll l=0,r=1;
    ll ans=min(x,y);
     if(n==1){
        cout<<ans<<endl;
        return 0;
     }
    while(!good(r))r*=2;
    while(l+1<r){
        
        ll mid=(l+r)/2;
        
        if(good(mid)){
            r=mid;
        }
        else{
            l=mid;
        }   
 
    }
    cout<<r+ans<<endl;
    
    return 0;
}