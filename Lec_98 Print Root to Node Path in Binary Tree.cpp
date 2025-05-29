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

bool root_to_node_path(node* root,int value,vector<int> &res)
{
    if (root == NULL) return false;
    res.push_back(root->data);
    if (value == root->data) return true ;
    if(root_to_node_path(root->left,value,res) || root_to_node_path(root->right, value,res) ) 
    {
        return true;
    }
    res.pop_back();
    return false;
}

int main()
{
    cout << "Tree";
    node *t1 = buildtree();
    int value ;
    cout<<"Enter the nodes value:\n";
    cin>>value;
    vector<int> res;
    bool a = root_to_node_path(t1,value,res);
    int len = res.size();
    cout<<"THE PATH FROM THE ROOT NODE TO GIVEN NODE IS : \n";
    for(int i=0;i<len;++i)
    {
        cout<<res[i]<<"->";
    }
    cout<<"\n-----Ans is : "<<a;
    cout<<endl;
    return 0;
}
