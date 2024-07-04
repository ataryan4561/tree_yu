#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val=0;
    Node* left=NULL;
    Node* right=NULL;
    Node(int val,Node* left,Node* right)
    {
        this->val=val;
        this->left=left;
        this->right=right;
    }
    Node(int val)
    {
        this->val=val;
    }
    Node()
    {}
};
Node* insert(Node* root,int val)
{
    if(!root)
        return new Node(val);
    if(val<root->val)
    {
        root->left = insert(root->left,val);
    }
    else if(val>root->val)
    {
        root->right = insert(root->right,val);
    }
    return root;
}
bool search(Node* root,int val)
{
    if(!root)
        return false;
    else if(val<root->val)
    {
        if(search(root->left,val)==true)
            return true;
        else
            return false;
    }
    else if(val>root->val)
    {
        if(search(root->right,val)==true)
            return true;
        else
            return false;
    }
    else
        return  true;
    return false;
}
Node* delete_node(Node* root,int val)
{
    if(!root)
        return root;
    if(val<root->val)
    {
        root->left = delete_node(root->left,val);
        return root;
    }
    else if(val>root->val)
    {
        root->right = delete_node(root->right,val);
        return root;
    }
    if(!root->left)
    {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (!root->right) 
    {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    Node* succParent = root;
    Node* succ = root->right;
    while (!succ->left) 
    {
        succParent = succ;
        succ = succ->left;
    }
    root->val = succ->val;
    if (succParent->left == succ)
        succParent->left = succ->right;
    else
        succParent->right = succ->right;
    delete succ;
    return root;
}
void print(Node* root)
{
    if(!root)
        return;
    cout<<root->val<<" ";
    if(root->left)
        print(root->left);
    if(root->right)
        print(root->right);
}
int  main()
{
    Node* root = new Node(10);
    root = insert(root,12);
    root = insert(root,13);
    root = insert(root,15);
    root = insert(root,16);
    root= insert(root,18);
    root = insert(root,14);
    print(root);
    cout<<search(root,20)<<" ";
    root = delete_node(root,12);
    print(root);
}