#include<iostream>
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

void insertionTail(node* &tail,int data){
    node*temp=new node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

int main(){
    node*node1=new node(10);
    node*head=node1;
    node*tail=node1;
    print(head);

    insertionTail(tail,20);
    print(head);
    insertionTail(tail,30);
    print(head);

    return 0;
}