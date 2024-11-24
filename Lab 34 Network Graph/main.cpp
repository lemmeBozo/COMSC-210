#include <iostream>
#include <vector>

// Data structures needed for DFS & BFS
#include <stack>
#include <queue>

using namespace std;

// COMSC-210 | Lab 34: Network Graph | Erick Pascual-Bautista

const int SIZE = 7;

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
        cout << "Graph's adjacency list:" << endl;
        for (int i = 0; i < adjList.size(); i++) {
            cout << i << " --> ";
            for (Pair v : adjList[i])
                cout << "(" << v.first << ", " << v.second << ") ";
            cout << endl;
        }
    }
    
    // Depth First Search (DFS)
    void DFS(int start) {
        vector<bool> visited(SIZE, false); 
        stack<int> stack;

        // Start from the given node
        stack.push(start);

        cout << "DFS starting from vertex " << start << ":" << endl;

        while(!stack.empty()) {
            int node = stack.top();
            stack.pop();
        
            if(!visited[node]) {
                cout << node << " ";
                visited[node] = true;
            }

            // Gets all adjacent vertices of the popped node 
            for (auto& neighbor : adjList[node]) {
                if (!visited[neighbor.first]) {
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

        // Starting from the given node
        queue.push(start);
        visited[start] = true;

        cout << "BFS starting from vertex " << start << ":" << endl;

        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            cout << node << " ";

            // Get all adjacent vertices of the dequeued node
            for (auto& neighbor : adjList[node]) {
                if (!visited[neighbor.first]) {
                    queue.push(neighbor.first);
                    visited[neighbor.first] = true;
                }
            }

        }
        cout << endl;
    }
};

int main() {
    // Creates a vector of graph edges/weights
    vector<Edge> edges = {
        // (x, y, w) —> edge from x to y having weight w
        {0,1,12},{0,2,8},{0,3,21},{2,3,6},{2,6,2},{5,6,6},{4,5,9},{2,4,4},{2,5,5}
    };

    // Creates graph
    Graph graph(edges);

    // Prints adjacency list representation of graph
    graph.printGraph();

    cout << endl << endl;
    
    graph.DFS(0);
    graph.BFS(0);

    return 0;
}

