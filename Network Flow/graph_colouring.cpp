#include <iostream>
#include <vector>
using namespace std;
int N;
bool issafe(vector<vector<int>> graph, vector<int>& colour,int node,int c){
    for(int i=0;i<N;i++){
        if( graph [node][i] && c==colour[i]){
            return false;
        }
    }
        return true;
}
bool solve(vector<vector<int>> graph, vector<int>& colour,int M,int node){
    if(node==N){
        return true;
    }
    for(int c=1;c<=M;c++){

        if(issafe(graph,colour,node,c)){
            colour[node]=c;

            if(solve(graph,colour,M,node+1)){
                return true;
            }

            colour[node]=0;

        }
    }
    return false;

}

int main(){
    int M,E;
    cin>>N>>M>>E;

    vector<vector<int>> graph(N,vector<int>(N,0));
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
    }
    vector<int> colour(N,0);

    if(solve(graph,colour,M,0)){
        cout<<"it is possible to color the graph "<<endl;
    }else{
        cout<<"it is not possile"<<endl;
    }


    return 0;
}

