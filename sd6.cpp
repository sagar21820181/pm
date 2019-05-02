#include<iostream>
using namespace std;
class vertex
{
    int data,v1,v2,v,e;
    vertex *next;
    vertex *head[10];

public:

    void create()
    {   
        for(int i=0;i<11;i++)
        {
            cout<<head[i]->data;
        }
        cout<<head[1]->data;
        cout<<"Enter no. of vertices and edges";
        cin>>v>>e;
        vertex *temp;0
        for(int i=0;i<e;i++)
        {
            cout<<"Enter start and end vertices for edge "<<i+1;
            cin>>v1>>v2;
            vertex *newvert=new vertex;
            newvert->next=NULL;
            newvert->data=v2;
            if(head[v1]->next==NULL)
            {
                head[v1]->next=newvert;
            }
            else
            {
                temp=head[v1];
                while(temp->next->data<newvert->data)
                    temp=temp->next;
                temp->next=newvert->next;
                temp->next=newvert;
                
            }
        }
        
    }
};


int main()
{
    vertex vvv;
    vvv.create();
}

