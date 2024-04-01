#include <iostream>
#include<vector>
using namespace std;
 int M,N;

bool bpm(vector<vector<int>> bpgraph,vector<int>& jobmatch,vector<bool>& vis,int i){// we search job for ith applicant 
// ith applicant come here to find job 

// i)if the applicant get a job they will be assigned to that job and return true;
// ii)if the applicant wants to apply a particular job but the job is assigned to other applicant ,we will go to 
    // that applicant and find if they have another possibilities to get a job , so we will assign that applicant
    //  to the available job for that applicant , the previous applicant will be assigned to the curent job
    //  or         if that applicant won't get any other job , the current applicant will go for next iteartion/job 
    // searching , if after whole iteration /job searcong the current applicant wouldn;t get any job we will return false
    // that means , we wouldn't increase the no of applicants getting job(result);
    for(int j=0;j<N;j++){
        if(bpgraph[i][j] && !vis[j]){//ith applicant wants to apply jth job and not applied to jth job
            vis[j]=1;//apply to jth job
            if(jobmatch[j]<0 || bpm(bpgraph,jobmatch,vis,jobmatch[j])){ //if jth job is  not assigned to anyone -1 , ith appl will be  assigned to jth
            //  job and retutn true
            

                jobmatch[j]=i;
                return true;

            }
        }
    }
    //  he applied to all interested jobs , but wouldn't get any jobs /return true
    return false;
    
}
int maxbpm(vector<vector<int>> bpgraph){


        int result=0;
        vector<int> jobmatch(N,-1);//-1 means this particular job is available or this job is not assigned to anyone
    for(int i=0;i<M;i++){
        vector<bool> vis(N,0);//1 means ith applicant have apllied to that particular job
        //  0 means ith applicant haven't interested to apply that particular job
        if(bpm(bpgraph,jobmatch,vis,i)){//return true means this applicant get a job 
            result++;
        }
    }
    return result;

}


int main(){
   
    cin>>M>>N;
    vector<vector<int>> bpgraph;
    // (M,vector<int>(N,0));
    // int E;
    // for(int i=0;i<E;i++){
    //     int appl,job;
    //     cin>>appl>>job;
    //     bpgraph[appl][job]=1;
    // }
    for(int i=0;i<M;i++){
        vector<int> temp;
        for(int j=0;j<N;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        bpgraph.push_back(temp);

    }
    cout<<"the maximum no of applicants that can get job "<<maxbpm(bpgraph);

    return 0;
}