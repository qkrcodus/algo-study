#include <iostream>
#include <vector>
using namespace std; 

bool sol(int height, const vector<int>& location,int length) {
	if (location[0] - height > 0) return false;
	if (location.back() + height < length) return false;
	for (int i = 1; i < location.size(); i++) {
		if (location[i - 1] + height < location[i] - height) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//굴다리 길이
	int length;
	//가로등 개수
	int num;
	cin >> length >> num;
	//위치
	vector <int> location(num);
	for (int i = 0; i < num ; i++) {
		cin >> location[i];
	}
	//높이 범위를 이진탐색으로 점점 범위 좁혀가며 최솟값 찾기 
	int min = 1, max = length, result = 0;
	//범위 좁혀가는 과정에서 max 값을 줄여줄거라 
	while (min <= max) {
		int mid = (min + max) / 2;
		if (sol(mid, location, length)) {
			result=mid;
			max=mid-1;
		}
		else {
			min=mid+1;
		}
	}
	cout << result;

}