#include <iostream>
using namespace std;

int getInvCount(int arr[])
{
	int inv_count = 0;
	for (int i = 0; i < 9 - 1; i++)
		for (int j = i+1; j < 9; j++)
			// Value 0 is used for empty space
			if (arr[j] && arr[i] && arr[i] > arr[j])
				inv_count++;
	return inv_count;
}

bool isSolvable(int puzzle[3][3])
{
	int invCount = getInvCount((int *)puzzle);
	cout<<invCount<<"gjhygjh"<<endl;

	return (invCount%2 == 0);
}

int main(int argv, int** args)
{
int puzzle[3][3] = {{1, 8, 2},
					{0, 4, 3},
					{7, 6, 5}};
isSolvable(puzzle)? cout << "Solvable":
					cout << "Not Solvable";
return 0;
}
