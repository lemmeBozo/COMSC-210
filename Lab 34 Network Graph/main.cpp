#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

// COMSC-210 | Lab 34: Network Graph | Erick Pascual-Bautista

const int SIZE = 10;

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;  // Creates alias 'Pair' for the pair<int,int> data type

class Graph {
protected:
    vector<vector<Pair>> adjList;

public:
    Graph(vector<Edge> const &edges) {
        adjList.resize(SIZE);

        for (auto &edge : edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            adjList[src].push_back(make_pair(dest, weight));
            adjList[dest].push_back(make_pair(src, weight));
        }
    }

    virtual void printGraph() {
        cout << "Graph's adjacency list:" << endl;
        for (int i = 0; i < adjList.size(); i++) {
        cout << i << " --> ";
        for (Pair v : adjList[i])
        cout << "(" << v.first << ", " << v.second << ") ";
        cout << endl;
        }
    }

    // DFS that returns traversal data instead of printing
    vector<int> DFS(int start) {
        vector<bool> visited(SIZE, false);
        stack<int> stack;
        vector<int> traversal; // Store visited nodes

        stack.push(start);
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();

            if (!visited[node]) {
                traversal.push_back(node);
                visited[node] = true;
            }

            for (auto &neighbor : adjList[node]) {
                if (!visited[neighbor.first]) {
                    stack.push(neighbor.first);
                }
            }
        }

        return traversal;
    }

    // BFS that returns traversal data instead of printing
    vector<int> BFS(int start) {
        vector<bool> visited(SIZE, false);
        queue<int> queue;
        vector<int> traversal;

        queue.push(start);
        visited[start] = true;

        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            traversal.push_back(node);

            for (auto &neighbor : adjList[node]) {
                if (!visited[neighbor.first]) {
                    queue.push(neighbor.first);
                    visited[neighbor.first] = true;
                }
            }
        }

        return traversal;
    }

    vector<int> dijkstra(int start) {
        vector<int> dist(SIZE, INT_MAX);
        dist[start] = 0;

        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            if (currentDist > dist[currentNode]) continue;

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
        return dist; // Return distance vector
    }

    // Kruskal: Returns the edges in the MST
    vector<Edge> kruskalMST() {
        vector<Edge> result; // Stores MST edges
        vector<Edge> allEdges;

        for (int i = 0; i < SIZE; i++) {
            for (auto &neighbor : adjList[i]) {
                if (i < neighbor.first) { // Avoid duplicate edges
                    allEdges.push_back({i, neighbor.first, neighbor.second});
                }
            }
        }

        sort(allEdges.begin(), allEdges.end(), [](Edge &a, Edge &b) {
            return a.weight < b.weight;
        });

        vector<int> parent(SIZE);
        for (int i = 0; i < SIZE; i++) parent[i] = i;

        function<int(int)> find = [&](int i) {
            if (parent[i] != i) parent[i] = find(parent[i]);
            return parent[i];
        };

        auto unite = [&](int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            parent[rootU] = rootV;
        };

        for (auto &edge : allEdges) {
            int rootU = find(edge.src);
            int rootV = find(edge.dest);

            if (rootU != rootV) {
                result.push_back(edge);
                unite(rootU, rootV);
            }
        }

        return result; // Return MST edges
    }
        // General-purpose print methods
    virtual void printDFS(int start) {
        auto traversal = DFS(start);
        cout << "DFS Traversal starting from node " << start << ":\n";
        for (int node : traversal) {
            cout << node << " ";
        }
        cout << endl << endl;
    }

    virtual void printBFS(int start) {
        auto traversal = BFS(start);
        cout << "BFS Traversal starting from node " << start << ":\n";
        for (int node : traversal) {
            cout << node << " ";
        }
        cout << endl << endl;
    }

    virtual void printDijkstra(int start) {
        auto dist = dijkstra(start);
        cout << "Dijkstra's Shortest Paths from node " << start << ":\n";
        for (int i = 0; i < dist.size(); i++) {
            cout << "Node " << start << " → Node " << i
                 << " : " << (dist[i] == INT_MAX ? "Unreachable" : to_string(dist[i])) << endl;
        }
        cout << endl;
    }

    virtual void printKruskalMST() {
        auto mst = kruskalMST();
        cout << "Minimum Spanning Tree edges:\n";
        for (auto &edge : mst) {
            cout << "Edge from " << edge.src << " to " << edge.dest
                << " with capacity: " << edge.weight << " units\n";
        }
        cout << endl;
    }

};

// Custom graph class derived from graph
class PowerGridGraph : public Graph {
private:
    vector<string> substationNames;

public:
    PowerGridGraph(vector<Edge> const &edges, vector<string> names)
        : Graph(edges), substationNames(names) {}

