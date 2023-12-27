#include<bits/stdc++.h> 
using namespace std; 
class node{
public:
int data;
node* left;
node* right;
int height;
node(int x){
    data=x;
    left=right=NULL;
    height=1;
}
};

int height(node* root){
    if(root==NULL){
    return 0;
    }
    return root->height;
}
int max(int a, int b){
    return ((a>b)? a : b);
}

node* leftrotate(node* root){
    node* x=root;
    node* y=x->right;
    // node*z=y->right;
    // node* T1=x->left;
    node* T2=y->left;
    // node* T3=z->left;
    // node* T4=z->right;

    y->left=x;
    x->right=T2;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return y;//return new root

}
node* rightrotate(node* root){
    node* x=root;
    node* y=x->left;
    // node*z=y->left;
    // node* T1=x->right;
    node* T2=y->right;
    // node* T3=z->right;
    // node* T4=z->left;

    y->right=x;
    x->left=T2;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return y;//return new root

}
 int getbalance(node* n){
    if(n==NULL){
        return 0;
    }
    return height(n->left)-height(n->right);//lh-rh
 }

 node* insert(node* root, int data){
    //insertion in bst
    if(root==NULL){
        return new node(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }else if(data>root->data){
        root->right=insert(root->right,data);
    } else{//equal not allowed
        return root;
    }
    //height update
    root->height=max(height(root->left),height(root->right))+1;
    //check balance factor 
    int balance=getbalance(root);

    
    
    //rotation(unbalanced)

    //(LL) left left -single
    if(balance>1 && data<root->left->data){
         return rightrotate(root);
    }
    //( LR=LL+RR) left ke right balance factor +2 bana -so we need double rotation
     if(balance>1 && data>root->left->data){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    //RR
    if(balance<-1 && data>root->right->data){
         return leftrotate(root);
    }
    //RL=RR+LL
     if(balance<-1 && data<root->right->data){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }



    //remain balanced 
    return root;    
 }


 node* deletion(node* root, int data){
    if(root==NULL){
        return root;
    }
    if(data<root->data){
        root->left=deletion(root->left,data);
    }else if(data>root->data){
        root->right=deletion(root->right,data);
    } else{
        //deletion in bst       
    }

    // If the tree had only one node
	// then return 
	if (root == NULL) 
	return root;

    //height update
    root->height=max(height(root->left),height(root->right))+1;
    //check balance factor 
    int balance=getbalance(root);

    //rotation(unbalanced)

    // L0 && L-1(RR)
    if(balance<-1 && getbalance(root->right)<=0){
        return leftrotate(root);
    }
    // L1( RL)
    if(balance<-1 && getbalance(root->right)>0){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    // R0 && R1(LL)
    if(balance>1 && getbalance(root->left)>=0){
        return rightrotate(root);
    }
    // R-1(LR)
    if(balance>1 && getbalance(root->left)>0){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }



    //remain balanced 
    return root;    
 }
 void preOrder(node *root) 
{ 
	if(root != NULL) 
	{ 
		cout << root->data << " "; 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 
int main(){
    node* root=NULL;
   	root = insert(root, 10); 
	root = insert(root, 20); 
	root = insert(root, 30); 
	root = insert(root, 40); 
	root = insert(root, 50); 
	root = insert(root, 25); 

    preOrder(root);
    return 0;
}


