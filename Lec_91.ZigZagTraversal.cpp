#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
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

node* buildtree()
{
    int value;
    int value1;
    int value2;
    cout <<"Enter the value for node (-1 for NULL)";
    cin>>value;

    node* root = new node(value);
    queue<node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        node* current = q.front();
        q.pop();

        cout<<"Enter the left child for "<<current->data<<" (-1 for NULL)";
        cin>>value1;
        if(value1 != -1)
        {
            current->left = new node(value1);
            q.push(current->left);
        }

        cout<<"Enter the right child for "<<current->data<<" (-1 for NULL)";
        cin>>value2;
        if(value2 != -1)
        {
            current->right = new node(value2);
            q.push(current->right);
        }
    }
    return root;
}

vector<vector<int>> ZigZagTraversal(node* tree)
{

}

int main()
{
    cout<<"Tree1";
    node* t1 = buildtree();
    vector<vector<int>>a = ZigZagTraversal(t1);
    for(int i=0;i<a.size();++i)
    {
        for(int j=0;j<a[i].size();++i)
        {
            cout<<a[i][j]<<", ";
        }
        cout<<endl;
    }
    return 0;
}