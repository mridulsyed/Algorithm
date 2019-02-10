#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int W, int weight[], int price[], int n)
{
int i, j;
int K[n+1][W+1];

for (i = 0; i <= n; i++)
{
	for (j = 0; j <= W; j++)
	{
		if (i==0 || j==0)
			K[i][j] = 0;
		else if (weight[i-1] <= j)
				K[i][j] = max(price[i-1] + K[i-1][j-weight[i-1]], K[i-1][j]);
		else
				K[i][j] = K[i-1][j];
	}
}
return K[n][W];
}
int main(){
    int n, W;
    cout<<"Enter the number of pair of weight & price : ";
    cin>>n;
    int price[n];
    int weight[n];
    cout<<"Enter boundary weight : ";
    cin>>W;
    cout<<"Enter the prices : ";
    for(int i=0;i<n;i++)
        cin>>price[i];

    cout<<"Enter the weights : ";
    for(int i=0;i<n;i++)
        cin>>weight[i];

	cout<<"\nThe solution using DP is : "<<knapSack(W, weight, price, n)<<endl;
}

