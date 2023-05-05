#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void print(node* &head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertionHead(node* &head,int data){
    node*temp= new node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

int main(){
    node*node1=new node(10);
    node*head=node1;
    print(head);

    insertionHead(head,20);
    print(head);
    insertionHead(head,30);
    print(head);

    return 0;
}