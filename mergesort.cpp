/*#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<vector>
using namespace std;

const int N = 15;
int numbers[N];

void generateNumbers(bool);
void printNumbers();
void mergeSort(int bottom, int top);
void merge(int bottom, int middle, int top);

int main()
{
	generateNumbers(false);
	cout << "Before sorting using merge sort: ";
	printNumbers();

	// Merge Sort
	mergeSort(0, N - 1);
	cout << "After sorting using merge sort: ";
	printNumbers();
}

// Merge Sort Implementation
void mergeSort(int bottom, int top)
{
	if (bottom < top)
	{
		int middle = bottom + (top - bottom) / 2;

		// Recursively sort the left and right halves
		mergeSort(bottom, middle);
		mergeSort(middle + 1, top);

		// Merge the sorted halves
		merge(bottom, middle, top);
	}
}

// Merge function to combine two sorted halves
void merge(int bottom, int middle, int top)
{
	int leftSize = middle - bottom + 1;
	int rightSize = top - middle;

	// Temporary arrays
	vector<int> left(leftSize), right(rightSize);

	// Copy data to temp arrays
	for (int i = 0; i < leftSize; i++)
		left[i] = numbers[bottom + i];
	for (int i = 0; i < rightSize; i++)
		right[i] = numbers[middle + 1 + i];

	// Merge back into original array
	int i = 0, j = 0, k = bottom;
	while (i < leftSize && j < rightSize)
	{
		if (left[i] <= right[j])
			numbers[k++] = left[i++];
		else
			numbers[k++] = right[j++];
	}

	// Copy remaining elements
	while (i < leftSize)
		numbers[k++] = left[i++];
	while (j < rightSize)
		numbers[k++] = right[j++];
}

void generateNumbers(bool twoHalf)
{
	srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		if (twoHalf)
		{
			int mid = (N - 1) / 2 + 1;
			if (i == 0 || i == mid)
			{
				numbers[i] = rand() % 12 + 1;
			}
			else
			{
				numbers[i] = numbers[i - 1] + rand() % 12 + 1;
			}
		}
		else
		{
			numbers[i] = rand() % 99 + 1;
		}
	}
}

void printNumbers()
{
	for (int i = 0; i < N; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
}
*/