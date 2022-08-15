#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;

#define PB push_back
#define MP make_pair
#define F first
#define S second

const ll MOD=1000000007;

/*void readInputFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}*/



void solve(){
  
  ll n,m;cin>>n>>m;

  vector<ll>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  while(m--){
      ll x;cin>>x;
      ll l=0,r=n;
      while(l+1<r){
        ll mid=(l+r)/2;
        if(v[mid]<=x){
            l=mid;
        }
        else{
            r=mid;
        }
      }
      if(v[l]==x)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
  }


}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //readInputFile();
  solve();
 
 return 0;
}