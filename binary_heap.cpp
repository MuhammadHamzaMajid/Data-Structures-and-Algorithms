/*#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

int N = 14;
int heap[100];

void heapRestore(int);
void heapDel();
void heapBuild();
void generateNumbers();
void printHeap();

int main()
{
    generateNumbers();
    printHeap();

    heapBuild();
    printHeap();

    cout << "Heap Sort:" << endl;
    while(N > 0)
    {
        cout << heap[0] << " ";
        heapDel();
    }
}

void heapRestore(int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && heap[left] > heap[largest])
        largest = left;
    if (right < N && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapRestore(largest);  // Recursively restore heap property
    }
}
void heapDel()
{
    if (N <= 0) return;

    heap[0] = heap[N - 1];  // Move last element to root
    N--;                    // Reduce heap size
    heapRestore(0);          // Restore heap property
}
void heapBuild()
{
    for (int i = N - 1; i >= 0; i--)
    {
        heapRestore(i);
    }
}

void generateNumbers()
{
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        heap[i] = rand() % 90 + 10;
    }
}
void printHeap()
{
    if (N > 0)
    {
        cout << "Elements of Heap:" << endl;

        int sep = 0;
        int block = 1;

        for (int i = 0; i < N; i++)
        {
            cout << heap[i] << " ";
            if (i == sep)
            {
                block *= 2;
                sep += block;
                cout << "| ";
            }
            else
                if (i % 2 == 0) cout << ", ";
        }
        cout << endl;
    }
    else cout << "Heap is empty" << endl;
}*/