#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

// COMSC-210 | Lab 34: Network Graph | Erick Pascual-Bautista

const int SIZE = 10;

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;  // Creates alias 'Pair' for the pair<int,int> data type

class Graph {
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges) {
        // resize the vector to hold SIZE elements of type vector<Edge>
        adjList.resize(SIZE);

        // add edges to the directed graph
        for (auto &edge: edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            // insert at the end
            adjList[src].push_back(make_pair(dest, weight));
            // for an undirected graph, add an edge from dest to src also
            adjList[dest].push_back(make_pair(src, weight));
        }
    }

    // Print the graph's adjacency list
    void printGraph() {
        cout << "Elecrtic Power Grid Topolgy" << endl;
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Substation " << i;
            switch(i) {
                case 0: cout << " (Main Power Station)"; break;
                case 1: cout << " (Distribution Center)"; break;
                case 2: cout << " (Residential Area)"; break;
                case 3: cout << " (Comerical Hub)"; break;
                case 4: cout << " (Industrial Complex)"; break;
                case 5: cout << " (Renewable Energy Plant)"; break;
                case 6: cout << " (Backup Power Station)"; break;
                case 7: cout << " (Substation)"; break;
            }
            cout << " connects to: " << endl;
            for (Pair v : adjList[i])
                cout << "  → Substation " << v.first << " (Capacity: " << v.second << " MW)" << endl;
            cout << endl;
        }
    }
    
    // Depth First Search (DFS)
    void DFS(int start) {
        vector<bool> visited(SIZE, false);
        stack<int> stack;

        // Start from the given node
        stack.push(start);

        cout << "Network Trace (DFS) from Substation " << start;
        if (start == 0) cout << " (Main Power Station)";
        cout << ":\nPurpose: Tracing power flow paths through the grid\n=======================================" << endl;

        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();

            if (!visited[node]) {
                cout << "Inspecting Substation " << node;
                switch (node) {
                    case 0: cout << " (Main Power Station)"; break;
                    case 1: cout << " (Distribution Center)"; break;
                    case 2: cout << " (Residential Area)"; break;
                    case 3: cout << " (Commercial Hub)"; break;
                    case 4: cout << " (Industrial Complex)"; break;
                    case 5: cout << " (Renewable Energy Plant)"; break;
                    case 6: cout << " (Backup Power Station)"; break;
                    case 7: cout << " (Substation)"; break;
                }
                cout << endl;
                visited[node] = true;
            }

            // Get all adjacent vertices of the popped node
            for (auto &neighbor : adjList[node]) {
                if (!visited[neighbor.first]) {
                    cout << "  → Potential power flow to Substation " << neighbor.first;
                    switch (neighbor.first) {
                        case 1: cout << " (Distribution Center)"; break;
                        case 2: cout << " (Residential Area)"; break;
                        case 3: cout << " (Commercial Hub)"; break;
                        case 4: cout << " (Industrial Complex)"; break;
                        case 5: cout << " (Renewable Energy Plant)"; break;
                        case 6: cout << " (Backup Power Station)"; break;
                        case 7: cout << " (Substation)"; break;
                    }
                    cout << " - Capacity: " << neighbor.second << " MW" << endl;
                    stack.push(neighbor.first);
                }
            }
        }
        cout << endl;
    }

    // Breadth First Search (BFS)
    void BFS(int start) {
        vector<bool> visited(SIZE, false);
        queue<int> queue;

        // Start from the given node
        queue.push(start);
        visited[start] = true;

        cout << "Layer-by-Layer Network Inspection (BFS) from Substation " << start;
        if (start == 0) cout << " (Main Power Station)";
        cout << ":\nPurpose: Analyzing power distribution by distance from source\n=================================================" << endl;

        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            cout << "Checking Substation " << node;
            switch (node) {
                case 0: cout << " (Main Power Station)"; break;
                case 1: cout << " (Distribution Center)"; break;
                case 2: cout << " (Residential Area)"; break;
                case 3: cout << " (Commercial Hub)"; break;
                case 4: cout << " (Industrial Complex)"; break;
                case 5: cout << " (Renewable Energy Plant)"; break;
                case 6: cout << " (Backup Power Station)"; break;
                case 7: cout << " (Substation)"; break;
            }
            cout << endl;

            // Get all adjacent vertices of the dequeued node
            for (auto &neighbor : adjList[node]) {
                if (!visited[neighbor.first]) {
                    cout << "  → Next service area: Substation " << neighbor.first;
                    switch (neighbor.first) {
                        case 1: cout << " (Distribution Center)"; break;
                        case 2: cout << " (Residential Area)"; break;
                        case 3: cout << " (Commercial Hub)"; break;
                        case 4: cout << " (Industrial Complex)"; break;
                        case 5: cout << " (Renewable Energy Plant)"; break;
                        case 6: cout << " (Backup Power Station)"; break;
                        case 7: cout << " (Substation)"; break;
                    }
                    cout << " - Capacity: " << neighbor.second << " MW" << endl;
                    queue.push(neighbor.first);
                    visited[neighbor.first] = true;
                }
            }
        }
        cout << endl;
    }

    // Dijkstra's algorithm to find the shortest path from a given source
    void dijkstra(int start) {
        vector<int> dist(SIZE, INT_MAX);
        dist[start] = 0;
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            if (currentDist > dist[currentNode]) {
                continue;
            }

            for (auto &neighbor : adjList[currentNode]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                int newDist = currentDist + weight;

                if (newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    pq.push(make_pair(newDist, nextNode));
                }
            }
        }

        cout << "Shortest path from node " << start << ":" << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << start << " -> " << i << " : " << dist[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    // Creates a vector of graph edges/weights
    vector<Edge> edges = {
        // (x, y, w) —> edge from x to y having weight w
        {0,2,8},{0,3,21},{2,3,6},{5,6,6},{4,5,9},{2,4,4},{2,5,5},{1,7,10},{3,8,15},{6,9,20},{7,8,25},{8,9,30},{3,7,12}
    };

    // Creates graph
    Graph graph(edges);

    // Prints adjacency list representation of graph
    graph.printGraph();

    cout << endl;
    
    graph.DFS(0);
    graph.BFS(0);

    graph.dijkstra(0);

    return 0;
}

