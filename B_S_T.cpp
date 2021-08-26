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
int counting(node *root){
    if (root==NULL){
        return 0;
    }
    return counting(root->left)+counting(root->right)+1;
}
void bst_to_arr(node *root,int arr[],int *i){
    if (root!=NULL){
        bst_to_arr(root->left,arr,i);
        arr[*i]=root->data;
        (*i)++;
        bst_to_arr(root->right,arr,i);
    }
}
node *return_the_num(node *root1,int abc){
    if (root1==NULL){
        return NULL;
    }
    if (abc==root1->data){
        return root1;
    }
    if (abc<root1->data){
        return return_the_num(root1->left,abc);
    }
    return return_the_num(root1->right,abc);
}
int count_pairs(node *root,node *root1,int sum){
    if (root==NULL || root1==NULL){
        return 0;
    }
    int x=counting(root);
    int *arr=new int[x];
    int i=0;
    bst_to_arr(root,arr,&i);
    sort(arr,arr+x);
    map < pair < int , int > , int > mapp;
    for (int j=0;j<x;j++){
        int bcd=sum-arr[j];
        node *temp=return_the_num(root1,bcd);
        if (temp!=NULL){
            pair < int , int > p;
            p.first=bcd;
            p.second=arr[j];
            mapp.insert({p,1});
        }
    }
    int count=0;
    for (auto it:mapp){
        count++;
    }
    return count;
}
int main(){
    node *root=NULL,*root1=NULL;
    root=insert(root,5);
    root=insert(root,3);
    root=insert(root,2);
    root=insert(root,6);
    root=insert(root,10);
    root1=insert(root1,8);
    root1=insert(root1,1);
    root1=insert(root1,3);
    root1=insert(root1,5);
    root1=insert(root1,12);
    int x=count_pairs(root,root1,13);
    cout<<x<<endl;
    return 0;
}