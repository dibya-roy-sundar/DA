#include <iostream>
using namespace std;
bool issorted(int arr[],int size){
if(size==0||size==1){
    return true;
}
    if(arr[0]>arr[1]){
        return false;
    }else{
        return issorted(arr+1,size-1);
    }

}
bool linsearch(int arr[], int size,int key){
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return  true;
    }else{
        return (linsearch(arr+1,size-1,key));
    }
}
int main() {   
    int test[5]={1,4,3,4,5};
    // if(issorted(test,5)){
    //     cout<<"yes,sorted";
    // }else{
    //     cout<< "not sorted";
    // }
    if(linsearch(test,5,4)){
        cout<<"yes,found";
    }else{
        cout<< "not found";
    }
    return 0;
}