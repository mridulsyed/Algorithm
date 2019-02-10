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

struct item
{
    int weight;
    int price;
};
item it[3];

void sortArray(item array[], int size)
{
    bool swapped;
    do{
        swapped=false;
        for(int i=0;i<size-1;i++)
        {
            if(array[i].price<array[i+1].price)
            {
                swap(array[i],array[i+1]);
                swapped =true;
            }
        }
    } while(swapped);

}

void showArray(const item array[], int size)
{
    for(int i=0;i<size; i++)
        cout<<array[i].price<<" "<<array[i].weight<<" "<<endl;
}
int main()
{
    int p[] = {1,2,5};
    int wt[] = {2,3,4};
    int  m = 8;
    int n = 3;
    int W=6;
    int Result[3];

  for(int i=0;i<n;i++)
  {
      it[i].price=p[i];
      it[i].weight=wt[i];
      cout<<"Item "<<i+1<<" :::   Price : "<<it[i].price<<"    "<<"Weight : "<<it[i].weight<<endl;
  }
  cout<<endl;
  cout<<"Condition Weight : "<<W<<endl;

   for(int z=n;z>0;z--)
   Result[abs(z-n)]=kthSmallest(p,0,n-1,z);

  cout<<"\nSorted Array is : ";
   for(int z=0;z<n;z++)
   cout<<Result[z]<<" ";

   cout<<endl<<endl;
   sortArray(it,n);
   showArray(it,n);
   cout<<endl;

   int cumweight=0;
   for(int i=0;i<n;i++)
   {
       if(it[i].weight<=W)
       {
           cout<<i+1<<"th item is taken"<<endl;
        cumweight=cumweight+it[i].weight;
       W=W-it[i].weight;
       }
   }
   cout<<endl;
   cout<<"Solution : "<<cumweight<<endl;

}
