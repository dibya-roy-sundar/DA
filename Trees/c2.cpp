#include<iostream>
using namespace std;

class node{
public:
int data;
node* left;
node* right;

node(int x){

        data=x;




left=NULL;
right=NULL;
}
};
node* insertion(int arr[],int n,int i){
node* root=NULL;
if(i<n){
root=new node(arr[i]);
root->left=insertion(arr,n,2*i+1);
root->right=insertion(arr,n,2*i+2);

}
return root;
}
void inorder(node* root){
    if(root!=NULL){



inorder(root->left);



cout<<root->data<<" ";

inorder(root->right);

}else{
return ;
}
}
int main(){
node* root=NULL;
int arr[]={1,2,3,4,5,6,7,0,8,9,0,0,0,10,11,12,13,0,14,15,0,16,17};
int n=sizeof(arr)/sizeof(arr[0]);
root=insertion(arr,n,0);
inorder(root);


}


