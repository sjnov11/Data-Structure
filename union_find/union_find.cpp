#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
void init(int V) {
	parent.resize(V + 1);
	for (int i = 1; i <= V; i++) {
		parent[i] = -1;
	}
}

int find(int e) {
	if (parent[e] < 0) return e;
	return find(parent[e]);
}

void uni(int e1, int e2) {
	int r1 = find(e1);
	int r2 = find(e2);
	int rank_r1 = parent[r1] * (-1);
	int rank_r2 = parent[r2] * (-1);

	if (rank_r1 > rank_r2)
		parent[r2] = r1;
	else {
		parent[r1] = r2;
		if (rank_r1 == rank_r2)
			parent[r2]--;
	}
}