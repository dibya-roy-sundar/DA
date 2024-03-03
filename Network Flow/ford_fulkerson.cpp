# include <iostream>
#include<cstring>
#include <queue>
using namespace std;
#define V 6

int bfs(int rgraph[V][V],int s , int t,int parent[]){
    queue<int> q;
    int vis[V]={0};
    q.push(s);
    vis[s]=1;
    // parent[s]=-1;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(node==t){
            return  true;
        }

        for(int i=0;i<V;i++){
            if(!vis[i] && rgraph[node][i]>0 ){// if the node is not visited and from the current node to that node
            // if there exists some capacity  we can go through this path 
                    


                q.push(i);
                vis[i]=1;//visited mark inside this because of the decrease the no of items push to the queue
                parent[i]=node;


            }
        }
    }
    return false;

}

int fordFulkerson(int graph[V][V],int s , int t){
    // we have to secure original data , we have to form a residual graph from original data
        int rgraph[V][V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                rgraph[i][j]=graph[i][j];
            }
        }

        int maxflow=0;

    // 1.find augmented path
        //   i) ford fulkerson-using dfs
        //   ii)edmond karp-using bfs
    // we need to store the augmented path as well as find bottleneck through the path
    // to store the augmented path we will use parent array 
    int parent[V];
    // now after bfs we store the augmented path into parent array
    while(bfs(rgraph,s,t,parent)){
        // if true , we find an augmented path
    //  2.find  bottleneck throughout the augmented path
        int bottleneck=1e9;
        for(int i=t;i!=s;i=parent[i]){
            // reverse backward     
            int v=i;
            int u=parent[v];
            bottleneck=min(bottleneck,rgraph[u][v]);
        }
    // 3. update the residual graph based on our bottleneck;
         for(int i=t;i!=s;i=parent[i]){
            // reverse backward 
            int v=i;
            int u=parent[v];
            // u se v ja rahe hai , so minus the bottleneck from the capacity = remaining capacity
           rgraph[u][v]-=bottleneck;
           
            // add the bottleneck to the  reverse of it - add the capacity 
           rgraph[v][u]+=bottleneck;
           
        }
    //4.add the bottleneck to the maxflow
        maxflow+=bottleneck;
    //5.now the residual graph is updated , based upon the graph and updated capacity / flow graph , we
    // will find new augmented path from src to sink and repeat the process untill we would not get any new augmented path
    // for every iteration , this is confirm that the augmented path will be different because , after minus bottleneck from capacity 
    // any of the edge's capacity will be 0 from the above path , in next iteration , that node wouldn't be pushed into queue and wouldn't be
    //  a part of our new augmented path
    }
    return maxflow; 
   
}



int main(){
    // int u,k;
    // cout<<"enter your graph size"<<endl;
    // cin>>u,k;
    // int graph[u][k]={0};
    // // memset(graph ,0 , sizeof(graph));
    // while(u){
    //     cout<<"enter "<<u <<" row details"<<endl;
    //     for(int i=0;i<k;i++){
    //         int x;
    //         cout<<"enter x"<<endl;
    //         cin>>x;
    //         graph[u][i]=x;

    //     }

    //     u--;
    // }
    // int s,t;
    // cout<<"Enter source"<<endl;
    // cin>>s;
    // cout<<"Enter Sink"<<endl;
    // cin>>t;
    int graph[V][V]
        = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
 
    cout << "The maximum possible flow is "
         << fordFulkerson(graph, 0, 5);

    return 0;
}