#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Graphs

// Undirected & Weighted

struct edge
{
    vertex* v;
    int weight;
};

struct vertex
{
    string key;
    vector<edge> adj;
};

class Graph
{
private:
    vector<vertex*> verticies;
    
public:
    Graph(/* args */);
    ~Graph();
    void insertVertex(string n);
    void addEdge(string v1, string v2, int weight);
};

Graph::Graph(/* args */)
{
}

Graph::~Graph()
{
}

void Graph::insertVertex(string n)
{
    // search: is the key n already here
    bool found = false;
    for (int i = 0; i < verticies.size(); i++)
    {
        if (verticies[i]->key == n)
        {
            found = true;
        }
        
    }
    
    // Create the vertex, no edges yet
    if (!found)
    {
        vertex* v = new vertex;
        v->key = n;
        verticies.push_back(v); // add the pointer to the list
    }
}

void Graph::addEdge(string v1, string v2, int weight) // O(V^2) and no duplicate checks... a little limited
{
    for (int i = 0; i < verticies.size(); i++)
    {
        if (verticies[i]->key == v1)
        {
            for (int j = 0; j < verticies.size(); j++)
            {
                if (verticies[j]->key == v2 && i != j)
                {
                    edge e0;
                    e0.v = verticies[j];
                    e0.weight = weight;
                    verticies[i]->adj.push_back(e0);
                    
                    // add the edge in the other direction as well
                    edge e1;
                    e1.v = verticies[i];
                    e1.weight = weight;
                    verticies[j]->adj.push_back(e1);
                }
            }
        }
    }
}