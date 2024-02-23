#include <iostream>
#include <vector>
using namespace std;

class disjoint{
vector<int> rank,parent,size;
public:
disjoint(int n){
    // 1 based node
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }
}
int findUParent(int u){
    // base case -- ultimate parent
    if(u==parent[u]){
        return u;
    }

    return parent[u]=findUParent(parent[u]);
}
void unionByRank (int u,int v){
    int up_u=findUParent(u);
    int up_v=findUParent(v);

    if(up_u==up_v){
        return ;
    }
    if(rank[up_u]<rank[up_v]){
        parent[up_u]=up_v;
    }else if(rank[up_u]>rank[up_v]){
        parent[up_v]=up_u;
    }else{
        parent[up_v]=up_u;
        rank[up_u]++;
    }

}
void unionBySize (int u,int v){
    int up_u=findUParent(u);
    int up_v=findUParent(v);

    if(up_u==up_v){
        return ;
    }
    if(size[up_u]<size[up_v]){
        parent[up_u]=up_v;
         size[up_v]+=size[up_u];
    }else{
        parent[up_v]=up_u;
        size[up_u]+=size[up_v];
    }

}
};
int main(){
    disjoint ds(7);
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // ds.unionByRank(5,6);
    // // check for connection of 3  and  7
    // if(ds.findUParent(3)==ds.findUParent(7)){
    //     cout<<"connected"<<endl;
    // }else{
    //     cout<<"not connected"<<endl;
    // }
    // ds.unionByRank(3,7);
    //  if(ds.findUParent(3)==ds.findUParent(7)){
    //     cout<<"connected"<<endl;
    // }else{
    //     cout<<"not connected"<<endl;
    // }
     ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    // check for connection of 3  and  7
    if(ds.findUParent(3)==ds.findUParent(7)){
        cout<<"connected"<<endl;
    }else{
        cout<<"not connected"<<endl;
    }
    ds.unionBySize(3,7);
     if(ds.findUParent(3)==ds.findUParent(7)){
        cout<<"connected"<<endl;
    }else{
        cout<<"not connected"<<endl;
    }
    return 0;
}