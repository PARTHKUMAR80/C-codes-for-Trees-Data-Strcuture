#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
    node(int k){
        this->data=k;
        this->left=NULL;
        this->right=NULL;
    }
};
node *create_node(int k){
    node *n=new node(k);
    return n;
}
node *insert(node *root,int k){
    if (root==NULL){
        root=create_node(k);
        return root;
    }
    if (k<root->data){
        root->left=insert(root->left,k);
    }
    else {
        root->right=insert(root->right,k);
    }
    return root;
}
void inorder(node *root){
    if (root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
bool route(node *root,int a,vector <int> &v){
    if (root==NULL){
        return false;
    }
    v.push_back(root->data);
    if (root->data==a){
        return true;
    }
    if (a<root->data){
        if (root->left && route(root->left,a,v)){
            return true;
        }
        return false;
    }
    if (root->right && route(root->right,a,v)){
        return true;
    }
    return false;
}
int kth_ancestor(node *root,int a,int k){
    if (root==NULL){
        return -1;
    }
    if (root->left==NULL && root->right==NULL){
        if (root->data==a && k==0){
            return root->data;
        }
        return -1;
    }
    vector <int> path;
    bool abc=route(root,a,path);
    if (!abc){
        return -1;
    }
    int count=0;
    for (int i=path.size()-1;i>=0;i--){
        if (k==count){
            return path[i];
        }
        count++;
    }
    return -1;
}
int main(){
    node *root=create_node(20);
    root->left=create_node(8);
    root->right=create_node(22);
    root->left->left=create_node(4);
    root->left->right=create_node(12);
    root->left->right->left=create_node(10);
    root->left->right->right=create_node(14);
    int x=kth_ancestor(root,14,3);
    cout<<x<<endl;
    return 0;
}