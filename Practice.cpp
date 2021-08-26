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
void inserting(node *root,int arr[],int *index){
    if (root==NULL){
        return;
    }
    inserting(root->left,arr,index);
    arr[*index]=root->data;
    (*index)++;
    inserting(root->right,arr,index);
}
node *insert(node *root,int k){
    if (root==NULL){
        root=create_node(k);
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
int inorder_tra(node *root,int &countinggg,int k){
    if (root!=NULL && countinggg<k){
        inorder_tra(root->right,countinggg,k);
        countinggg++;
        if (countinggg==k){
            cout<<root->data;
        }
        inorder_tra(root->left,countinggg,k);
    }
}
void k_th_largest_ele(node *root,int k){
    if (root==NULL){
        cout<<-1;
    }
    if (root->left==NULL && root->right==NULL && k==1){
       cout<<root->data;
    }
    int x=counting(root);
    if (x<k){
        cout<<-1;
    }
    if (x==k){
        if (root->right==NULL){
            cout<<root->data;
        }
        node *temp=root;
        while (temp && temp->right!=NULL){
            temp=temp->right;
        }
       cout<<temp->data;
    }
    int countinggg=0;
    inorder_tra(root,countinggg,k);
}
node *inorder_sma(node *root,int k){
    if (root!=NULL){
        node *left=inorder_sma(root->left,k);
        if (left!=NULL){
            return left;
        }
        k--;
        if (k==0){
            return root;
        }
        return inorder_sma(root->right,k);
    }
}
int k_th_smallest(node *root,int k){
    if (root==NULL){
        return -1;
    }
    if (root->left==NULL && root->right==NULL && k==1){
        return root->data;
    }
    int x=counting(root);
    if (k>x){
        return -1;
    }
    if (k==1){
        node *temp=root;
        while (temp && temp->left!=NULL){
            temp=temp->left;
        }
        return temp->data;
    }
    if (k==x){
        node *temppp=root;
        while (temppp && temppp->right!=NULL){
            temppp=temppp->right;
        }
        return temppp->data;
    }
    node *tempp=inorder_sma(root,k);
    return tempp->data;
}
int lca(node *root,int a,int b){
    if (root==NULL){
        return -1;
    }
    if (a<root->data && b<root->data){
        int abc=lca(root->left,a,b);
        return abc;
    }
    if (a>root->data && b>root->data){
        int bcd=lca(root->right,a,b);
        return bcd;
    }
    return root->data;
}
int main(){
    node *root=NULL;
    root=create_node(5);
    root->left=create_node(3);
    root->left->right=create_node(4);
    root->right=create_node(8);
    int ab=k_th_smallest(root,2);
    cout<<ab;
    return 0;
}