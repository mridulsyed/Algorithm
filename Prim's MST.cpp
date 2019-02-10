#include <bits/stdc++.h>
using namespace std;
int V;
int minKey(int key[], bool mstSet[]){
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++){
	if(mstSet[v] == false && key[v] < min)
		{
        min = key[v];
		 min_index = v;
		 }
}
return min_index;
}
int main(){
    cout<<"Enter the number of vertex : ";
    cin>>V;
    int graph[V][V];
    int number=V,x;
    srand(time(0));

    for(int i=0;i<number;i++){
    for(int j=0;j<number;j++){
        cin>>x;
      graph[i][j]=x;
      }
    }
cout<<endl;
    int parent[V];
	int key[V];
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V-1; count++)
	{
		int u = minKey(key, mstSet);
        mstSet[u] = true;

		for (int v = 0; v < V; v++)

		if (graph[u][v]!=0 && mstSet[v] == false && graph[u][v] < key[v])
			parent[v] = u, key[v] = graph[u][v];
	}

	printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        {printf("%d - %d \t%d \n", parent[i]+1, i+1, graph[i][parent[i]]);}

}


