#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int start;
    int nVert, nEdges;
    int a, b;

    ifstream infile("graph.txt");
    infile >> nVert >> nEdges;
    vector<vector<int>> graph(nVert);

    for (int i = 0; i < nEdges; i++)
    {
        infile >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    infile >> start;
    infile.close();

    vector<int> dist(nVert, -1);
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int adj : graph[curr]) 
        {
            if (dist[adj] == -1)
            {
                dist[adj] = dist[curr] + 1;
                q.push(adj);
            }
        }
    }

    for (int i = 0; i < nVert; i++)
    {
        cout << dist[i] << endl;
    }
}

