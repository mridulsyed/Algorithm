#include<bits/stdc++.h>
using namespace std;
int main()
{
  FILE *file;
  int i;
  int k; ///k nmbr will be picked from n
  int temp; ///will be used in swaping
  cout <<"Enter the value of k: ";
  cin >> k;
  int Array[k];
  srand(time(0));

  file =fopen("input.txt","r"); ///file open in read mode
  for(int i = 0; i < k; i++)
  {
      fscanf(file,"%d", &Array[i]); ///assigning k nmbrs from file in Array[]
  }
   fclose(file);


   clock_t start = clock(); ///clock strt for sorting beginning
    for (int c = 0 ; c < ( k - 1 ); c++)
  {
    for (int d = 0 ; d < k - c - 1; d++)
    {
      if (Array[d] > Array[d+1]) /// From lower to higher sorting
      {
        temp       = Array[d];   /// Swaping
        Array[d]   = Array[d+1];
        Array[d+1] = temp;
      }
    }
  }
    clock_t End = clock();  ///clock end for sorting ending
   double duration = (double)(End-start)/(2500000000);   ///Processor 2.50GHz
   for(int i =0; i< k; i++)
   {
       cout << Array[i] << " "; ///just printing the sorted nmbrs
   }
   cout << endl;
   cout << "Execution time for bubble sort : " << duration << endl;
}
