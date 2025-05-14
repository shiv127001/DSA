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


int height(struct node *root)
{
    if (root == NULL)
        return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1, h2);
}

int isBalanced_method1(struct node *root)
{
    if (root == NULL)
        return 0;
    int h1 = isBalanced_method1(root->left);
    if (h1 == -1)
        return -1;
    int h2 = isBalanced_method1(root->right);
    if (h2 == -1)
        return -1;
    // if(h1==-1 || h2==-1) return -1;
    if (abs(h1 - h2) > 1)
        return -1;
    return 1 + max(h1, h2);
}

bool isBalanced(struct node *root)
{
    if (root == NULL)
    {
        return true;
    }

    int hh1 = height(root->left);
    int hh2 = height(root->right);
    if (abs(hh1 - hh2) > 1)
        return false;

    bool lt = isBalanced(root->left);
    bool rt = isBalanced(root->right);

    if (lt == false || rt == false)
        return false;

    return true;
}
