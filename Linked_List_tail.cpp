#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
};

void insertionTail(Node* &tail,int data){
    Node*temp=new Node();
    temp->data=data;
    temp->next=NULL;
    tail->next=temp;
    tail=temp;
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node*node1=new Node();
    node1->data=10;
    node1->next=NULL;

    Node*head=node1;
    Node*tail=node1;
    print(head);

    insertionTail(tail,20);
    print(head);

    insertionTail(tail,30);
    print(head);

    return 0;

}