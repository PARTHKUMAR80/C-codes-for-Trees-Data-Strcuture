#include <bits/stdc++.h>
using namespace std;
struct node {
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
void root_to_set(node *root,unordered_set <int> &all_nodes,unordered_set <int> &leaf_nodes){
    if(root==NULL){
        return;
    }
    all_nodes.insert(root->data);
    if (root->left==NULL && root->right==NULL){
        leaf_nodes.insert(root->data);
    }
    root_to_set(root->left,all_nodes,leaf_nodes);
    root_to_set(root->right,all_nodes,leaf_nodes);
}
bool is_deadend(node *root){
    if (root==NULL){
        return false;
    }
    if (root->left==NULL && root->right==NULL){
        return false;
    }
    unordered_set <int> all_nodes,leaf_nodes;
    root_to_set(root,all_nodes,leaf_nodes);
    for (auto i=leaf_nodes.begin();i!=leaf_nodes.end();i++){
        int x=(*i);
        if (all_nodes.find(x-1)!=all_nodes.end() && all_nodes.find(x+1)!=all_nodes.end()){
            return true;
        }
    }
    return false;
}
int count_pairs(node *root,node *root1,int k){
    if (root==NULL || root1==NULL){
        return 0;
    }
    stack <node *> s,s1;
    node *top;
    node *top1;
    map < pair < int , int > , int > mapp;
    while (true){
        while (root!=NULL){
            s.push(root);
            root=root->left;
        }
        while (root1!=NULL){
            s1.push(root1);
            root1=root1->right;
        }
        if (s.empty() || s1.empty()){
            break;
        }
        top=s.top();
        top1=s1.top();
        if (top->data+top1->data==k){
            pair < int , int > p;
            p.first=top->data;
            p.second=top1->data;
            mapp[p]++;
            s.pop();
            s1.pop();
            root=top->right;
            root1=top1->left;
        }
        else if (top->data+top1->data<k){
            s.pop();
            root=top->right;
        }
        else {
            s1.pop();
            root1=top1->left;
        }
    }
    int count=0;
    for (auto it:mapp){
        count++;
    }
    return count;
}
void arr_to_pre(node *root,int ar[],int *i){
    if (root!=NULL){
        arr_to_pre(root->left,ar,i);
        ar[*i]=root->data;
        (*i)++;
        arr_to_pre(root->right,ar,i);
    }
}
bool check_if_preorder_is_right_or_wrong(int arr[],int n){
    node *temp=NULL;
    for (int i=0;i<n;i++){
        temp=insert(temp,arr[i]);
    }
    int *ar=new int[n];
    int i=0;
    arr_to_pre(temp,ar,&i);
    bool ans=true;
    for (int i=0;i<n;i++){
        if (arr[i]!=ar[i]){
            ans=false;
            break;
        }
    }
    if (ans){
        return true;
    }
    return false;
}
int main(){
    node *root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,7);
    // node *root1=NULL;
    // root1=insert(root1,8);
    // root1=insert(root1,9);
    // root1=insert(root1,10);
    // root1=insert(root1,11);
    // root1=insert(root1,12);
    // int abc=count_pairs(root,root1,15);
    // cout<<abc;
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int arrr[n];
        for (int i=0;i<n;i++){
            cin>>arrr[i];
        }
        bool a=check_if_preorder_is_right_or_wrong(arrr,n);
        if (a==true){
            cout<<"Y";
        }
        else {
            cout<<"F";
        }
        cout<<endl;
    }
    return 0;
}