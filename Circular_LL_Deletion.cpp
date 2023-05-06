#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    //constructor
    Node(int val){
        data=val;
        next=NULL;
    }
    //destructor
    ~Node(){
        int val=data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data "<<val<<endl;
    }
};

void insertion(Node* &tail,int element, int data){
    //empty list
    if(tail==NULL){
        Node*newNode =new Node(data);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        //non-empty list
        //assuming that element is present in the list

        Node* curr=tail;
        while(curr->data != element){
            curr=curr->next;
        }
        //element found->curr is representing element wala node
        Node*temp=new Node(data);
        temp->next = curr->next;
        curr->next=temp;
    }
}

void deletion(Node* &tail, int val){
    //empty list
    if(tail == NULL){
        cout<<"List is empty,please check again" << endl;
        return;
    }
    else{
        //non-empty list
        //assuming that element is present in the list

        Node*prev =tail;
        Node*curr=prev->next;

        while(curr->data != val){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;

        //1 Node Linked List
        if(curr==prev){
            tail=NULL;
        }
        //>=2 Node Linked List
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* &tail){
    Node*temp =tail;
    if(tail==NULL){
        cout<<"List is Empty"<<endl;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail != temp);
    cout<<endl;
}

int main(){
    Node*tail=NULL;

    insertion(tail,5,3);
    print(tail);

    /*insertion(tail,3,5);
    print(tail);

    insertion(tail,5,7);
    print(tail);

    insertion(tail,7,9);
    print(tail);

    insertion(tail,5,6);
    print(tail);

    insertion(tail,9,10);
    print(tail);

    insertion(tail,3,4);
    print(tail);*/

    deletion(tail,3);
    print(tail);

    return 0;
}