#include<bits/stdc++.h>
using namespace std;

int Max1;
int Min1;
int Comp = 0;

void LeafNodeTwo(int Array[],int low, int high)
{
    int LeftMax;
    int LeftMin;

    if(low == high)
    {
        Max1 = Min1 = Array[low];
    }
     else
    {
        if(high == low+1)
        {
            if(Array[low] > Array[high]){
                Max1 = Array[low];
                Min1 = Array[high];
            }
            else
            {
               Max1 = Array[high];
                Min1 = Array[low]; }
                Comp ++;
        }

        else{
        int Mid = (low+high)/2;
        LeafNodeTwo(Array,low,Mid);
        LeftMax = Max1;
        LeftMin = Min1;
        LeafNodeTwo(Array,Mid+1,high);

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
     int ans = (n-1)*2;
    cout <<"Maximum : " << Max << endl;
    cout <<"Minimum : " << Min<< endl;
    cout <<"Comparison: " << ans << endl;
}
int main()
{
    FILE *file;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int Array[n];

    file = fopen("Input.txt", "r");
    for(int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &Array[i]);
        printf("%d ", Array[i]);
    }
    fclose(file);
    cout<<endl;
    cout <<"For Brute Force: " << endl;
    BruteForce(Array,n);
    cout<< endl;
    cout <<"For DAC(Leaf Node Two): " << endl;
    LeafNodeTwo(Array,0,n-1);

    cout <<"Maximum : " << Max1 << endl;
    cout <<"Minimum : " << Min1<< endl;
    cout <<"Comparison: " << Comp << endl;
}






