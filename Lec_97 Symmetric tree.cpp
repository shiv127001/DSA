#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }

} node;

node *buildtree()
{
    int value;
    int value1;
    int value2;
    cout << "Enter the value for node (-1 for NULL)";
    cin >> value;

    node *root = new node(value);
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();

        cout << "Enter the left child for " << current->data << " (-1 for NULL)";
        cin >> value1;
        if (value1 != -1)
        {
            current->left = new node(value1);
            q.push(current->left);
        }

        cout << "Enter the right child for " << current->data << " (-1 for NULL)";
        cin >> value2;
        if (value2 != -1)
        {
            current->right = new node(value2);
            q.push(current->right);
        }
    }
    return root;
}

// METHOD 1
void preorder_traversal_1(node *a, vector<int> &temp)
{
    if (a == NULL)
        return;
    temp.push_back(a->data);
    preorder_traversal_1(a->left, temp);
    preorder_traversal_1(a->right, temp);
    // return temp;
}
void preorder_traversal_2(node *a, vector<int> &temp)
{
    if (a == NULL)
        return;
    temp.push_back(a->data);
    preorder_traversal_2(a->right, temp);
    preorder_traversal_2(a->left, temp);
}

bool isSymmetric(node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->left == NULL && root->right != NULL)
        return false;
    if (root->left != NULL && root->right == NULL)
        return false;
    vector<int> l1, l2;
    preorder_traversal_1(root->left, l1);
    preorder_traversal_2(root->right, l2);
    if (l1.size() != l2.size())
    {
        return false;
    }
    for (int i = 0; i < l1.size(); ++i)
    {
        if (l1[i] != l2[i])
        {
            return false;
        }
    }
    return true;
}

// METHOD 2
bool symm(node *a, node *b)
{
    if (a == NULL && b != NULL)
        return false;
    if (a != NULL && b == NULL)
        return false;
    if (a == NULL && b == NULL)
        return true;
    if (a->data != b->data)
        return false;
    return symm(a->left, b->right) && symm(a->right, b->left);
    // return true;
}
bool isSymmetric(node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->left == NULL && root->right != NULL)
        return false;
    if (root->left != NULL && root->right == NULL)
        return false;
    return symm(root->left, root->right);
}

int main()
{
    cout << "Tree1";
    node *t1 = buildtree();
    bool a = isSymmetric(t1);
    cout << a;
    return 0;
}