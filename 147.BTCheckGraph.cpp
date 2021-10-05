// Approach : We create a graph using an adjacency list which has all the vertices connected to each vertex stores in it. We also have a
// visited array which keeps track if a node is already visited or not. We have a parent array which stores the value of parent of an 
// which is -1 if no parent is found. We start bfs traversal from node 0, then for each node connected to it we check if that node is 
// already visited if it is visited and if the current node is not the parent of the connected node(they do not form an edge). Then a 
// cycle is detected. If the node is not visited then we make the current node the parent of the connected node and push it to the queue.
// If it is already visited and is the parent of current node then we do nothing. When all connected nodes of a node are checked we pop 
// the current node from the queue and perform the above check for the next element. When the queue becomes empty then we check if all
// the elements are visited using the visisted array and return accordingly.
#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Graph {
public:
	int vertices;
	list<int>* adj;
	int* visited;
	int* parent;

	Graph(int v) {
		vertices = v;
		adj = new list<int>[v];
		visited = new int[v];
		parent = new int[v];
		for(int i = 0; i < v; i++) {
			visited[i] = 0;
			parent[i] = -1;
		}
	}

	void addEdge(int start, int end) {
		adj[start].push_back(end);
		adj[end].push_back(start);
	}

	bool isTree() {
		queue<int> q;
		q.push(0);
		while(!q.empty()) {
			while(!adj[q.front()].empty()) {
				if(visited[adj[q.front()].front()] == 1 and !parent[q.front()] == adj[q.front()].front()) {
					return false;
				}
				if(!visited[adj[q.front()].front()] == 1) {
					parent[adj[q.front()].front()] = q.front();
					q.push(adj[q.front()].front());
				}
				adj[q.front()].pop_front();
			}
			visited[q.front()] = 1;
			q.pop();
		}
		for(int i = 0; i < vertices; i++) {
			if(visited[i] == 0) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	int v = 5;
	Graph graph(v);
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 2);
	graph.addEdge(0, 3);
	graph.addEdge(3, 4);
	cout << graph.isTree();
	return 0;
}