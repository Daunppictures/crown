#include <iostream>
#include <math.h>
using namespace std;
#define SIZE 5

class Array {
private:
	int PrivateArr[SIZE];
public:
	friend void inputMatrix(Array Matrix[]);
	friend void coutMatrix(Array Matrix[]);
	friend void arithmetic_mean(Array* Matr);
	friend void sortArray(Array  arr[], int n);
	int operator [] (int i) {
		return PrivateArr[i];
	}
};

void sortArray(Array  arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int BlockSizeIter = 1; BlockSizeIter < n; BlockSizeIter *= 2)
		{
			for (int BlockIter = 0; BlockIter < n - BlockSizeIter; BlockIter += 2 * BlockSizeIter)
			{
				int LeftBlockIter = 0;
				int RightBlockIter = 0;
				int LeftBorder = BlockIter;
				int MidBorder = BlockIter + BlockSizeIter;
				int RightBorder = BlockIter + 2 * BlockSizeIter;
				RightBorder = (RightBorder < n) ? RightBorder : n;
				int* SortedBlock = new int[RightBorder - LeftBorder];

				while (LeftBorder + LeftBlockIter < MidBorder && MidBorder + RightBlockIter < RightBorder)
				{
					if (arr[i].PrivateArr[LeftBorder + LeftBlockIter] > arr[i].PrivateArr[MidBorder + RightBlockIter])
					{
						SortedBlock[LeftBlockIter + RightBlockIter] = arr[i].PrivateArr[LeftBorder + LeftBlockIter];
						LeftBlockIter++;
					}
					else
					{
						SortedBlock[LeftBlockIter + RightBlockIter] = arr[i].PrivateArr[MidBorder + RightBlockIter];
						RightBlockIter++;
					}
				}
				while (LeftBorder + LeftBlockIter < MidBorder)
				{
					SortedBlock[LeftBlockIter + RightBlockIter] = arr[i].PrivateArr[LeftBorder + LeftBlockIter];
					LeftBlockIter++;
				}
				while (MidBorder + RightBlockIter < RightBorder)
				{
					SortedBlock[LeftBlockIter + RightBlockIter] = arr[i].PrivateArr[MidBorder + RightBlockIter];
					RightBlockIter++;
				}

				for (int MergeIter = 0; MergeIter < LeftBlockIter + RightBlockIter; MergeIter++)
				{
					arr[i].PrivateArr[LeftBorder + MergeIter] = SortedBlock[MergeIter];
				}
				delete SortedBlock;

			}

		}
	}
}
void inputMatrix(Array Matrix[]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << "Enter array element ?" << j + 1 << endl;
			cin >> Matrix[i].PrivateArr[j];
		}
	}
}
void coutMatrix(Array Matrix[]) {
	for (int row = 0; row < SIZE; row++) {
		for (int column = 0; column < SIZE; column++) {
			cout << Matrix[row].PrivateArr[column] << "     ";
		}
		cout << "\n\n";
	}
}

void arithmetic_mean(Array* Matr) {
	int number = 5;
	float result = 0;
	float string[5] = { 1,1,1,1,1 };
	for (int k = 1; k < number; k++)
	{
		for (int l = 0; l < k; l++)
		{
			string[l] *= Matr[k][l];
		}
	}
	for (int i = 0; i < number - 1; i++)
	{
		result += string[i];
		cout << "f[" << i << "]=" << string[i] << endl;
	}
	number--;
	result /= number;
	cout << "F(arithmetic_mean)= " << result << endl;
}


int main() {
	Array Matrix[SIZE];
	inputMatrix(Matrix);
	coutMatrix(Matrix);
	cout << "\n\n\n";

	sortArray(Matrix, SIZE);

	coutMatrix(Matrix);
	cout << "\t\tOutput product_of_elements" << endl;
	arithmetic_mean(Matrix);
	return 0;
}