#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

ll n,k;
vector<ll>a;
bool good(double x){
    double sum=0;
    for(double c:a){
       sum+= floor(c/x) ;
    }
    return sum>=k;
}

int main(){
  cin>>n>>k;
  a.resize(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  double l=0,r=1e8;

  while((r-l)>=1e-6)
  {
    double mid=(l+r)/2;
    if(good(mid)){
        l=mid;
    }
    else{
        r=mid;
    }
  }
  cout<<setprecision(20)<<l<<endl;
  return 0;
}