#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    //Constructor
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

//Build from Level Order
void buildfromLevelOrder(Node*&root){
    queue<Node*>q;
    cout<<"Enter data for root: "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!= -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!= -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

//Level Order Traversal
void levelOrderTraversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(temp!= NULL){
            cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
             else{
                cout<<endl;
                if(!q.empty()){
                q.push(NULL);
                 }
            }
    }
}

int main(){
    Node*root=NULL;
    buildfromLevelOrder(root);
    levelOrderTraversal(root);
    return 0;
}