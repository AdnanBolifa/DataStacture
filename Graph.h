#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_VERTICES = 100; // Adjust the maximum number of vertices as needed

// Graph class
class Graph {
private:
    int adjList[MAX_VERTICES][MAX_VERTICES] = { 0 };

public:
    void addEdge(int src, int dest) {
        adjList[src][dest] = 1;
    }

    void printGraph() {
        for (int i = 0; i < MAX_VERTICES; i++) {
            bool hasEdges = false;
            for (int j = 0; j < MAX_VERTICES; j++) {
                if (adjList[i][j] == 1) {
                    hasEdges = true;
                    break;
                }
            }
            if (!hasEdges)
                continue;

            cout << i << " -> ";
            for (int j = 0; j < MAX_VERTICES; j++) {
                if (adjList[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }



// Function to read edges and vertices from a text file and add them to a graph
void readGraphFromFile(const string& filename, Graph& graph) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        int src, dest;
        if (!(iss >> src >> dest)) {
            cerr << "Error reading edge: " << line << endl;
            continue;
        }

        graph.addEdge(src, dest);
    }

    inputFile.close();
}

void GraphMain() {
    Graph graph;
    string filename = "graph.txt";

    readGraphFromFile(filename, graph);

    graph.printGraph();

}
};