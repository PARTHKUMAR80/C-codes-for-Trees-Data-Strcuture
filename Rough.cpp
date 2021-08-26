#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *create_node(int k){
    node *n=new node();
    n->data=k;
    n->left=n->right=NULL;
    return n;
}
void inorder(node *root){
    if (root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
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
node *arr_to_bst(int arr[],int s,int e){
    node *temp=NULL;
    if (s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    temp=create_node(arr[mid]);
    temp->left=arr_to_bst(arr,s,mid-1);
    temp->right=arr_to_bst(arr,mid+1,e);
    return temp;
}
node *pre_to_bst(int arr[],int key,int *index,int min,int max,int size){
    if (*index>=size){
        return NULL;
    }
    node *root=NULL;
    if (key>min && key<max){
        root=create_node(key);
        *index=*index+1;
        if (*index<size){
            root->left=pre_to_bst(arr,arr[*index],index,min,key,size);
        }
        if (*index<size){
            root->left=pre_to_bst(arr,arr[*index],index,key,max,size);
        }
    }
    return root;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    node *root=NULL;
    int i=0;
    int min=INT_MIN;
    int max=INT_MAX;
    root=pre_to_bst(arr,arr[0],&i,min,max,n);
    inorder(root);
    return 0;
}