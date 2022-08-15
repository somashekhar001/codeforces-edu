    #include<bits/stdc++.h>
     
    using namespace std;
     
    int main(){
        int n,k;cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        unordered_map<int,int>cnt;
        long long int ans=0,l=0,num=0;
        for(int r=0;r<n;r++){
     
                    cnt[a[r]]++;
            if(cnt[a[r]]==1)num++;
            while(num>k){
              cnt[a[l]]--;
              if(cnt[a[l]]==0)num--;
              l++;
            }
     
            ans+=r-l+1;
        }
        cout<<ans<<endl;
        return 0;
    }