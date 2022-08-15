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
   
    private: vi p,rank,setsize; //p=pointer vector
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
    bool issameset(int i,int j){
        // both have same leader element
         return findset(i)==findset(j);
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
        if(rank[x]==rank[y]){
            rank[y]++;
        }
        setsize[y] +=setsize[x];
        numsets--;
    }
    // size of set of  element i belong to

    int sizeofset(int i){
        return setsize[findset(i)];
    }
    // number of sets being maintained currently

    int numdisjointset(){
        return numsets;
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
      cin>>u>>v;

      if(s=="union"){

        uf.unionset(u,v);
      }
      else{
          if(uf.issameset(u,v)){
             cout<<"YES"<<endl;
          }
          else{
              cout<<"NO"<<endl;
          }
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