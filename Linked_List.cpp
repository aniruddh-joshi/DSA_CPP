#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
};

void insertion(Node* &head,int data){
    Node*temp=new Node();
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head=temp;
}

void print(Node* &head){
    Node*temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node*node1 = new Node();
    node1->data=10;
    node1->next=NULL;
    
    Node*head=node1;
    print(head);
    
    insertion(head,12);
    print(head);
    
    return 0;
}