#include <iostream>
using namespace std;

const int N = 6;
int graph[N][N] = {
    { 0, 7, 9, 0, 0,14}, //0   
    { 7, 0,10,15, 0, 0}, //1   
    { 9,10, 0,11, 0, 2}, //2   
    { 0,15,11, 0, 6, 0}, //3   
    { 0, 0, 0, 6, 0, 9}, //4   
    {14, 0, 2, 0, 9, 0}  //5   
    //    0  1  2  3  4  5
};
int mins[N];
int path[N];
bool done[N];

void init();
void printEdges();
void printMins();
void printPath(int, int);
void dijkstra(int);

int main()
{
    init();
    printEdges();

    int start = 0; // Starting node
    int dest = 4;  // Destination node

    dijkstra(start);  // Run Dijkstra's algorithm from the start node

    printMins();
    printPath(start, dest);
}

void init()
{
    for (int i = 0; i < N; i++)
    {
        done[i] = false;
        mins[i] = 99999;
        path[i] = -1;
    }
}

void printEdges()
{
    cout << "Edges:" << endl;
    for (int i = 0; i < N; i++)
    {
        int count = 0;
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] != 0)
            {
                cout << "(" << i << ")--";
                cout << graph[i][j];
                cout << "--(" << j << ") , ";
                count++;
            }
        }
        if (count > 0) cout << endl;
    }
    cout << "------" << endl;
}

void printMins()
{
    cout << "Minimum distances from start:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "[" << i << "]:" << mins[i] << ", ";
    }
    cout << endl;
}

void printPath(int start, int dest)
{
    cout << "Shortest Path (" << start << " to " << dest << "):" << endl;

    if (mins[dest] == 99999)
    {
        cout << "No path exists." << endl;
        return;
    }

    int v = dest;
    while (v != start && v != -1)
    {
        cout << v << " <- ";
        v = path[v];
    }

    if (v != -1)
        cout << v << endl;
    else
        cout << "Path incomplete." << endl;
}

void dijkstra(int start)
{
    mins[start] = 0;

    for (int i = 0; i < N; i++)
    {
        // Find the vertex with the smallest known distance
        int u = -1;
        for (int j = 0; j < N; j++)
        {
            if (!done[j] && (u == -1 || mins[j] < mins[u]))
                u = j;
        }

        if (u == -1) break; // Remaining nodes are inaccessible

        done[u] = true;

        // Update neighbors
        for (int v = 0; v < N; v++)
        {
            if (graph[u][v] != 0 && !done[v])
            {
                int newDist = mins[u] + graph[u][v];
                if (newDist < mins[v])
                {
                    mins[v] = newDist;
                    path[v] = u;
                }
            }
        }
    }
}
