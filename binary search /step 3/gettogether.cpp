#include<bits/stdc++.h>

using namespace std;

#define ll long long int 
#define INF 1e18
ll n;
vector<pair<long double,long double>>a;

bool good(long double mid){
  
   long double maxa=-1e18,mini=1e18;

  for(auto c:a){
    long double k=c.first-(c.second*mid);
    long double m=c.first+(c.second*mid);
    maxa=max(maxa,k);
    mini=min(mini,m);
  }
  if(maxa<=mini)
  {
    return 1;
  }
  return 0;
    

}

int main(){
     
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++){
        long double x,y;
        cin>>x>>y;
        a[i]={x,y};
    }

    long double l=0,r=1e10;
    ll y=100;
    while(y){
        long double mid=(l+r)/2;
        if(good(mid)){
            r=mid;
        }
        else{
           l=mid;
        }
        y--;
        
    }
     cout<<setprecision(20)<<r<<endl;
 
    
    return 0;
}