#include<bits/stdc++.h>
using namespace std;

void Merge(int Array[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int Left[n1], Right[n2]; ///creating temporary arrays

    for (i = 0; i < n1; i++)  /// Copy data to temporary arrays
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
int main()
{
  FILE *file;
  int result;
  int i,n;
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

   clock_t start = clock();
   mergeSort(Data,0,n-1);  ///merge sort is being called
   clock_t End = clock();
   double duration = (double)(End-start)/(2500000000);
   for(int i =0; i< n; i++)
   {
       cout << Data[i] << " ";
   }
   cout << endl;
   cout << "Execution time for merge sort: " << duration << endl;
}
