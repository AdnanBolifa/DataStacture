#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Queue.h"


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


    void shortestPath(int src, int dest) {
        MyQueue q;
        int distance[MAX_VERTICES];
        int parent[MAX_VERTICES];

        fill(distance, distance + MAX_VERTICES, INT_MAX);
        fill(parent, parent + MAX_VERTICES, -1);

        q.push(src);
        distance[src] = 0;

        while (!q.isEmpty()) {
            int current = q.front();
            q.pop();

            for (int i = 0; i < MAX_VERTICES; i++) {
                if (adjList[current][i] == 1 && distance[i] == INT_MAX) {
                    q.push(i);
                    distance[i] = distance[current] + 1;
                    parent[i] = current;

                    if (i == dest)
                        break;
                }
            }
        }

        if (parent[dest] == -1) {
            cout << "There is no path from " << src << " to " << dest << endl;
            return;
        }

        cout << "Shortest path from " << src << " to " << dest << ": ";
        int path[MAX_VERTICES];
        int pathLength = 0;
        int current = dest;

        while (current != -1) {
            path[pathLength++] = current;
            current = parent[current];
        }

        for (int i = pathLength - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0)
                cout << " -> ";
        }
        cout << endl;
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

    void GraphMain(int src, int dest) {
        Graph graph;
        string filename = "graph.txt";

        readGraphFromFile(filename, graph);

        graph.printGraph();
        graph.shortestPath(src, dest);

    }
};
