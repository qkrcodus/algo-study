#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> timearray(N);
	for (int i = 0; i < N; i++) {
		cin >> timearray[i];
	}
	sort(timearray.begin(),timearray.end());
	int minresult=0;
	for (int i = 0; i < N; i++) {
		minresult += (N-i)*timearray[i];
	}
	cout << minresult;

}