#include<bits/stdc++.h>
using namespace std;

int main()
{
  FILE *file;
  int n;
  cout <<"Enter the value of n: ";
  cin >> n;
  int Array[n];
  srand(time(0));

  file = fopen("input.txt","r");
  for(int i = 0; i < n; i++)
  {
      fscanf(file,"%d", &Array[i]);
       printf("%d ", Array[i]);
  }
   fclose(file);

   clock_t start = clock();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k= 0; k < n; k++)
            {

                if(Array[i]+Array[j]+Array[k] == 0)
                   {
                       cout<< Array[i] << "," << Array[j]<<","<<Array[k]<< endl;
                   }
            }
        }
    }
    clock_t End = clock();
    cout << endl;

    double diff = (double)(End-start)/(2500000000);
    cout << "Execution time: " << diff << endl;

    return 0;
}
