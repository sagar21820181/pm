#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class expNode
{
public:
    char data;
    expNode *left,*right;
    expNode* accept(char s)
    {
        expNode* newNode=new expNode;
        newNode->data=s;
        newNode->left=newNode->right=NULL;
        return newNode;
    }
    friend class stack;
};

class stackNode
{
    stackNode *next;
    expNode *val;
public:
    friend class stackptr;
};

class stackptr
{
    stackNode *top;
public:
    void push(expNode *node)
    {
        if(top==NULL)
        {
            stackNode *s=new stackNode;
            s->val=node;
            s->next=NULL;
            top=s;
        }
        else
        {
            stackNode *s=new stackNode;
            s->val=node;
            s->next=top;
            top=s;
        }
    }
    expNode *pop()
    {
        stackNode *temp=top;;
        expNode *tn=temp->val;
        top=top->next;
        temp->next=NULL;
        delete temp;
        return tn;
    }

};

bool isop(char c)
{
    if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
        return true;
    else
        return false;
}


void inorder(expNode *t)
{
    if(t)
    {
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}

void preorder(expNode *t)
{
    if(t)
    {
        cout<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }
}

void postorder(expNode *t)
{
    if(t)
    {
        postorder(t->left);
        postorder(t->right);
        cout<<t->data<<" ";
    }
}


int main()
{

    char pf[100];
    stackptr s1;
    expNode *tr,*tl,*n1;
    cout<<"Enter postfix code "<<endl;
    cin>>pf;
    for(int i=0;i<strlen(pf);i++)
    {
        n1=n1->accept(pf[i]);
        
        if(!isop(pf[i]))
        {
            s1.push(n1);
        }

        else
        {
            tr=s1.pop();
            tl=s1.pop();
            n1->right=tr;
            n1->left=tl;
            s1.push(n1);
        }

    }

    n1=s1.pop();
    
    cout<<"Preorder is  - \t";
    preorder(n1);
    cout<<"\nInorder is  - \t";
    inorder(n1);
    cout<<"\nPostorder is  - \t";
    postorder(n1);
}

