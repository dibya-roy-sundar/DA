#include <iostream>
using namespace std;
class node{
public:
int val;
int col;
node* next;
node(int data,int column){
    val=data;
    col=column;
    next=NULL;
}
};
class row_list{
    public:
    int row;
    node* link_right;
    row_list* link_down;
    row_list(int data){
        row=data;
        link_right=NULL;
        link_down=NULL;
    }
};
void create_node(int data, int col, row_list*& z){
node* new_node=new node(data,col);
if(z->link_right==NULL){
    z->link_right=new_node;
}else{
    node* temp=z->link_right;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=new_node;
}
}
row_list*  create_row(int sparse[4][5],int row,int col){
    row_list* head=NULL;
    for(int i=0;i<row;i++){
        row_list* z=new row_list(i+1);
        if(head==NULL){
            head=z;
        }else{
            row_list* temp=head;
            while(temp->link_down!=NULL){
                temp=temp->link_down;
            }
            temp->link_down=z;
        }
        for(int j=0;j<col;j++){
            if(sparse[i][j]!=0){
                create_node(sparse[i][j],j+1,z);
            }
        }
    }
    return head;

}
void printlist(row_list*  head){
    row_list* temp=head;
    node* curr;
    while(temp!=NULL){
        if(temp->link_right!=NULL){
            cout<<"row= "<<temp->row<<endl;
            curr=temp->link_right;
            while(curr!=NULL){
                cout<<"col= "<<curr->col<<endl;
                cout<<"value= "<<curr->val<<endl;
                curr=curr->next;
            }

        }
        temp=temp->link_down;
    }

}
int main(){
    int sprase[4][5]={
        {0,0,3,0,4},
        {0,0,5,7,0},
        {0,0,0,0,0},
        {0,2,6,0,0}
    };
    row_list* head=create_row(sprase,4,5);
    printlist(head);
}