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

//creation of tree
Node*buildTree(Node*root){
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    
    cout<<"Enter data to the left of"<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data to the right of"<<data<<endl;
    root->right=buildTree(root->right);
    return root;
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

//Main Function
int main(){
    Node*root=NULL;
    root=buildTree(root);
    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);
}
