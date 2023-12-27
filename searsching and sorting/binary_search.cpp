# include <iostream>
# include <vector>
# include <bits/stdc++.h>
using namespace std;
int binary( int arr[], int size , int key){
    // condition of binary search is the array should be monotonic function i.e increasing or decreasing
    // in this solution we assume our array is  sorted in increasing order
    int s=0;
    int e=size-1;
    // int mid=(s+e)/2;
    //  optimisation-if the input array size is grater than the range of int then this formula would fail 
    // so we should try new optimise formula
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }
        // if greater than mid we will search in right part 
        if(key>arr[mid]){
            s=mid+1;
        }else{
            // if less than we will search in left part
            e=mid-1;
        }
        // update mid
             // mid=(s+e)/2;
        // optimisation
        mid=s+(e-s)/2;    
    }
    return -1;
}

int leftmost(int arr[], int size , int key){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    int i=-1;
    while(s<=e){
        if(arr[mid]==key){
            i=mid;
            e=mid-1;
        }else if(key>arr[mid]){
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return i;
}

int rightmost(int arr[], int size , int key){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    int i=-1;
    while(s<=e){
        if(arr[mid]==key){
            i=mid;
            s=mid+1;
        }else if(key>arr[mid]){
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
        // cout<<i<<endl;
    }
        return i;
}

// find peak index of a mountain array
int  peak(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<e){
        // for avoid repetation of iteration we should use s<e instead of s<=e
        if((arr[mid]<arr[mid+1])){
            s=mid+1;
        }else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int getpivot(int arr[], int size){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    while(s<e){
        // s<=e not use due to avoid code repetation
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }else{
            e=mid;
            // we don't want to loose the edge case when end exist in pivot so instead of mid-1 we use e=mid
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int binarys( int arr[], int start ,int end, int key){
    int s=start;
    int e=end;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }else{
        if(key>arr[mid]){
            s=mid+1;
        }else{
            e=mid-1;
        }
        }
        mid=s+(e-s)/2;    
    }
            return -1;
}



int getindexinsortedrotated(int arr[],int size, int key){
    int pivot=getpivot(arr,size);
    // cout<<pivot;
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    if(key>=arr[pivot] && key<=arr[e]){
        s=pivot;
        return binarys(arr,s,e,key);
    }else{
        e=pivot-1;
        return binarys(arr,s,e,key);
    }
}


double sqrt (long long int n,int precision){

long long int s=0;

long long int e=n;

long long int mid=s+(e-s)/2;
// int ans=-1;
// optimised due to solve the problem during find greater number's squrae root
long long int ans=-1;
while(s<=e){
    if(mid*mid==n){
        return mid;
    }
    if(mid*mid>n){
        e=mid-1;
    }else{
        ans=mid;
        s=mid+1;
    }
    mid=s+(e-s)/2;
}
double factor=1;
double f_ans=-1;
for(int i=0;i<precision;i++){
    factor=factor/10;
    for(double j=ans;j*j<n;j=j+factor){
        f_ans=j;
    }
}
return f_ans;

}

bool isPossible(vector<int> &stalls, int k, int mid, int n) {
    
    int cowCount = 1;
    int lastPos = stalls[0];
    
    for(int i=0; i<n; i++ ){
        
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    // sorted vector 1 2 3 4 6 
    int s = 0;
    int n = stalls.size();//n=5;
    int e=stalls[n-1];//due to sorted vector stalls ka last element hi stalls vector ka max element hoga
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e) {
        if(isPossible(stalls, k, mid, n)) {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}





// int main(){
//     // int odd[5]={3,7,9,1,2};
//     // int even[6]={7,9,0,1,2,3};
//     // int oddindex=binary(odd,5,45);
//     // int evenindex=binary(even,6,34);
//     // cout<<oddindex<<endl<<evenindex;
//     // cout<<leftmost(odd,11,3)<<endl;
//     // cout<<rightmost(odd,11,3)<<endl;
//     // cout<<"total no of occurance is   " <<(rightmost(odd,11,3)-leftmost(odd,11,3))+1<<endl;
//     // cout<<peak(even,6)<<endl;
//     // cout<<getpivot(odd,6)<<endl;
//     // cout<<getindexinsortedrotated(even,6,0);
//     double ans=sqrt(37,6);
//     cout<<ans<<endl;
//     return 0;

// }
// // time complexity : o(logn) base-2
// // sc: o(1);

