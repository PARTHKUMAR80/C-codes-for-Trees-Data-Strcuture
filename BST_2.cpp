#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
};
node *createnode(int d){
    node *n=new node();
    n->data=d;
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
        root=createnode(k);
        return root;
    }
    if (k>root->data){
        root->right=insert(root->right,k);
    }
    else {
        root->left=insert(root->left,k);
    }
    return root;
}
bool find_a_value(node *root,int key){
    if (root==NULL){
        return false;
    }
    if (root->data==key){
        return true;
    }
    bool a;
    if (key>root->data){
        a=find_a_value(root->right,key);
    }
    else {
        a=find_a_value(root->left,key);
    }
    return a;
}
node *find_left(node *abc){
    node *abcd=abc;
    while (abcd && abcd->left!=NULL){
        abcd=abcd->left;
    }
    return abcd;
}
node *deletee(node *root,int key){
    if (root==NULL){
        return NULL;
    }
    if (key>root->data){
        root->right=deletee(root->right,key);
    }
    else if (key<root->data){
        root->left=deletee(root->left,key);
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
            node *temp=find_left(root);
            root->data=temp->data;
            root->right=deletee(root->right,temp->data);
        }
    }
    return root;
}
int find_min(node *root){
    if (root==NULL){
        return -1;
    }
    if (root->left==NULL && root->right==NULL){
        return root->data;
    }
    if (root->left==NULL){
        return root->data;
    }
    node *abc=root;
    while (abc && abc->left!=NULL){
        abc=abc->left;
    }
    return abc->data;
}
bool bst_or_not(node *root){
    if (root==NULL){
        return true;
    }
    if (root->left==NULL && root->right==NULL){
        return true;
    }
    if (root->left==NULL){
        if (root->right->data<root->data){
            return false;
        }
        else {
            bool a=bst_or_not(root->right);
            return a;
        }
    }
    else if (root->right==NULL){
        if (root->left->data>root->data){
            return false;
        }
        else {
            bool a=bst_or_not(root->left);
            return a;
        }
    }
    else {
        if (root->left->data>root->data){
            return false;
        }
        if (root->right->data<root->data){
            return false;
        }
        bool a=bst_or_not(root->left);
        bool b=bst_or_not(root->right);
        return a && b;
    }
}
node *l_c_a(node *root,int n1,int n2){
    if (root==NULL){
        return NULL;
    }
    if (root->data>n1 && root->data>n2){
        return l_c_a(root->left,n1,n2);
    }
    if (root->data<n1 && root->data<n2){
        return l_c_a(root->right,n1,n2);
    }
    return root;
}
int main(){
    node *root=createnode(20);
    root->left=createnode(8);
    root->right=createnode(22);
    root->left->left=createnode(4);
    root->left->right=createnode(12);
    root->left->right->left=createnode(10);
    root->left->right->right=createnode(14);
    node *t=l_c_a(root,10,14);
    cout<<t->data<<endl;
    node *t1=l_c_a(root,10,22);
    cout<<t1->data<<endl;
    return 0;
}