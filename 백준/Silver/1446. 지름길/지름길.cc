//기억하며 풀기 알고리즘 DP
//[최적 부분 구조] 전체 문제를 부분 문제로 나눌 수 있다(각 위치까지의 최단 거리로 최단 거리를 계산)
//[중복되는 부분 문제] 이미 계산된 최단거리를 재활용
//이미 한 계산을 다시 하지 않으려면 각 위치까지 최단 거리를 저장하는 배열 dp 만든다.
//작은 문제부터 해결 => bottom up , 배열에 저장
//풀이
//전체적=>지름길 수 num, 길이 distance, 계산 값 저장할 배열
//지름길=> 시작점, 끝점, 거리

//흐름
//값을 갱신할 배열에선 디폴트로 지름길 없을때를 가정하고 길이만큼 더해준다
//지름길에서 시작점에 도착하면 1> 중복되는 끝점이 있따면

#include <iostream>
#include <vector>
#include <algorithm> //min 함수 사용

using namespace std;

int main() {
	const int INF = 10001;
	int num, distance;
	cin >> num >> distance;
	//각 위치에서 출발하는 지름길 정보 저장
	vector<int> start_vector;
	vector<int> end_vector;
	vector<int> length_vector;
	for (int i = 0; i < num; i++) {
		int start, end, length;
		cin >> start >> end >> length;
		if (end <= distance) {
			start_vector.push_back(start);
			end_vector.push_back(end);
			length_vector.push_back(length);
		}
	}
	//저장할 배열
	vector <int> dp(distance + 1, INF);
	dp[0] = 0;
	for (int i = 0; i <= distance; i++) {
		if (i > 0) {
			dp[i] = min(dp[i], dp[i - 1] + 1);
		}
		for (int j = 0; j < start_vector.size(); j++) {
			int start = start_vector[j];
			int end = end_vector[j];
			int length = length_vector[j];
			if (i == start) {
				dp[end] = min(dp[end], dp[start] + length);
			}
		}
	}
	cout << dp[distance] << endl;
	return 0;
}