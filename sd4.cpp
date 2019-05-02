#include<iostream>
using namespace std;

class bst
{
    int val;
    bst *left,*right;
public:
    bst *create(int k)
    {
        bst *newNode=new bst;
        newNode->val=k;
        newNode->left=newNode->right=NULL;
        return newNode;
    }
    
    bst *insert(bst *node,int k)
    {
        if(node==NULL)
            return create(k);
        
        if(k>node->val)
            node->right=insert(node->right,k);
        
        if(k<node->val)
            node->left=insert(node->left,k);
        
        return node;
    }
      
    void inorder(bst *t)
    {
        if(t)
        {
            inorder(t->left);
            cout<<t->val<<" ";
            inorder(t->right);
        }
    }
    
    void swap(bst *root)
    {
        bst *temp;
        if(root==NULL)
            return;
        else
        {
            swap(root->left);
            swap(root->right);
            temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
    }

};

int main()
{
    bst *SearchTree=NULL;
    int n,data;
    cout<<"How many values do you want to enter in the tree?\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter value ("<<i+1<<") -> ";
        cin>>data;
        SearchTree=SearchTree->insert(SearchTree,data);
    }
    
    cout<<"\nInorder Traversal of Tree = ";
    SearchTree->inorder(SearchTree);
    cout<<"\nSwapped Tree is - "<<endl;
    SearchTree->swap(SearchTree);
    SearchTree->inorder(SearchTree);

}  

