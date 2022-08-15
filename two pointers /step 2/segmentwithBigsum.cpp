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
     
     
    void solve(){
     
       ll n,m; cin>>n>>m;
       vi A(n);
       for(int i=0;i<n;i++){
        ll x;cin>>x;
         A[i]=x;
       }
       ll l=0;ll sum=0,ans=INT_MAX;
       for(int r=0;r<n;r++){
        sum+=A[r];
        while(sum-A[l]>=m){
            sum-=A[l];
            l++;
        }
        if(sum>=m){
            ans=min(ans,r-l+1);
        }
       }
       if(ans==INT_MAX){
        ans=-1;
       }
     
       cout<<ans<<endl;
          
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