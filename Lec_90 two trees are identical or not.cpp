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
        cin>>value;
        if(value != -1)
        {
            current->left = new node(value);
            q.push(current->left);
        }
    }


}