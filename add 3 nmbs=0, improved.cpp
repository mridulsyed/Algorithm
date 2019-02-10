#include<bits/stdc++.h>
using namespace std;

void Merge(int Array[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int Left[n1], Right[n2];

    for (i = 0; i < n1; i++)
        Left[i] = Array[low + i];
    for (j = 0; j < n2; j++)
        Right[j] = Array[mid + 1+ j];
    i = 0;j = 0;k = low;
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            Array[k] = Left[i];
            i++;
        }
        else
        {
            Array[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        Array[k] = Left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        Array[k] = Right[j];
        j++;
        k++;
    }
}
void mergeSort(int Array[], int low, int high)
{
    if (low < high)
    {
        int mid = (low+high)/2;

        mergeSort(Array, low, mid);
        mergeSort(Array, mid+1, high);

        Merge(Array, low, mid, high);
    }
}
int BinarySearch(int Array[], int low, int high, int x) ///here goes Binary search instead of brute force
{
    if(high >= low)
       {
    int mid = (high+low)/2;
    if(Array[mid] == x)
        return mid;
     if(Array[mid] > x)
        return BinarySearch(Array,low,mid-1,x);
     return BinarySearch(Array,mid+1,high,x);
}
return -1;
}
int main()
{
  FILE *file;
  int n;
  int result; ///will be used to search negative of added nmbr

  cout <<"Enter the value of n: ";
  cin >> n;
  int Data[n];
  srand(time(0));

  file =fopen("input.txt","r");
  for(int i = 0; i < n; i++)
  {
      fscanf(file,"%d", &Data[i]);
  }
   fclose(file);

   mergeSort(Data,0,n-1);
   clock_t start = clock();

   for(int i = 0; i < n; i++)
   {
       for(int j = 0; j < n; j++)
       {
           result = -(Data[i]+Data[j]);
           int t = BinarySearch(Data,0,n-1,result); ///searching (-)result in Data
           if(t != -1) ///if not found it will be -1
           {
               cout << Data[i] << "," << Data[j] << "," << Data[t] << endl;
           }
       }
   }

 clock_t End = clock();
   double diff = (double)(End-start)/(2500000000);
   cout << endl;
   cout << "Execution time : " << diff << endl;
}
