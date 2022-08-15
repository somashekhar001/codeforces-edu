#include<bits/stdc++.h>

using namespace std;
#define ll long long int
int main(){
    ll n,k;cin>>n>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    while(k--){
        ll d;cin>>d;
        ll l=-1,r=n;
        while(l+1<r){
            ll m=(l+r)/2 ;
            if(a[m]<=d){
               l=m;
            }
            else{
                r=m;
            }
        }
        cout<<l+1<<endl;
    }


    return 0;
}