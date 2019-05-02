#include<iostream>
using namespace std;

class AdjMat
{
    bool mat[100][100];
    int e,v,a,b,i,j,start;
    bool vis[100];
public:
    void create()
    {
       cout<<"Enter number of vertices and edges";
       cin>>v>>e;
       for(i=0;i<v;i++)
       {
           vis[i]=false;
       }
       for(i=0;i<e;i++)
       {
           cout<<"Enter vertices for edge "<<i+1<<" - "<<endl;
           cin>>a>>b;
           mat[a][b]=1;
       }
       for(i=0;i<v;i++)
       {
           for(j=0;j<v;j++)
           {
               cout<<mat[i][j];
           }
           cout<<"\n";
       }
    }

    void DFS(int start)
    {     
        vis[start]=1;
        cout<<start;
        for(int x=0;x<=v;x++)
        {
            if(mat[start][x]&&!vis[x])
            {
                DFS(x);
            }
        }
    }
};

int main()
{
    int src;
    AdjMat m;
    m.create();
    cout<<"\nEnter source";
    cin>>src;
    m.DFS(src);
}

