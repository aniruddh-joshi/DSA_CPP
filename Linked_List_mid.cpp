#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
};

void insertionHead(Node* &head,int data){
    Node*temp=new Node();
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head=temp;
}

void insertionTail(Node* &tail,int data){
    Node*temp=new Node();
    temp->data=data;
    temp->next=NULL;
    tail->next=temp;
    tail=temp;
}

void insertionMid(Node* &head,Node* &tail,int position,int data){
    //insertion at start
    if(position==1){
        insertionHead(head,data);
        return;
    }

    //insertion at specific position
    Node*temp=head;
    int cnt=1;
    while(cnt < position-1){
        temp=temp->next;
        cnt++;
    }
    Node* nodeToinsert=new Node();
    nodeToinsert->data=data;
    nodeToinsert->next=NULL;
    nodeToinsert->next=temp->next;
    temp->next=nodeToinsert;

    //insertion at last
    if(temp->next==NULL){
        insertionTail(tail,data);
        return;
    }
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

    insertionMid(head,tail,4,22);
    print(head);

    return 0;
}