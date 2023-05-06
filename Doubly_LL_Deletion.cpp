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
    ~node(){
        int val=data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data "<<val<<endl;
    }
};

void print(node* &head){
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }
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
    if(head!=NULL){
        head->prev=temp;
    }
    head=temp;
}

void insertionTail(node* &tail,int data){
    node*temp=new node(data);
    if(tail==NULL){
        tail=temp;
        return;
    }
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertionMid(node* &head,node* &tail,int position,int data){
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    //insertion at start
    if(position==1){
        insertionHead(head,data);
        return;
    }

    //insertion at specific position
    node*temp=head;
    int cnt=1;
    while(cnt < position-1 && temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    if(temp==NULL){
        cout<<"Invalid Position"<<endl;
        return;
    }
    //creating node for data
    node* nodeToinsert=new node(data);
    nodeToinsert->next=temp->next;
    if(temp->next != NULL){
        temp->next->prev=nodeToinsert;
    }
    temp->next=nodeToinsert;
    nodeToinsert->prev=temp;

    //insertion at last
    if(temp->next==NULL){
        insertionTail(tail,data);
        return;
    }
}

void deletion(node* &head,int position){
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    //deletion first node
    if(position==1){
        node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }
    else{
        node*current=head;
        node*prev=NULL;
        int cnt=1;
        while(cnt < position && current!=NULL){
            prev=current;
            current=current->next;
            cnt++;
        }
        if(current==NULL){
            cout<<"Invalid Position"<<endl;
            return;
        }
        current->prev=NULL;
        prev->next=current->next;
        if(current->next!=NULL){
            current->next->prev=prev;
        }
        current->next=NULL;
        delete current;
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

    deletion(head,1);
    print(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    deletion(head,4);
    print(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    deletion(head,7);
    print(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    return 0;
}