/*#include <iostream>
using namespace std;

// STACK 
const int sN = 10;
int stack[sN];
int sCount = 0;

// Push operation
bool sPush(int value) {
    if (sCount < sN) {//checking if stack is full or not
        stack[sCount] = value;
        sCount++;
        return true;
    }
    return false;
}

// Pop operation
int sPop() {
    if (sCount > 0) {
        --sCount;
        return stack[sCount];
    }
    return -1;
}

// QUEUE
const int qN = 11;// 10+1
int queue[qN];
int qBegin = 0, qEnd = 0;

// Add operation (enqueue)
bool qAdd(int value) {
    if ((qEnd + 1) % qN != qBegin) { // Checking if queue is full or not
        queue[qEnd] = value;
        qEnd = (qEnd + 1) % qN;
        return true;
    }
    return false;
}

// Get operation (dequeue)
int qGet() {
    if (qBegin != qEnd) { // Check if queue is not empty
        int value = queue[qBegin];
        qBegin = (qBegin + 1) % qN;
        return value;
    }
    return -1;
}

// Program 
int main() {
    // STACK 
    cout << "The operation of stack storage:" << endl;
    // Output: 1 1 1
    cout << sPush(10) << " ";
    cout << sPush(15) << " ";
    cout << sPush(21) << endl;

    // Output: 21 15
    cout << sPop() << " ";
    cout << sPop() << endl;

    // Output: 1 1 1 1 1 1 1 1 1 0 0
    cout << sPush(9) << " ";
    cout << sPush(8) << " ";
    cout << sPush(7) << " ";
    cout << sPush(6) << " ";
    cout << sPush(5) << " ";
    cout << sPush(4) << " ";
    cout << sPush(3) << " ";
    cout << sPush(2) << " ";
    cout << sPush(1) << " ";
    cout << sPush(11) << " ";
    cout << sPush(12) << endl;

    // Output: 1 2 3 4 5 6 7 8 9 10 -1 -1
    cout << sPop() << " ";
    cout << sPop() << " ";
    cout << sPop() << " ";
    cout << sPop() << " ";
    cout << sPop() << " ";
    cout << sPop() << " ";
    cout << sPop() << " ";
    cout << sPop() << " ";
    cout << sPop() << " ";
    cout << sPop() << " ";
    cout << sPop() << " ";
    cout << sPop() << endl;

    //QUEUE
    cout << "\n\nThe operation of queue storage:" << endl;
    // Output: 1 1 1
    cout << qAdd(10) << " ";
    cout << qAdd(20) << " ";
    cout << qAdd(30) << endl;

    // Output: 10 20 30
    cout << qGet() << " ";
    cout << qGet() << " ";
    cout << qGet() << endl;

    // Output: 1 1 1 1 1 1 1 1 1 1 0 0
    cout << qAdd(1) << " ";
    cout << qAdd(2) << " ";
    cout << qAdd(3) << " ";
    cout << qAdd(4) << " ";
    cout << qAdd(5) << " ";
    cout << qAdd(6) << " ";
    cout << qAdd(7) << " ";
    cout << qAdd(8) << " ";
    cout << qAdd(9) << " ";
    cout << qAdd(10) << " ";
    cout << qAdd(11) << " ";
    cout << qAdd(12) << endl;

    // Output: 1 2 3 4 5 6 7 8 9 10 -1 -1
    cout << qGet() << " ";
    cout << qGet() << " ";
    cout << qGet() << " ";
    cout << qGet() << " ";
    cout << qGet() << " ";
    cout << qGet() << " ";
    cout << qGet() << " ";
    cout << qGet() << " ";
    cout << qGet() << " ";
    cout << qGet() << " ";
    cout << qGet() << " ";
    cout << qGet() << endl;
}
*/