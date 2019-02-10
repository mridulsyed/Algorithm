#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool adj(int u,int v);
bool check[100];
bool adj_matrix[100][100];

int main(){
int number;
cout<<"Enter the number of node in the graph...!\n";
cin>>number;
int x=0;


//Adjacent matrix...
cout<<"Enter Adjacency Table : \n";
for(int i=1;i<=number;i++){
    for(int j=1;j<=number;j++){
     // x=rand()%2;
      cin>>adj_matrix[i][j];
    }
}
//Matrix...
cout<<"The adjacent matrix is given bellow....!\n";
for(int i=1;i<=number;i++){
    for(int j=1;j<=number;j++){
            cout<<"   "<<adj_matrix[i][j]<<ends;
}
cout<<"\n";
}

for(int i=1;i<=number;i++)
{0 1 0 0 0 0
0 0 1 0 0 0
0 0 0 1 1 1
1 0 0 0 0 0
0 0 0 0 0 0
1 0 0 0 0 0
    check[i]=0;
}



stack <int> STACK;
int A;
cout<<"\nEnter the source node...!\n";
cin>>A;
STACK.push(A);
check[A]=1;
cout<<"\n\nThe traversed nodes are given bellow...!\n";
while(STACK.size()!=0)
{
state :
    int u;
    u=STACK.top();
    cout<<u<<"  "<<ends;
    STACK.pop();
    check[1]=0;


    for(int v=1;v<=number;v++)
        {
        if((adj(u,v)==1) && check[v]==0)
          {
           STACK.push(v);
           check[v]=1;
          goto state;
          }

        }

}
cout<<"\n\n\n";
return 0;
}

bool adj(int u,int v){
if(adj_matrix[u][v]==1)
    return 1;
else
return 0;
}
