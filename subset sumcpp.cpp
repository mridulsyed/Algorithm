#include<bits/stdc++.h>
using namespace std;

int isSubsetSum(int set[], int n, int sum)
{
	int subset[n+1][sum+1];

	for (int i = 0; i <= n; i++)
	subset[i][0] = 1;

	for (int i = 1; i <= sum; i++)
	subset[0][i] = 0;

	for (int i = 1; i <= n; i++)
	{
        for (int j = 1; j <= sum; j++)
        {
		if(j<set[i-1])
		subset[i][j] = subset[i-1][j];
		if (j >= set[i-1])
		subset[i][j] = subset[i-1][j] || subset[i - 1][j-set[i-1]];
        }
	}

	for (int i = 0; i <= n; i++)
	{
	for (int j = 0; j <= sum; j++)
		cout<<subset[i][j]<<" ";
    cout<<endl;
	}
	return subset[n][sum];
}
int main(){
int set[] = {3, 4, 5};
int sum = 9;
int n = sizeof(set)/sizeof(set[0]);
if (isSubsetSum(set, n, sum) == 1)
	printf("Subset Found");
else
	printf("Not Found");
}
