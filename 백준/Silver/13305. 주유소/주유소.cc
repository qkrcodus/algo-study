#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	int N;
	cin >> N;
	//도시별 기름 값
	int cost[100000];
	//도시 사이 거리 
	int distance[1000000];
	//저장할 곳
	int dp[1000000];
	distance[0] = 0;
	cost[0] = 0;
	for (int i = 0; i < N ; i++) {
		cin >> distance[i+1];
	}
	for (int i = 0; i < N; i++) {
		cin >> cost[i+1];
	}
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = cost[1] * distance[1];

	for (int i = 3; i < N + 1; i++) {

		int add = min(cost[i - 2], cost[i - 1]);
		dp[i] = add * distance[i - 1] + dp[i - 1];
	}
	cout << dp[N];
}