    void printGraph() override {
        cout << "Power Grid Network Topology:\n================================\n";
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Substation " << i << " (" << substationNames[i] << ") connects to:\n";
            for (Pair v : adjList[i]) {
                cout << "  → Substation " << v.first << " (" << substationNames[v.first]
                     << ") - Capacity: " << v.second << " MW\n";
            }
        }
        cout << endl;
    }

    void printDFS(int start) override {
        cout << "Network Trace (DFS) from Substation " << start << " (" << substationNames[start] << "):\n";
        cout << "Purpose: Tracing possible power flow paths through the grid\n";
        cout << "=======================================\n";
        auto traversal = DFS(start);
        for (int node : traversal) {
            cout << "Inspecting Substation " << node << " (" << substationNames[node] << ")\n";
            for (auto &neighbor : adjList[node]) {
                cout << "  → Potential power flow to Substation " << neighbor.first << " ("
                     << substationNames[neighbor.first] << ") - Capacity: " << neighbor.second << " MW\n";
            }
        }
        cout << endl;
    }

    void printBFS(int start) override {
        cout << "Layer-by-Layer Network Inspection (BFS) from Substation " << start
             << " (" << substationNames[start] << "):\n";
        cout << "Purpose: Analyzing power distribution by distance from source\n";
        cout << "=================================================\n";
        auto traversal = BFS(start);
        for (int node : traversal) {
            cout << "Checking Substation " << node << " (" << substationNames[node] << ")\n";
            for (auto &neighbor : adjList[node]) {
                cout << "  → Next distribution area: Substation " << neighbor.first << " ("
                     << substationNames[neighbor.first] << ") - Capacity: " << neighbor.second << " MW\n";
            }
        }
        cout << endl;
    }

    void printDijkstra(int start) override {
        auto dist = dijkstra(start);
        cout << "Shortest Power Distribution Paths from Substation " << start << " ("
             << substationNames[start] << "):\n";
        for (int i = 0; i < dist.size(); i++) {
            cout << "Substation " << start << " → Substation " << i
                 << " (" << substationNames[i] << ") : "
                 << (dist[i] == INT_MAX ? "Unreachable" : to_string(dist[i]) + " MW") << endl;
        }
        cout << endl;
    }

    void printKruskalMST() override {
        auto mst = kruskalMST();
        cout << "Minimum Spanning Tree of the Power Grid:\n";
        for (auto &edge : mst) {
            cout << "Transmission Line from Substation " << edge.src << " (" << substationNames[edge.src]
                 << ") to Substation " << edge.dest << " (" << substationNames[edge.dest]
                 << ") with capacity: " << edge.weight << " MW\n";
        }
        cout << endl;
    }
};

void displayMenu(PowerGridGraph&);

int main() {
    // Creates a vector of graph edges/weights
    vector<Edge> edges = {
        // (x, y, w) —> edge from x to y having weight w
        {0,2,8},{0,3,21},{2,3,6},{5,6,6},{4,5,9},{2,4,4},{2,5,5},{1,7,10},{3,8,15},{6,9,20},{7,8,25},{8,9,30},{3,7,12}
    };

    // Creates vector of names
    vector<string> names = {
        "Main Power Plant",      // Node 0
        "Substation Alpha",      // Node 1
        "Substation Beta",       // Node 2
        "Switchyard Gamma",      // Node 3
        "Transformer Delta",     // Node 4
        "Control Station Epsilon", // Node 5
        "Relay Station Zeta",    // Node 6
        "Substation Eta",        // Node 7
        "Backup Station Theta",  // Node 8
        "Regional Hub Iota"      // Node 9
    };

    PowerGridGraph grid(edges, names);
    displayMenu(grid);

    return 0;
}

void displayMenu(PowerGridGraph &grid) {
    int choice;
    do {
        cout << "Power Grid Network Menu:\n";
        cout << "[1] Display power distribution network\n";
        cout << "[2] Analyze power distribution (BFS)\n";
        cout << "[3] Plan inspection route (DFS)\n";
        cout << "[4] Calculate shortest distribution paths\n";
        cout << "[5] Find Minimum Spanning Tree\n";
        cout << "[0] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                grid.printGraph();
                break;
            case 2:
                grid.printBFS(0);  // Start BFS from the main power plant
                break;
            case 3:
                grid.printDFS(0);  // Start DFS from the main power plant
                break;
            case 4:
                grid.printDijkstra(0);  // Start Dijkstra from the main power plant
                break;
            case 5:
                grid.printKruskalMST();  // Print Minimum Spanning Tree
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        cout << endl;
    } while (choice != 0);
}