#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
public:
    vector<long long int> sums;
    int size;
    SegmentTree(int n)
    {
        size = 1;
        while (size < n)  size *= 2;
          
        sums.assign(2 * size, 0LL);
    }
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx == 1){
            if(lx<a.size())sums[x]=a[lx];

            return;
        }
        int mid= (lx+rx)/2;
        build(a,2*x+1,lx,mid);
        build(a,2*x+2,mid,rx);
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }

   void build(vector<int>&a){
    build(a,0,0,size);
   }







    void set(int i, int v, int x, int lx, int rx)
    {
       
        if (rx - lx == 1)
        {
            sums[x] = v;
            return;
        }
        int mid = (rx + lx) / 2;
        if (i < mid)
        {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else
        {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }
    void set(int i, int v)
    {

        set(i, v, 0, 0, size);
    }
    long long int sum(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || r <= lx)
            return 0;
        if (lx >= l && r >= rx)
            return sums[x];
        int mid = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, mid) + sum(l, r, 2 * x + 2, mid, rx);
    }
    long long int sum(int l, int r)
    {
       
         return sum(l, r, 0, 0, size);
    }
    
};
int main()
{
    int n;
    cin >> n;

    SegmentTree st(n);
     vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
   
    
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int sum=0;
        sum=st.sum(a[i],n);
        ans[i]=sum;   
        st.set(a[i]-1,1);  
            
    }
    for(auto c:ans)cout<<c<<" ";

    cout<<endl;
    return 0;
}
