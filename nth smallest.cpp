#include<bits/stdc++.h>
using namespace std;
int partition(int Array[], int left, int right);
int kthSmallest(int Array[],int left,int right,int k)
{
        int pos=partition(Array, left, right);

        if(pos==k-1) return Array[pos];
        if(pos>k-1) return kthSmallest(Array,left,pos-1,k);
        return kthSmallest(Array,pos+1,right,k);

}
void swap(int *a, int *b)
{
    int temp= *a;
    *a=*b;
    *b=temp;
}
int partition(int Array[], int left, int right)
{
    int x=Array[right],i=left;  ///here pivot is the last element
    for(int j=left;j<=right-1;j++)
    {
        if(Array[j]<=x)
        {
            swap(&Array[i], &Array[j]);
            i++;
        }
    }
    swap(&Array[i],&Array[right]);  ///pivot swapping
    return i;

}
int main()
{
  FILE *file;
  int n,k;
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
   cout<<endl;
   for(int i=0;i<n;i++)
   {
    cout<<"Enter the kth smallest Or press 0 to exit : ";
   cin>>k;
   if(k==0) break;
   cout<<"The "<<k<<"th smallest element is : "<<kthSmallest(Array,0,n-1,k)<<endl;
   }
   cout<<endl<<endl;
   cout<<"Sorted Array is : ";
   for(int z=1;z<=n;z++)
   cout<<kthSmallest(Array,0,n-1,z)<<" ";

   cout<<endl<<endl;
}


