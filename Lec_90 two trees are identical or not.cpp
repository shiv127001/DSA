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

bool are_identical(node* t1, node* t2)
{
    if (t1== NULL && t2==NULL) return true;
    if (t1== NULL || t2==NULL) return false;
    int l1,l2;
    l1 = t1->data;
    l2 = t2->data;
    if(l1!=l2) return false;
    are_identical(t1->left,t2->left);
    are_identical(t1->right,t2->right);
}

int main()
{
    cout<<"Tree1";
    node* t1 = buildtree();
    cout<<"\nTree2";
    node* t2 = buildtree();
    cout<<are_identical(t1,t2);
    return 0;
}