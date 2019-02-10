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
for(int i=1;i<=number;i++){
    for(int j=1;j<=number;j++){
      cin>>x;
      adj_matrix[i][j]=x;
    }
}
cout<<"The adjacent matrix is given bellow....!\n";
for(int i=1;i<=number;i++){
    for(int j=1;j<=number;j++){
            cout<<"   "<<adj_matrix[i][j]<<ends;
}
cout<<"\n";
}

for(int i=1;i<=number;i++){
    check[i]=0;
}
stack <int> STACK;
int A,flag;
cout<<"\nEnter the source node...!\n";
cin>>A;
STACK.push(A);
check[A]=1;
cout<<"\n\nThe traversed nodes are given bellow...!\n";
while(STACK.size()!=0){

    int u;
    u=STACK.top();
    cout<<u<<" "<<ends;
    STACK.pop();
    check[A]=0;

    for(int v=1;v<=number;v++){
        if((adj(u,v)==1) && check[v]!=1)
        {
          STACK.push(v);
          check[v]=1;
           if(check[A]==1) { flag=1;}
            else flag=0;
        }
    }


}
if(flag==1) cout<<"\n\nCreates a cycle";
else cout<<"\n\nDoesnt create a cycle";
cout<<"\n\n\n";
return 0;
}

bool adj(int u,int v){
if(adj_matrix[u][v]==1)
    return 1;
else
return 0;
}
