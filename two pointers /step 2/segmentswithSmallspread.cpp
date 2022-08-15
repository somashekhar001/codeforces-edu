    #include<bits/stdc++.h>
     
    using namespace std;
     
    struct stack{
      vector<long long int>s,smax{LLONG_MIN},smin{LLONG_MAX};
      void push(long long int x){
        s.push_back(x);
        smin.push_back(::min(smin.back(),x));
        smax.push_back(::max(smax.back(),x));
      }
      long long int pop(){
        long long int ans=s.back();
        s.pop_back();
        smax.pop_back();
        smin.pop_back();
        return ans;
      }
      bool empty(){
        return s.empty();
      }
      long long int max(){
        return smax.back();
      }
      long long int min(){
        return smin.back();
      }
     
    };
    ::stack s1 , s2;
    void add(long long int x){
        s2.push(x);
    }
    void remove(){
        if(s1.empty()){
            while(!s2.empty()){
                s1.push(s2.pop());
            }
        }
        s1.pop();
    }
    long long int k;
    bool good(){
        long long int mn=min(s1.min(),s2.min());
        long long int mx=max(s1.max(),s2.max());
     
        return mx - mn <= k ;
    }
    int main(){
        int n;cin>>n>>k;
        vector<long long int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        
        long long int ans=0;int l=0;
     
        for(int r=0;r<n;r++){
           add(a[r]);
           while(!good()){
            remove();
            l++;
           }
           ans+=r-l+1;
        }
        cout<<ans<<endl;
        return 0;
    }