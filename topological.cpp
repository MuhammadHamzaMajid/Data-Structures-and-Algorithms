#include <iostream>
#include <queue>
using namespace std;

const int N = 9;
string items[N] = { "shoes", "underwear", "shirt", "socks", "jacket", "tie", "belt", "vest", "pants" };
int tasks[N][N] = {
    {0, 0, 0, 0, 0, 0, 1, 0, 0}, // shoes
    {0, 0, 0, 0, 0, 0, 0, 0, 1}, // underwear
    {0, 0, 0, 0, 0, 1, 1, 1, 0}, // shirt
    {1, 0, 0, 0, 0, 0, 0, 0, 0}, // socks
    {0, 0, 0, 0, 0, 0, 0, 0, 0}, // jacket
    {0, 0, 0, 0, 0, 0, 0, 1, 0}, // tie
    {0, 0, 0, 0, 0, 0, 0, 0, 0}, // belt
    {0, 0, 0, 0, 1, 0, 0, 0, 0}, // vest
    {1, 0, 0, 0, 0, 0, 1, 0, 0}  // pants
};
int inDegree[N] = { 0 }; // Array to track incoming edges
queue<int> q;

void calculateInDegree();
void topologicalSort();
void printEdges();
void printSchedule();

int schedule[N];
int sX = 0;

int main()
{
    printEdges();
    calculateInDegree();
    topologicalSort();
    printSchedule();
}

void calculateInDegree() {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (tasks[i][j] != 0) {
                inDegree[j]++;
            }
        }
    }
}

void topologicalSort() {
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        schedule[sX++] = current;

        for (int j = 0; j < N; j++) {
            if (tasks[current][j] != 0) {
                inDegree[j]--;
                if (inDegree[j] == 0) {
                    q.push(j);
                }
            }
        }
    }
}

void printEdges() {
    cout << "Edges:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tasks[i][j] == 1) {
                cout << items[i] << " -> " << items[j] << ", ";
            }
        }
        cout << endl;
    }
    cout << "------" << endl;
}

void printSchedule() {
    cout << "Schedule:" << endl;
    for (int i = 0; i < sX; i++) {
        cout << items[schedule[i]] << ", ";
    }
    cout << endl;
}
