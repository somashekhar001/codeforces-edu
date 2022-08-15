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
     
     ll n,m; cin>>n>>m;
       vi A(n);
       vi B(m);
       for(int i=0;i<n;i++){
        ll x;cin>>x;
         A[i]=x;
       }
       for(int i=0;i<m;i++){
        ll x;cin>>x;
         B[i]=x;
       }
       vi ans;
       ll x=0,y=0;
       for(int i=0;i<m;i++){
          while(A[y]<B[i] && y<n){
            y++;
          }
          ans.PB(y);
        
       }
       for(auto c:ans)cout<<c<<" ";
        
         cout<<endl;
       
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