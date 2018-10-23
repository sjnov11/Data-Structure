#include <iostream>
#include <vector>
using namespace std;

#define V 11

vector<int> adj_list[V];
bool visited[V];

void addEdge(int u, int v) {
	adj_list[u].push_back(v);
}

void DFS(int n) {
	visited[n] = true;
	printf("visit : %d\n", n);
	for (auto next : adj_list[n]) {
		if (!visited[next])
			DFS(next);
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