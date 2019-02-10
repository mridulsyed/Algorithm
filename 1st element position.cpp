#include<bits/stdc++.h>
using namespace std;
int partition(int Array[], int left, int right);

void swap(int *a, int *b)
{
    int temp= *a;
    *a=*b;
    *b=temp;
}
int partition(int Array[], int left, int right)
{
    int x=Array[0],i=right;   ///here pivot is 1st element
    for(int j=right;j>=left+1;j--)
    {
        if(Array[j]>=x)
        {
            swap(&Array[i], &Array[j]);
            i--;
        }
    }
    swap(&Array[i],&Array[0]);   ///swapping the pivot
   cout<<"Position of 1st element : "<<i+1<<endl<<endl;
}
int main()
{
  FILE *file;
  int n,k,z;
  while(z!=n){
  cout <<"Enter the value of n(total elements): ";
  cin >> n;
  int Array[n];

  file = fopen("input.txt","r");
  for(int i = 0; i < n; i++)
  {
      fscanf(file,"%d", &Array[i]);
       printf("%d ", Array[i]);
  }
   fclose(file);
   cout<<endl<<endl;

   partition(Array,0,n-1);
   z++;
  }
}


