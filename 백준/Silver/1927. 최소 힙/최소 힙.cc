#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector <int> result;

	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x > 0) {
			minHeap.push(x);
		}
		else {
			if (minHeap.empty()) {
				result.push_back(0);
			}
			else {
				result.push_back(minHeap.top());
				minHeap.pop();
			}
		}
	}
	for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
	return 0;
}