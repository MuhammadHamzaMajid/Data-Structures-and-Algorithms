#include <iostream>
#include <limits.h> // For INT_MAX
using namespace std;

const int N = 9;
int graph[N][N] = {
    {0, 4, 0, 0, 0, 0, 0, 8, 0}, // 0   
    {4, 0, 8, 0, 0, 0, 0,11, 0}, // 1
    {0, 8, 0, 7, 0, 4, 0, 0, 2}, // 2
    {0, 0, 7, 0, 9,14, 0, 0, 0}, // 3
    {0, 0, 0, 9, 0,10, 0, 0, 0}, // 4
    {0, 0, 4,14,10, 0, 2, 0, 0}, // 5
    {0, 0, 0, 0, 0, 2, 0, 1, 6}, // 6
    {8,11, 0, 0, 0, 0, 1, 0, 7}, // 7
    {0, 0, 2, 0, 0, 0, 6, 7, 0}  // 8
 //  0  1  2  3  4  5  6  7  8
};
int sTree[N][N];
bool check[N];

void init();
void printEdges(int[][N], bool);
void prim(); // Prim's algorithm function
int minKey(int[], bool[]);

int main()
{
    init();
    printEdges(graph, false);

    // Run Prim's algorithm to build the MST
    prim();

    printEdges(sTree, true);
}

void init()
{
    for (int i = 0; i < N; i++)
    {
        check[i] = false;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sTree[i][j] = 0;
        }
    }
}

void printEdges(int matrix[][N], bool isResult)
{
    int edges = 0;
    int weight = 0;
    cout << (isResult ? "Tree:" : "Graph:") << endl;
    for (int i = 0; i < N; i++)
    {
        int count = 0;
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] != 0 && matrix[i][j] == matrix[j][i])
            {
                cout << "(" << i << ")--";
                cout << matrix[i][j];
                cout << "--(" << j << ") , ";
                count++;
                edges++;
                weight += matrix[i][j];
            }
        }
        if (count > 0) cout << endl;
    }
    edges /= 2;
    weight /= 2;
    cout << "Edges: " << edges << endl;
    if (isResult) cout << "Weight: " << weight << endl;
    cout << "------" << endl;
}

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < N; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void prim()
{
    int parent[N]; // Array to store constructed MST
    int key[N];    // Key values used to pick minimum weight edge
    bool mstSet[N]; // To represent set of vertices included in MST

    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;     // Start from the first node
    parent[0] = -1; // First node is root

    for (int count = 0; count < N - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < N; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Fill the sTree matrix using parent[]
    for (int i = 1; i < N; i++)
    {
        int u = parent[i];
        int v = i;
        int w = graph[u][v];
        sTree[u][v] = w;
        sTree[v][u] = w;
    }
}
