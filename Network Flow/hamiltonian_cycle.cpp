#include <iostream>
#include <vector>
#include <string>
using namespace std;
int M,N,K;
bool util(vector<vector<char>> board,string word,int index,int row,int col,int n){
    if(index==n){
        return true;
    }
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(!( i==0 && j==0)){
                int newro=row+i;
                int newco=col+j;

                if(newro>=0 && newro<M && newco>=0 && newco<N && word[index]==board[newro][newco]){
                    if(util(board,word,index+1,newro,newco,n)){
                        return true;
                    }

                }
            }
        }
    }
    return false;

}
void solve(vector<vector<char>> board,string word, vector<string>& ans){
    int n=word.length();

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(word[0]==board[i][j]){
                if(util(board,word,1,i,j,n)){
                    ans.push_back(word);
                    return ;
                }
            }
        }
    }
    
}

int main(){
    
    cin>>M>>N>>K;
    vector<string> dict;
    for(int i=0;i<K;i++){
        string x;
        cin>>x;
        dict.push_back(x);
    }
    vector<vector<char>> board;
    for(int i=0;i<M;i++){
        vector<char> temp;
        for(int j=0;j<N;j++){
            char c;
            cin>>c;
            temp.push_back(c);

        }
        board.push_back(temp);
    }
    vector<string> ans;
    for(int i=0;i<K;i++){
        solve(board,dict[i],ans);
    }
    cout<<"the result is "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    
    return 0;
}