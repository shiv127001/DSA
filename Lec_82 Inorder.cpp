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

void inorder_recursively(struct node* newnode)
{
    if (newnode ==NULL)
        return ;
    
        inorder_recursively (newnode->left);
        cout<<newnode->data;
        inorder_recursively(newnode->right);

}

vector<int> inorder_traversal_iteratively(struct node* newnode)
{
    stack<struct node*> st;
    vector<int> inorder;
    struct node* root = newnode;
    while (true)
    {
        if (root!=NULL)
        {
            st.push(root);
            root = root->left;
        }

        else {
            if (st.empty()) break;
            root = st.top();
            st.pop();
            inorder.push_back(root->data);
            root = root->right;
        }
    }
    return inorder;
}

