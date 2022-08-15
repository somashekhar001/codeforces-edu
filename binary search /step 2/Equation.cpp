#include<bits/stdc++.h>

using namespace std;

#define ll long long int 

double n;

bool good(double mid){

      return (mid*mid)+(sqrt(mid)) >= n;
}

int main(){
     
    cin>>n;
    double l=0,r=1e10;

    while((r-l)>1e-8){
        double mid=(l+r)/2;
        if(good(mid)){
            r=mid;
        }
        else{
           l=mid;
        }
    }
    cout<<setprecision(20)<<r<<endl;

    
    return 0;
}