#include <iostream>
#include <vector>
using namespace std;

class Heap {
	vector<int> heap;
	
public:
	void insert(int data) {
		heap.push_back(data);
		int idx = heap.size() - 1;
		while (idx != 0 && heap[idx / 2 - ((idx % 2)^1)] > data) {
			heap[idx] = heap[idx / 2 - ((idx % 2) ^ 1)];
			idx = idx / 2 - ((idx % 2) ^ 1);
		}
		heap[idx] = data;
	}

	int pop() {
		int item = heap[0];
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		int idx = 0;

		while (true) {
			int left = idx * 2 + 1;
			int right = idx * 2 + 2;
			int min_idx = idx;

			if (left < heap.size() && heap[left] < heap[min_idx]) {
				min_idx = left;
			}
			if (right < heap.size() && heap[right] < heap[min_idx]) {
				min_idx = right;
			}

			if (min_idx == idx) {
				break;
			}
			int temp = heap[idx];
			heap[idx] = heap[min_idx];
			heap[min_idx] = temp;
			idx = min_idx;
		}	
		return item;
	}

	int size() {
		return heap.size();
	}
};


int main() {
	Heap h;

	for (int i = 50; i > 0; i--) {
		h.insert(i);
	}
	/*h.insert(1);
	h.insert(8);
	h.insert(3);
	h.insert(4);*/

	while (h.size() > 0) {
		cout << h.pop() << endl;
	}


}