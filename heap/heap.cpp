#include<iostream>
using namespace std;
class MaxHeap{
    int arr[100];
    int size;
    public:
    MaxHeap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int n){
        size++;
        int index,parent,t;
        index=size;
        arr[index]=n;
        while(index>1){
            parent=index/2;
            if(arr[parent]<arr[index]){
                t=arr[parent];
                arr[parent]=arr[index];
                arr[index]=t;
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void del(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }

        int t,i,lc,rc;
        arr[1]=arr[size];
        size--;
        i=1;

        while(i<size){
            lc=2*i;
            rc=2*i+1;

            if(lc<=size && arr[lc]>arr[i]){
                t=arr[lc];
                arr[lc]=arr[i];
                arr[i]=t;
                i=lc;
            }
            if(rc<=size && arr[rc]>arr[i]){
                t=arr[rc];
                arr[rc]=arr[i];
                arr[i]=t;
                i=rc;
            }
            else{
                return;
            }
        }
    }


    void print(){
        int i;
        for(i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
    
void heapify(int arr[],int n,int i){
    int largest=i;
    int lc=2*i,rc=2*i+1,t;

    if(lc<=n && arr[lc]>arr[largest]){
        largest=lc;
    }
    if(rc<=n && arr[rc]>arr[largest]){
        largest=rc;
    }

    if(largest!=i){
        t=arr[largest];
        arr[largest]=arr[i];
        arr[i]=t;
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    int size=n,t;

    while(size>1){
        t=arr[1];
        arr[1]=arr[size];
        arr[size]=t;

        size--;

        heapify(arr,size,1);
    }
}

int main(){
    MaxHeap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(54);
    h.insert(52);
    h.print();

    h.del();
    h.print();

    int arr[11]={-1,1,2,3,4,5,6,7,8,9,10};
    int i;
    for(i=10/2;i>=1;i--){
        heapify(arr,10,i);
    }

    for(i=1;i<=10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,10);

    for(i=1;i<=10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}