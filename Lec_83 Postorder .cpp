#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef struct node{
    int data ;
    struct node* left;
    struct node* right;
}node;


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
    return postorder;
}