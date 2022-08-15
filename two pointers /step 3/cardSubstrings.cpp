#include<bits/stdc++.h>

using namespace std;
#define ll long long int

int main(){
    ll n,m;cin>>n>>m;
    string s;cin>>s;
    unordered_map<char,ll>mp;
    for(int i=0;i<m;i++){
        char c;cin>>c;
        mp[c]++;
    }
    unordered_map<char,ll>temp;
    ll l=0,ans=0;
    for(int r=0;r<n;r++){
      temp[s[r]]++;
      while(temp[s[r]]>mp[s[r]]){
         temp[s[l]]--;
        l++;
      }
      ans+=r-l+1;
    }
   cout<<ans<<endl;
    return 0;
}