    #include<bits/stdc++.h>
    using namespace std;
     
    #define ll long long int
     
     
    class segmenttree{
     
      public:
        vector<ll>value;
        ll size;
        void init(ll n){
            size=1;
            while(size<n) size*=2;
            value.assign(size*2,0LL);
        }    
        void set(ll v ,ll l,ll r,ll x,ll lx,ll rx){
             if(lx>=r || rx<=l) return ;
             if(lx>=l && rx<=r) {
                value[x]=max(value[x],v);
                return;
             }
            ll mid=(lx+rx)/2;
     
            set(v,l,r,2*x+1,lx,mid);
            set(v,l,r,2*x+2,mid,rx);
            
        }
        void set(ll l,ll r,ll v){
            set(v,l,r,0,0,size);
        }
        ll get (ll i,ll x,ll lx,ll rx){
            if((rx-lx)==1){
                return value[x];
            }
     
            ll mid=(lx+rx)/2;
             ll res;
            if(i<mid){
               res=get(i,2*x+1,lx,mid);
            }
            else{
                res=get(i,2*x+2,mid,rx);
            }
            return max(res,value[x]);
        }
        ll get(ll i){
            return get(i,0,0,size);
        }
    };
     
     
     
     
     
    int main(){
        ll n,m;cin>>n>>m;
        segmenttree st;
        st.init(n);
        while(m--){
            ll op;cin>>op;
            if(op==1){
              ll l,r,v;cin>>l>>r>>v;
              st.set(l,r,v);
            }
            else{
             ll i;cin>>i;
             cout<<st.get(i)<<endl;
            }
        }
        return 0;
    }