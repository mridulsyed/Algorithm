#include<bits/stdc++.h>
using namespace std;
int a[30],flag=0;
int place(int pos)
{    int i;
     for(i=1;i<pos;i++)
     {      if((a[i]==a[pos]) || ((abs(a[i]-a[pos])==abs(i-pos))))
               return 0;
     }
     return 1;
}
void print_sol(int n)
{     int i,j;
     flag++;
     cout<<"\n\nSolution "<<flag<<" : \n";
     for(i=1;i<=n;i++)
     {    for(j=1;j<=n;j++)
          {
               if(a[i]==j)
                printf("1\t");
               else
                printf("0\t");
          }
          printf("\n");
     }
}
void queen(int n)
{
     int k=1;
     a[k]=0;
     while(k!=0)
     {
          do
          {
            a[k]++;
          } while((a[k]<=n)&& place(k)==0);
          if(a[k]<=n)
          {
               if(k==n)
                {
                    print_sol(n);
                    cout<<endl;
                     cout<<"The a[] is : ";
                for(int i=1;i<=n;i++)
                   cout<<a[i]<<" ";

                    cout<<endl;
                }
               else
               {
                k++;
                a[k]=0;
               }
          }
          else
          {
                k--;
          }
     }
}
int main ()
{     int n;
     cout<<"Enter the number of Queens : ";
     cin>>n;
     queen(n);
     cout<<"\nTotal solutions = "<<flag<<endl;
}

