#include<bits/stdc++.h>

using namespace std;

#define ll long long int 
int main(){

    ll n,s;cin>>n>>s;
    vector<ll>cost(n);
    vector<ll>weight(n);
    for(int i=0;i<n;i++)cin>>weight[i];

    for(int i=0;i<n;i++)cin>>cost[i];
    
    vector<pair<ll,ll>>A(n);
    
    for(int i=0;i<n;i++){
        A[i]={weight[i],cost[i]};
    }
    ll ans=0,l=0,sum=0,priceSum=0;
     
    for(ll r=0;r<n;r++){
        sum+=A[r].first;
        priceSum+=A[r].second;
        while(sum>s){
            sum-=A[l].first;
            priceSum-=A[l].second;
            l++;
        }
        ans=max(ans,priceSum);
    }

   cout<<ans<<endl;

    return 0;
}