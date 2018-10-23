#include <iostream>
using namespace std;
// 0~10±îÁöÀÇ vertex
#define V 11

int graph[V][V];
bool visited[V];

void addEdge(int u, int v) {
	graph[u][v] = 1;
}

void DFS(int n) {
	visited[n] = true;
	printf("visit : %d\n", n);
	for (int i = 0; i < V; i++) {
		if (!visited[i] && graph[n][i]) {		
			DFS(i);
		}
	}
}

int main() {
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(0, 3);
	addEdge(1, 4);
	addEdge(2, 5);
	addEdge(2, 6);
	addEdge(4, 7);
	addEdge(5, 7);
	addEdge(7, 8);
	addEdge(8, 10);
	addEdge(7, 9);

	DFS(0);
}