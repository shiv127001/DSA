#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include<queue>
using namespace std;

typedef struct node{
    int data ;
    struct node* left;
    struct node* right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }

}node;

node* buildTree()
{
    int value;
    int value1;
    int value2;
    cout <<"Enter the value for node (-1 for NULL)";
    cin>>value;
    
    node* root = new node(value);
    queue <node*> q ;
    q.push(root);
    
    while(!q.empty())
    {
        node* current = q.front();
        q.pop();
        cout<<"Enter the left child for node "<<current->data<<" (-1 for NULL)";
        cin >>value1;
        if(value1!=-1)
        {
            current->left = new node(value1);
            q.push(current->left);
        }
        cout<<"Enter the right child for node "<<current->data<<" (-1 for NULL)";
        cin >>value2;
        if(value2!=-1)
        {
            current->right = new node(value2);
            q.push(current->right);
        }
    }
    return root;
}

// Postorder Traversal
void postorder_traversal_recursively(node* root) {
    if (root == nullptr) return;
    postorder_traversal_recursively(root->left);
    postorder_traversal_recursively(root->right);
    cout << root->data << " ";
}

vector<int> postorder_traversal_iteratively(struct node* root)
{
    vector<int> postorder;
    if (root== NULL)
    {
        return postorder;
    }
    stack <struct node*> st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL)
        {
            st1.push(root->left);
        }
        if(root->right!=NULL)
        {
            st1.push(root->right);
        }
    }
    while(!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    for (int i=0;i<postorder.size();++i)
    {
        cout<<postorder[i]<<", ";
    }
    return postorder;
}

int main()
{
    cout << "Build Tree 1:\n";
    node* root1 = buildTree();

    cout<<"printing by postorder_traversal_iteratively\n";
    postorder_traversal_iteratively(root1);

    cout<<"\n\nprinting by postorder_traversal_recursively\n";
    postorder_traversal_recursively(root1);

    return 0;
}
