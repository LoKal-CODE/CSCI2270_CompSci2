#include <string>
#include <vector>

using namespace std;

// BFT

struct vertex
{
    string key;
    bool visited = false;
    int distance = 0; // distance from starting vertex, used in BFS
    vector<edge> adj;
};

struct edge
{
    int weight; // unused in BFT
    vertex* v;
};

/*

void bft(keyStart)
    1. Find key of starting vertex ("root")
    2. set vStart as "visited"
    3. create a queue ("q")
    4. enqueue vStart onto q
    5. loop until the queue is empty
        i. n = dequeue
        ii. print(n->key)
        iii. loop through n's adjacency list
            1) vertex* nb = n->adj[x].v
            2) if (!nb->visited)
                a) nb->visited = true
                b) enqueue onto q

*/