#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

int pathsum(node *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }

    int lsum = max(0, pathsum(root->left, maxi));
    int rsum = max(0, pathsum(root->right, maxi));
    maxi = max(maxi, lsum + rsum + root->data);
    return root->data + max(lsum, rsum);
}

int maxPathSum(node *root)
{
    int maxi = INT_MIN;
    int sum = pathsum(root, maxi);
    return maxi;
}
