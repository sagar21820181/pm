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
    
    int Height(bst *root)
    {
        if(root==NULL)
            return 0;
        
        else
        {
        int lHt=Height(root->left);
        int rHt=Height(root->right);
        
        if(lHt>rHt)
            return lHt+1;
        else
            return rHt+1;
    
        }
    }
        
    int Min(bst *root)
    {
        if(root==NULL)
            cout<<"Tree doesn't exist";
        else
            while(root->left=NULL)
            {
                root=root->left;
            }
            
        return root->val;
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
    cout<<"\n\nHeight of BST is = "<<SearchTree->Height(SearchTree)<<endl;
    cout<<"\nMinimum value in BST is = "<<SearchTree->Min(SearchTree);
    }

