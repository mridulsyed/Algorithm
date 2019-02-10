#include<bits/stdc++.h>
using namespace std;

int Max1;
int Min1;
int Comp = 0;

void LeafNodeOne(int Array[],int low, int high)
{
    int LeftMax;
    int LeftMin;

    if(low == high)
    {
        Max1 = Min1 = Array[low];
    }

    else{
        int Mid = (low+high)/2;
        LeafNodeOne(Array,low,Mid);
        LeftMax = Max1;
        LeftMin = Min1;

        LeafNodeOne(Array,Mid+1,high);

        if(LeftMax > Max1)
        {
            Max1 = LeftMax;
        }
        if(LeftMin < Min1)
        {
            Min1 = LeftMin;
        }
        Comp = Comp + 2;
    }
}
void BruteForce(int Array[], int n)
{
   int Max = Array[0];
    int Min = Array[0];

    for(int i = 1; i < n; i++)
    {
        if(Array[i] > Max)
        {
            Max = Array[i];
        }
        else if(Array[i] < Min)
        {
            Min = Array[i];
        }
    }
    int ans=(n-1)*2;
    cout <<"Maximum : " << Max << endl;
    cout <<"Minimum : " << Min<< endl;
    cout <<"Comparison: " << ans << endl;
}
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
   cout<<endl;

    cout <<"For Brute Force: " << endl;
    BruteForce(Array,n);
    cout<< endl;
    cout <<"For DAC(Leaf Node One}: " << endl;
    LeafNodeOne(Array,0,n-1);

    cout <<"Maximum : " << Max1 << endl;
    cout <<"Minimum : " << Min1<< endl;
    cout <<"Comparison: " << Comp << endl;
}






