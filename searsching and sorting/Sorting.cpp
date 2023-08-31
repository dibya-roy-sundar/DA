#include <iostream>
using namespace std;
void  selectionsort(int arr[], int n){
    int minindex;
    for(int i=0;i< n-1;i++){
    minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        swap(arr[i],arr[minindex]);
    }
}

void bubblesort(int arr[],int  n){
    for(int i=1;i<n;i++){
        // n-1 comparison
            // optimised 
            bool swapped=false;
        for(int j=0;j<n-i;j++){
            // n-i for decreasing seach space and avoid redundency
            if (arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
            // if in one round we loop around through whole array but the array is already sorted and so after the iteration swapped will remain false 
            // so there is no need to go for next round so we break from the loop
            break;
        }
    }
}
void insertionsort(int arr[],int n){
    for(int i=1;i<n-1;i++){
        int j=i-1;
        int temp=arr[i];
        while(j>=0){
        if(arr[j]>temp){
            arr[j+1]=arr[j];
        }else{
            break;
        }
        j--;
        }
        // now j is there where arr[j]<temp;
        arr[j+1]=temp;
    }
}
int main() {
    int test[5]={7,2,1,4,8};
    // selectionsort(test,5);
    insertionsort(test,5);
    for(int i=0;i<5;i++){
        cout<<test[i];
    }

return 0;
}