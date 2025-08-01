#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//first, we declare the global variables
const int M = 100;
const int N = 15;
int numbers[N];
int result[N];

void generateNumbers();
void printNumbers(int[]);
void countingSort();

int main()
{
    generateNumbers();

    cout << "Before sorting using counting sort: ";
    printNumbers(numbers);

    countingSort();
    cout << "After sorting using counting sort: ";
    printNumbers(result);
}

void generateNumbers()
{
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        numbers[i] = rand() % (M - 1) + 1;
    }
}
void printNumbers(int array[])
{
    for (int i = 0; i < N; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void countingSort()
{
    int count[M] = { 0 }; 

    for (int i = 0; i < N; i++)
    {
        count[numbers[i]]++;
    }

    // Calculate cumulative counts
    for (int i = 1; i < M; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the sorted output array
    for (int i = N - 1; i >= 0; i--)
    {
        result[count[numbers[i]] - 1] = numbers[i];
        count[numbers[i]]--;
    }
}