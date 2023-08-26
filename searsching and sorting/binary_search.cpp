# include<iostream>
using namespace std;
int binary( int arr[], int size , int key){
    // condition of binary search is the array should be monotonic function i.e increasing or decreasing
    // in this solution we assume our array is  sorted in increasing order
    int s=0;
    int e=size-1;
    // int mid=(s+e)/2;
    //  oprimisation-if the input array size is grater than the ange of int then this formula would fail 
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
        return -1;
    }
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


int main(){
    int odd[11]={0,1,1,2,2,2,2,3,3,3,3};
    int even[6]={1,3,5,6,7,1};
    // int oddindex=binary(odd,5,45);
    // int evenindex=binary(even,6,34);
    // cout<<oddindex<<endl<<evenindex;
    // cout<<leftmost(odd,11,3)<<endl;
    // cout<<rightmost(odd,11,3)<<endl;
    // cout<<"total no of occurance is   " <<(rightmost(odd,11,3)-leftmost(odd,11,3))+1<<endl;
    cout<<peak(even,6)<<endl;
    return 0;

}
// time complexity : o(logn) base-2
// sc: o(1);