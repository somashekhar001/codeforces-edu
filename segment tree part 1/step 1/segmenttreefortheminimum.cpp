#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
public:
    vector<long long int> mins;
    int size;
    SegmentTree(int n)
    {
        size = 1;
        while (size < n)  size *= 2;
          
        mins.assign(2 * size, 0LL);
    }
    void set(int i, int v, int x, int lx, int rx)
    {
       
        if (rx - lx == 1)
        {
            mins[x] = v;
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
        mins[x] = min(mins[2 * x + 1] , mins[2 * x + 2]);
    }
    void set(int i, int v)
    {

        set(i, v, 0, 0, size);
    }
    long long int minimum(int l, int r, int x, int lx, int rx)
    {
        if (rx <= l || r <= lx)
            return long(INT_MAX);
        if (lx >= l && r >= rx)
            return mins[x];
        int mid = (lx + rx) / 2;
        return min(minimum(l, r, 2 * x + 1, lx, mid),minimum(l, r, 2 * x + 2, mid, rx));
    }
    long long int minimum(int l, int r)
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
            cout << st.minimum(l, r) << endl;
        }
    }
    return 0;
}
