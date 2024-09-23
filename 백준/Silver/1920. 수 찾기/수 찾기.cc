#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

//return 0 return 1 이 함수 탈출이라 
void binary(vector <int>& a, vector <int>& b) {

	for (int i = 0; i < b.size(); i++) {
		int low = 0;
		int high = a.size() - 1;
		int target = b[i];
		bool found = false;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (target == a[mid]) { 
				cout << 1 << '\n'; 
				found = true;
				break; }
			if (target < a[mid]) {
				high = mid - 1;
			}
			else if (target > a[mid]) {
				low = mid + 1;
			}
		}
		if(!found) cout << 0 << '\n';
	}
}
	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N;
	vector <int> array_1(N);
	for (int i = 0; i < N; i++) {
		cin >> array_1[i];
	}
	cin >> M;
	vector <int> array_2(M);
	for (int i = 0; i < M; i++) {
		cin >> array_2[i];
	}
	//binary search 전 정렬
	sort(array_1.begin(), array_1.end());
	binary(array_1, array_2);

}
