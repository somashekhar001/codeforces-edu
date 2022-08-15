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
class unionfind{
   
    private: vi p,rank,setsize,maxset,minset; //p=pointer vector
         int numsets;
    public:
    //Intitialization
    unionfind(int N){
     
      //create N singleton sets
      p.assign(N,0);

      //to begin with everyone is there own parent

      for(int i=0;i<N;i++){
          p[i]=i;
      }
      // the height of all trees are zero
      rank.assign(N,0);

      // the sizes of individual sets are one

      setsize.assign(N,1);
      
      maxset.assign(N,0);

      minset.assign(N,0);
       for(int i=0;i<N;i++){
          maxset[i]=i;
          minset[i]=i;
      }
      //number of sets is N 
      
      numsets=N;

    }
    // findset find the leader of set of that i belongs to
    int findset(int i){
     
    //if already at leader element
    //fact is parent pointer points to element itself
      if(p[i]==i){
          return i;
      }
    // otherwise find leader element and do path compression 
    // by pointing the current element to leader element
      else{
          return p[i]=findset(p[i]);
      }
    }
   
    void unionset(int i,int j)
    {
        if(issameset(i,j))
        {
            return;
        }
        int x=findset(i);
        int y=findset(j);
        if(rank[x]>rank[y]){
            swap(x,y);
        }
        p[x]=y;
        maxset[y]=max(maxset[x],maxset[y]);
        minset[y]=min(minset[x],minset[y]);
        if(rank[x]==rank[y]){
            rank[y]++;
        }
        setsize[y] +=setsize[x];
        numsets--;
    }


     bool issameset(int i,int j){
        // both have same leader element
         return findset(i)==findset(j);
    }
    // size of set of  element i belong to

    int sizeofset(int i){
        return setsize[findset(i)];
    }
    // number of sets being maintained currently

    int numdisjointset(){
        return numsets;
    }
    
    int maxinset(int i){
        return maxset[findset(i)];
    }
    int mininset(int i){
        return minset[findset(i)];
    } 

};
void solve(){

  int n,m ; cin>>n>>m;

  unionfind uf(n+1);

  while(m--)
  {
      int u,v;
      string s;
      cin>>s;

      if(s=="union"){
         cin>>u>>v;
        uf.unionset(u,v);
      }
      else{
          cin>>u;
          cout<<uf.mininset(u)<<" "<<uf.maxinset(u)<<" "<<uf.sizeofset(u)<<endl;
        
      }
  }





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