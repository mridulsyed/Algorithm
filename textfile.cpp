#include<bits/stdc++.h>
using namespace std;

int main(){
  ofstream fp;
  fp.open("input.txt");
  FILE *file;
  int i;   /// for iteration
  int n;   /// n nmbr is generated in file to take k nmbr for sorting from this n
  cout <<"Enter the value of n: ";
  cin >> n;
  int Array[n];
  srand(time(0));  ///for generating actual random

  for(i = 0; i < n; i++)
  {
      fp<< (rand()%9999-5000) << endl;  ///for generating randoms between a range
  }
 fp.close();

  file = fopen("input.txt","r"); ///file open in raed mode
  for(int i = 0; i < n; i++)
  {
      fscanf(file,"%d", &Array[i]); ///picking nmbrs from file
      printf("%d ", Array[i]);
  }
   fclose(file);
}
