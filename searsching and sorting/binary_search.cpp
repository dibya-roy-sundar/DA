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

int main(){
    int odd[5]={1,34,45,67,89};
    int even[6]={2,23,45,46,88,94};
    int oddindex=binary(odd,5,45);
    int evenindex=binary(even,6,34);
    cout<<oddindex<<endl<<evenindex;
    return 0;

}
// time complexity : o(logn) base-2
// sc: o(1);