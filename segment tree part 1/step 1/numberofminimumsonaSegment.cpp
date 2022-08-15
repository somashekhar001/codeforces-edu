#include <bits/stdc++.h>
using namespace std;

 struct item{
        int m,c;
 };

class SegmentTree
{
public:
    vector<item> mins;
    int size;
    item Neutral={INT_MAX,0};
    SegmentTree(int n)
    {
        size = 1;
        while (size < n)  size *= 2;
          
        mins.resize(2 * size);
    }
    item merge(item a,item b){
       if(a.m<b.m)return a;
       if(a.m>b.m)return b;
       return {a.m,a.c+b.c};
    }
    void set(int i, int v, int x, int lx, int rx)
    {
       
        if (rx - lx == 1)
        {
            mins[x].m = v;
            mins[x].c = 1;
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
       mins[x]=merge(mins[2*x+1],mins[2*x+2]);
    }
    void set(int i, int v)
    {

        set(i, v, 0, 0, size);
    }
    item minimum(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || r <= lx)
            return Neutral;
        if (lx >= l && r >= rx)
            return mins[x];
        int mid = (lx + rx) / 2;
        item s1=minimum(l, r, 2 * x + 1, lx, mid);
        item s2=minimum(l, r, 2 * x + 2, mid, rx);
         return merge(s1,s2);
         
    }
    item minimum(int l, int r)
    {
       
         return minimum(l, r, 0, 0, size);
    }
    
};
int main()
{
    int n, m;
    cin >> n >> m;

    SegmentTree st(n);

    for (int i = 0; i < n; i++)
    {
        long long int v;
        cin >> v;
        st.set(i, v);
    }
    
    while (m--)
    {
        int q;
        cin >> q;   
        if (q == 1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
         
            int l, r;
            cin >> l >> r;
            item x=st.minimum(l, r);
            cout << x.m <<" "<<x.c <<endl;
        }
    }
    return 0;
}
