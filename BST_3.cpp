#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
};
node *create_node(int d){
    node *n=new node();
    n->data=d;
    n->left=n->right=NULL;
    return n;
}
int counting(node *root){
    if (root==NULL){
        return 0;
    }
    return counting(root->left)+counting(root->right)+1;
}
void storeinorder(node *root,int arr[],int *index){
    if (root==NULL){
        return;
    }
    storeinorder(root->left,arr,index);
    arr[*index]=root->data;
    (*index)++;
    storeinorder(root->right,arr,index);
}
int compare(const void * a, const void *b){
    return (*(int*)a-*(int*)b);
}
void array_to_bst(node *root,int arr[],int *indexx){
    if (root==NULL){
        return;
    }
    array_to_bst(root->left,arr,indexx);
    root->data=arr[*indexx];
    (*indexx)++;
    array_to_bst(root->right,arr,indexx);
}
void binary_tree_to_bst(node *root){
    if (root==NULL){
        return;
    }
    int n=counting(root);
    int *arr=new int[n];
    int i=0;
    storeinorder(root,arr,&i);
    qsort(arr,n,sizeof(arr[0]),compare);
    i=0;
    array_to_bst(root,arr,&i);
    delete[] arr;
}
void inorder(node *root){
    if (root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main(){
    struct node *root=NULL;
    root=create_node(10);
    root->left=create_node(30);
    root->right=create_node(15);
    root->left->left=create_node(20);
    root->right->right=create_node(5);
    binary_tree_to_bst(root);
    inorder(root);
    cout<<endl;
    return 0;
}