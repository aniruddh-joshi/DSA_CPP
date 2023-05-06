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

void insertionHead(node* &head,int data){
    node*temp= new node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertionTail(node* &tail,int data){
    node*temp=new node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertionMid(node* &head,node* &tail,int position,int data){
    //insertion at start
    if(position==1){
        insertionHead(head,data);
        return;
    }

    //insertion at specific position
    node*temp=head;
    int cnt=1;
    while(cnt < position-1){
        temp=temp->next;
        cnt++;
    }
    //creating node for data
    node* nodeToinsert=new node(data);
    nodeToinsert->next=temp->next;
    temp->next->prev=nodeToinsert;
    temp->next=nodeToinsert;
    nodeToinsert->prev=temp;

    //insertion at last
    if(temp->next==NULL){
        insertionTail(tail,data);
        return;
    }
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

    insertionMid(head,tail,2,100);
    print(head);

    insertionMid(head,tail,1,200);
    print(head);

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    return 0;
}