#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *newnode(int d){
    node *n=new node();
    n->data=d;
    n->left=n->right=NULL;
    return n;
}
node *insert(node *root,int d){
    if (root==NULL){
        root=newnode(d);
        return root;
    }
    if (d>root->data){
        root->right=insert(root->right,d);
    }
    else {
        root->left=insert(root->left,d);
    }
    return root;
}
void inorder(node *root){
    if (root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node *min_value_node(node *abc){
    node *abcd=abc;
    while (abcd && abcd->left!=NULL){
        abcd=abcd->left;
    }
    return abcd;
}
node *delete_node(node *root,int d){
    if (root==NULL){
        return root;
    }
    if (d>root->data){
        root->right=delete_node(root->right,d);
    }
    else if (d<root->data){
        root->left=delete_node(root->left,d);
    }
    else {
        if (root->left==NULL){
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL){
            node *temp=root->left;
            free(root);
            return temp;
        }
        else {
            node *temp=min_value_node(root->right);
            root->data=temp->data;
            root->right=delete_node(root->right,temp->data);
        }
    }
    return root;
}
node *con_tr_util(int arr[],int *preindex,int key,int min,int max,int size){
    if (*preindex>=size){
        return NULL;
    }
    node *root=NULL;
    if (key>min && key<max){
        root=newnode(key);
        *preindex=*preindex+1;
        if (*preindex<size){
            root->left=con_tr_util(arr,preindex,arr[*preindex],min,key,size);
        }
        if (*preindex>size){
            root->right=con_tr_util(arr,preindex,arr[*preindex],key,max,size);
        }
    }
    return root;
}
node *construct_bst(int arr[],int size){
    int preindex=0;
    return con_tr_util(arr,&preindex,arr[0],INT_MIN,INT_MAX,size);
}
int main(){
    // node *root=NULL;
    // root=insert(root,3);
    // root=insert(root,4);
    // root=insert(root,2);
    // root=insert(root,6);
    // root=insert(root,8);
    // root=insert(root,9);
    // inorder(root);
    // cout<<endl;
    // root=delete_node(root,6);
    // inorder(root);
    // cout<<endl;
    int arr[6]={10,5,1,7,40,50};
    node *root=construct_bst(arr,6);
    inorder(root);
    return 0;
}