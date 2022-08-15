#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct item{
   long long int sum;
};
class segmenttree{
  public:
   ll size;
   vector<item>value;
   void init(ll n){
    size=1;
     while(n>size){
      size*=2;
     }
     value.resize(2*size);
   }
   
   item merge(item c,item b){
    return  { c.sum+b.sum } ;
    
   }


   void build(vector<ll>&a, ll x,ll lx, ll rx){
   
    if(rx-lx == 1){
      if(lx<a.size()){
      if(a[lx]==1){
         value[x]={1};
      }
      else{
        value[x]={0};
      }
      }
      else{
        value[x]={0};
      }
        return ;
    }
    
    ll mid=(lx+rx)/2;
    
    build(a,2*x+1,lx,mid);

    build(a,2*x+2,mid,rx);
    
    value[x]=merge(value[2*x+1],value[2*x+2]);
   
   }
   void build(vector<ll>&a){
        build(a,0,0,size);     
   }




    void set(ll v, ll x,ll lx, ll rx){
   
    if(rx-lx == 1){
        if(value[x].sum==0)value[x].sum=1;

        else value[x].sum=0;  
        return ;
    }
    
    ll mid=(lx+rx)/2;
    
    if(v<mid){
      
       set(v,2*x+1,lx,mid);
    }
    else
    {
       set(v,2*x+2,mid,rx);
    }
    value[x]=merge(value[2*x+1],value[2*x+2]);
   }
   
   void set(ll v){
   
     set(v,0,0,size);
   
   }
   ll find(ll k,ll x,ll lx,ll rx){
        if(rx-lx==1){
            return lx;
        }
        ll mid = (lx+rx)/2;
        ll val=value[2*x+1].sum;
        if(val>k){
          return find(k,2*x+1,lx,mid); 
        }
        else{
         return find(k-val,2*x+2,mid,rx);
        }
   }
   ll find(ll k){
    return find(k,0,0,size);
   }
};


int main(){
    ll n;cin>>n;
    segmenttree st;
    st.init(n);
    vector<ll>a(n),b(n,1),ans(n);
    for(int i=0;i<n;i++){
      cin>>a[i];
    
    }  
    st.build(b);

    for(int i=n-1;i>=0;i--){
       ll index=st.find(a[i]);
        ans[i]=n - index;
        st.set(index);
    } 
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
  return 0;
} 