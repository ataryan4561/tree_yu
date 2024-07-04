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
    if(root->left)
        print(root->left);
    cout<<root->val<<" ";
    if(root->right)
        print(root->right);
}
int find_min(Node* root)
{
    if(!root->right && !root->left)
        return root->val;
    else if(!root->left)
        return root->val;
    else if(!root->right)
    {
        while(!root->left)
        {
            root=root->left;
        }
        return root->val;
    }
    else
    {
        while(!root->left)
        {
            root=root->left;
        }
        return root->val;
    }
}
vector<int> lst;
void sorti(Node* root)
{
    if(!root)
        return;
    sorti(root->left);
    lst.push_back(root->val);
    sorti(root->right);
}
int k_max(Node* root,int k)
{
    sorti(root);
    return lst[size(lst)-k];
}
bool helper(Node* root,int k,vector<int>& ans)
{
    if(!root)
        return false;
    else if(root->val==k)
        return true;
    bool leftans = helper(root->left,k,ans);
    if(leftans)
    {
        ans.push_back(root->val);
        return true;
    }
    bool rightans = helper(root->right,k,ans);
    if(rightans)
    {
        ans.push_back(root->val);
        return true;
    }
    return false;
}
vector<int> ancestor(Node* root,int k)
{
    vector<int> ans;
    bool ans1 = helper(root,k,ans);
    return ans;
}
int find_height(Node* root)
{
    if(!root)
        return 0;
    int lefthe = find_height(root->left);
    int righthe = find_height(root->right);
    return max(lefthe,righthe)+1;
}
void helper1(Node* root,int k,vector<int>& ans)
{
    if(!root)
        return;
    if(k==0)
    {
        ans.push_back(root->val);
        return;
    }
    else
    {
        helper1(root->left,k-1,ans);
        helper1(root->right,k-1,ans);
    }
}
vector<int> find_k_nodes(Node* root,int k)
{
    vector<int> ans;
    helper1(root,k,ans);
    return ans;
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
    cout<<k_max(root,3);
    vector<int> ans = ancestor(root,18);
    cout<<endl;
    for(auto e:ans)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    cout<<find_height(root);
}