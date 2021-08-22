#include<bits/stdc++.h>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    vector<Node*> children;
    Node(int data)
    {
        this->data=data;
    }
};
void display(Node *r)
    {
        cout<<r->data<<"-> ";
        for(Node *child: r->children)
        {
            cout<<child->data<<",";
        }
        cout<<endl;
        for(Node *child :r->children)
        {
            display(child);
        }
    }
Node *create(vector<int> arr)
{
     stack<Node*> st;
    for(int i=0; i<arr.size()-1; i++)
    {
        if(arr[i]==-1)
        {
            if(st.size()>0)
                st.pop();
        }
        else
        {
            Node *t=new Node(arr[i]);
            if(st.size()>0)
                st.top()->children.push_back(t);
            st.push(t);
        }
    }
    return st.top();
}
int size(Node *root)
{
    int s=0;
    for(Node *child : root->children)
    {
        int cs=size(child);
        s=s+cs;
    }
    s=s+1;
    return s;
}
int maxa(Node *root)
{
    int maxx=0;
    for(Node *child : root->children)
    {
        int maxi=maxa(child);
        maxx=max(maxx,maxi);
    }
    return max(maxx,root->data);
}
int height(Node *root)
{
    int ans=-1;
    for(Node *child: root->children)
    {
        int ch=height(child);
        ans=max(ch,ans);
    }
    ans+=1;
    return ans;
}
void preorder(Node *root)
{
    cout<<root->data<<" ";
    for(Node *child: root->children)
    {
        // cout<<child->data<<" ";
        preorder(child);
    }
}
void postorder(Node *root)
{
    for(Node *child : root->children)
    {
        postorder(child);
        // cout<<child->data<<" ";
    }
    cout<<root->data<<" ";
}
void leveltravesel(Node *root)
{
    queue<Node*> qu;
    qu.push(root);
    while(qu.size()!=0)
    {
        Node *n=qu.front();
        qu.pop();
        cout<<n->data<<" ";
        for(Node *child :n->children)
        {
            qu.push(child);
        }
    }
}
void levelorderline(Node *root)
{
    queue<Node*> qu;
    queue<Node*> qu1;
    qu.push(root);
    while(qu.size()>0)
    {
        Node *n=qu.front();
        qu.pop();
        cout<<n->data<<" ";
        for(Node *child :n->children)
        {
            qu1.push(child);
        }
        if(qu.size()==0)
        {
            qu=qu1;
            cout<<endl;
            while(qu1.size()!=0)
            {
                qu1.pop();
            }
        } 
    }
}
void mirror(Node *root)
{
    for(Node *child: root->children)
    {
        mirror(child);
    }
    reverse(root->children.begin(), root->children.end());
}
bool findele(Node *root,int data)
{
    bool ans=false;
    for(Node *child : root->children)
    {
        bool anss =findele(child,data);
        ans=anss;
    }
    if(root->data==data)
    {
        return true;
    }
    return ans;
}
vector<int> noderootpath(Node *root,int data)
{
    if(root->data==data)
    {
        vector<int> ans;
        ans.push_back(root->data);
        return ans;
    }
        for(Node *child : root->children)
        {
            vector<int> an=noderootpath(child,data);
            if(an.size()>0)
            {
                an.push_back(root->data);
                return an;
            }
        }
        vector<int> ans;
        return ans;
}
// void removeleaves(Node *root)
// {
//     for(int i=root->children.size()-1; i>=0; i--)
//     {
//         Node *ch=root->children[i];
//         cout<<ch->data<<" ";
//         if(ch->children.size()==0)
//         {

//         }
//     }
//     cout<<endl;
//     for(Node *child: root->children)
//     {
//         removeleaves(child);
//     }
// }
// Node *gettail(Node *n)
// {
//     while(n->children.size()==1)
//     {
//         n=n->children[0];
//     }
//     return n;
// }
// void linear(Node *root)
// {
//     for(Node *child :root->children)
//     {
//         linear(child);
//     }
//     while(root->children.size()>1)
//     {
//         Node *lc=root->children[root->children.size()-1];
//         root->children.pop_back();
//         Node *s1=root->children[root->children.size()-1];
//         Node *slt=gettail(s1);
//         slt->children.push_back(s1);
//     }
// }
int main()
{
    vector<int> arr;
    arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    // cout<<arr.size();
    Node *root=create(arr);
    // display(root);
    // cout<<size(root)<<endl;
    // cout<<maxa(root)<<endl;
    // cout<<height(root)<<endl;
    // preorder(root);
    // cout<<endl;
    // postorder(root);
    // leveltravesel(root);
    // levelorderline(root);
    // mirror(root);
    // removeleaves(root);
    // linear(root);
    // display(root);
    // cout<<findele(root,10);
    vector<int> ans=noderootpath(root,110);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}