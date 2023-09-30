#include <iostream>
using namespace std;



class Node
{
public:
int data;
Node *next;
Node *child;
Node(int x){
    data=x, next = NULL , child =NULL ;
}
};
Node* createlist(int* arr, int n){
    Node* head=NULL;
    Node* temp=head;
    for(int i=0;i<n;i++){
        Node* p=new Node(arr[i]);
        if(temp==NULL){
            temp=p;
        }else{
            temp->next=p;
            temp=p;
        }
    }
    return  head;
}
Node* multi(){
int arr1[] = {10, 5, 12, 7, 11};
int arr2[] = {4, 20, 13};
int arr3[] = {17, 6};
int arr4[] = {9, 8};
int arr5[] = {19, 15};
int arr6[] = {2};
int arr7[] = {16};
int arr8[] = {3};
Node *head1 = createlist(arr1, sizeof(arr1));
Node *head2 = createlist(arr2, sizeof(arr2));
Node *head3 = createlist(arr3, sizeof(arr3));
Node *head4 = createlist(arr4, sizeof(arr4));
Node *head5 = createlist(arr5, sizeof(arr5));
Node *head6 = createlist(arr6, sizeof(arr6));
Node *head7 = createlist(arr7, sizeof(arr7));
Node *head8 = createlist(arr8, sizeof(arr8));

head1->child = head2;
head2->next->child=head6;
head2->next->next->child=head7;
head7->next=head8;
head1->next->next->next->child = head3;
head3->child=head4;
head4->child=head5;
return head1;

}
int main(){
    Node* head=NULL;
    head=multi();
    return 0;
}