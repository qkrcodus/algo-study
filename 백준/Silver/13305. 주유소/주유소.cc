#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	//도시별 기름 값
	vector<int> cost(N);
	//도시 사이 거리 
	vector<int> distance(N - 1);

	for (int i = 0; i < N - 1; i++) {
		cin >> distance[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> cost[i];
	}

	long long min_cost = cost[0];
	long long total_cost = 0;

	for (int i = 0; i < N - 1; i++) {
		if (cost[i] < min_cost) {
			min_cost = cost[i];
		}
		total_cost += min_cost * distance[i];
	}

	cout << total_cost;
}