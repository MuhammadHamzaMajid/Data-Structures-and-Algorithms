#pragma once
#include<iostream>
using namespace std;

const int N = 10;
int ids[N] = { 6, 13, 21, 28, 32, 44, 53, 67, 72, 80 };

int main(){
	int search = 80;
	int result = -1;

	//Linear Search

	int steps = 0;
	for (int i = 0; i < N; i++) {
		steps++;
		if (ids[i] == search) {
			result = search;
		}

	}

	if (result != -1)
	{
		cout << "Benne van, itt: " << result << endl;
	}
	else
	{
		cout << "Nincs benne" << endl;
	}
	cout << "Steps taken with linear search: " << steps << endl;



	result = -1;
	steps = 0;

	//Binary Search 


	int mid = ids[N / 2], mid_id = N / 2;


	for (int i = 0; i < 10; i++) {
		steps++;
		if (search == mid) {
			result = search;
			break;
		}
		if (search >= mid) {
			
			mid_id = mid_id + mid_id / 2;
			mid = ids[mid_id];
		}
		if (search < mid) {
			mid_id = mid_id - mid_id / 2;
			mid = ids[mid_id];
		}
	}
	if (result != -1)
	{
		cout << "Benne van, itt: " << result << endl;
	}
	else
	{
		cout << "Nincs benne" << endl;
	}
	cout << "Steps taken with binary search: " << steps << endl;
	return 0;
}