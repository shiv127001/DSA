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

bool isLeaf(node* root)
{
    if(root!= NULL && root->left == NULL && root->right== NULL) return true;
    else return false;
}

void leftTraversal(node* root,vector<int>& res)
{
    node* currLeft = root->left;
    while(currLeft)
    {
        if(!isLeaf(currLeft)) res.push_back(currLeft->data);
        if(currLeft->left !=NULL) currLeft = currLeft->left;
        else currLeft = currLeft->right;
    }
}
void leavesTraversal(node* root,vector<int>& res)
{
    if(isLeaf(root)) 
    {
        res.push_back(root->data);
        return;
    }
    if(root->left) leavesTraversal(root->left, res);
    if(root->right) leavesTraversal(root->right, res);
}
void rightTraversal(node* root,vector<int>& res)
{
    vector<int> temp ;
    node* currRight = root->right;
    while(currRight)
    {
        if(!isLeaf(currRight)) temp.push_back(currRight->data);
        if(currRight->right) currRight = currRight->right;
        else currRight = currRight->left;
    }
    for(int i=temp.size()-1;i>=0;--i)
    {
        res.push_back(temp[i]);
    }
}

vector<int> Boundarytraversal(node *root)
{
    vector<int>res;
    if (root == NULL) return {};
    if(isLeaf(root)) 
    {
        res.push_back(root->data);
        return res;
    }
    res.push_back(root->data);
    leftTraversal(root,res);
    leavesTraversal(root,res);
    rightTraversal(root,res);
    return res;
}
int main()
{
    cout << "Tree1";
    node *t1 = buildtree();
    vector<int> a = Boundarytraversal(t1);
    cout<<"Boundary level traversal is\n";
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << ", ";
    }
    return 0;
}