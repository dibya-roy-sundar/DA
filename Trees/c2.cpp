#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    
    node(int val) : data(val), left(NULL), right(NULL) {}
};

node* rightmost(node* root) {
    while (root->right) {
        root = root->right;
    }
    return root;
}

void morrissolve(node* curr, vector<int>& in, map<node*, bool>& m) {
    if (curr == NULL) {
        return;
    }
    if (!m[curr]) {
        m[curr] = true; // Mark visited
    } else {
        node* temp = rightmost(curr->left);
        temp->right = NULL;
        in.push_back(curr->data);
        morrissolve(curr->right, in, m);
    }
    if (curr->left) {
        node* temp = rightmost(curr->left);
        temp->right = curr;
        morrissolve(curr->left, in, m);
    } else {
        in.push_back(curr->data);
        morrissolve(curr->right, in, m);
    }
}

vector<int> morrisin(node* root) {
    vector<int> in;
    node* curr = root;
    map<node*, bool> m;
    morrissolve(curr, in, m);
    return in;
}
void search(node* root,node*& prev,node*& temp,int key){
    if(root==NULL){
        return ;
    }
    if(root->data==key){
        return ;
    }
   
    if(key<root->data){
             if(root->left){
                        if(root->left->data==key){
                            temp=root->left;
                            return ; 
                                }else{
                                     prev=root->left;
                                    temp=root->left;
             return search(root->left,prev,temp,key);
                                }
            }
        
      
    }else{
       if(root->right){
                        if(root->right->data==key){
                            temp=root->right;
                            return ; 
                                }else{
                                    prev=root->right;
                                    temp=root->right;
            return search(root->right,prev,temp,key);
                                }
            }
    }
}
int main() {
    // Create a sample binary tree
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->left->left = new node(2);
    root->left->right = new node(4);
    root->right->right = new node(7);
    root->right->right = new node(8);

    // vector<int> result = morrisin(root);

    // // Print the in-order traversal
    // for (int val : result) {
    //     cout << val << " ";
    // }
    

    node* prev=root;
    node* temp=root;
    search(root,prev,temp,8);
    cout<<prev->data;
    cout<<temp->data;
    // Clean up memory (you should free the memory allocated for the tree)
    return 0;
}
