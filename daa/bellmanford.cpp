#include <bits/stdc++.h>
using namespace std;

void BellmanFord(int V, int E, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Negative cycle detected" << endl;
            return;
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "INF ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    BellmanFord(V, E, edges, src);
    return 0;
}
