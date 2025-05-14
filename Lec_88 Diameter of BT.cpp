#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>
using namespace std;

typedef struct node{
    int data ;
    struct node* left;
    struct node* right;
}node;

int maxi = 0;

int diameter(node* root, int maxi)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = diameter(root->left,maxi);
    int rh = diameter(root->right,maxi);
    maxi = max(maxi, lh+rh);
    return 1+max(lh,rh);
}
