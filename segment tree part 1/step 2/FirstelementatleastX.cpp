#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct item{
   long long int sum;
};
class segmenttree{
  public:
   ll size;
   ll o;
   vector<item>value;
   void init(ll n){
    size=1;
    o=n;
     while(n>size){
      size*=2;
     }
     value.resize(2*size);
   }
   
   item merge(item c,item b){
   
        return {max(c.sum,b.sum)};
   }


   void build(vector<ll>&a, ll x,ll lx, ll rx){
   
    if(rx-lx == 1){
      if(lx<a.size()){
        value[x]={a[lx]};
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




    void set(ll i,ll v, ll x,ll lx, ll rx){
   
    if(rx-lx == 1){
        value[x]={v};
        return ;
    }
    
    ll mid=(lx+rx)/2;
    
    if(i<mid){
      
       set(i,v,2*x+1,lx,mid);
    }
    else
    {
       set(i,v,2*x+2,mid,rx);
    }
    value[x]=merge(value[2*x+1],value[2*x+2]);
   }
   
   void set(ll i,ll v){
   
     set(i,v,0,0,size);
   
   }
   ll find(ll k,ll x,ll lx,ll rx){
        if(value[x].sum < k)return -1;

        if(rx-lx==1){
          return lx;
        }
        ll mid = (lx+rx)/2;
        ll val=find(k,2*x+1,lx,mid);
        if(val== -1){
            val = find(k,2*x+2,mid,rx);       
        }
        return val;
   }
   ll find(ll k){
    return find(k,0,0,size);
   }
};


int main(){
    ll n,m;cin>>n>>m;
    segmenttree st;
    st.init(n);
    vector<ll>a(n);
    for(int i=0;i<n;i++){
      cin>>a[i];
    }  
    st.build(a);
    
    while(m--){
      ll q;cin>>q;
      if(q==1){
        ll i,v;cin>>i>>v;
        st.set(i,v);
      }
      else{
        ll v;cin>>v;
       cout<<st.find(v)<<endl;
      }
    }
  return 0;
} 